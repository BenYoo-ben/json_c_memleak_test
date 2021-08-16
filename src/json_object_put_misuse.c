/*
 * From: stackoverflow.com
 * description:
 * An example I found from stackoverflow.com.
 * json_object_put is used wrong considering the architecture of json-c lib.
 *
 * if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */
//#define FIX

#include <stdio.h>
#include <stdlib.h>
#include "json.h"


struct json_object * parse_object;
void init() {

    char buffer_file[] = "{ \"object\": {\"array1\": [1, 2, 3], \"array2\": [4, 5, 6] } }";
    parse_object = json_tokener_parse(buffer_file);
    printf("inside : %s\n",json_object_to_json_string(parse_object));

}
void test_json() {
    struct json_object * obj1, * arr1;
    json_object_object_get_ex(parse_object, "object", &obj1);
    json_object_object_get_ex(obj1, "array1", &arr1);
    int size = json_object_array_length(arr1);
    printf("size = %d \n", size);
    /*
     * @ERROR #1: object_get_ex, does not increment json_object->_ref_count.
     * 			  So following json_object_put(obj1) actually does free memory allocated for obj1
     *
     * 			  test_json() function is called multiple times in main().
     * 			  Accessing previously freed memory = undefined behavior.
     */
#ifndef FIX
    json_object_put(obj1);
#endif
}

int main(int argc, char const *argv[]) {
    int j = 0;
    int max = 100;
    init();
    while(++j < max) {
       test_json();
    }
#ifdef FIX
json_object_put(parse_object);
#endif
    return 0;
}
