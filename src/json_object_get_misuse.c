/*
 * author: byongjin.yoo
 * description:
 * json_object_get is to get reference of a json_object.
 * but it also increments the _ref_count field of the json_object.
 * when json_object_put is called, first it decrements the _ref_count of the object passed
 * and when the _ref_count is not 0, the memory allocated won't be freed.
 *
 * if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */

//#define FIX

#include <stdio.h>
#include "json.h"


int main(void)
{
	json_object *json_array_1 = json_object_new_array();

	json_object *json_int = json_object_new_int64(12345);

	json_object *json_string = json_object_new_string("Hello World");

	 json_object *json_obj = json_object_new_object();


	json_object_array_add(json_array_1,json_int);
	json_object_array_add(json_array_1,json_string);
	json_object_array_add(json_array_1,json_obj);



	json_object *json_array_1_copy = json_object_get(json_array_1);
	printf("calling json_object_get...(ref_count +1)\n");


	json_object_put(json_array_1);
	printf("json_object_put(json_array_1) called...\n");



	printf("(json_array_1) is not freed, ref_count >1\n");
#ifdef FIX
	json_object_put(json_array_1_copy);
	printf(("json_array_1_copy) is freed, ref_count =0\n"));
#endif

}
