#include <stdio.h>
#include "json.h"
/*
 * this prgoram is to show how ref_count is incremented when json_object_get is called.
 *
 *
 */

int main(void)
{
	json_object *json_array_1 = json_object_new_array();

	json_object *json_int = json_object_new_int64(369369);

	json_object *json_string = json_object_new_string("Hello World");

	 json_object *json_obj = json_object_new_object();


	json_object_array_add(json_array_1,json_int);
	json_object_array_add(json_array_1,json_string);
	json_object_array_add(json_array_1,json_obj);


	json_object *json_array_1_copy = json_object_get(json_array_1);
	printf("calling json_object_get...(ref_count +1)\n");

	//printf("json_array_1->ref_count = %d\n",json_array_1->_ref_count);

	json_object_put(json_array_1);
	printf("json_object_put(json_array_1) called...\n");

	printf("(json_array_1) is not freed, ref_count >1");
}
