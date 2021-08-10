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
    json_object_put(obj1);  
}

int main(int argc, char const *argv[]) {
    int j = 0;
    int max = 100;
    init();
    while(++j < max) {
       test_json();
    }
   // json_object_put(parse_object);
    return 0;
}