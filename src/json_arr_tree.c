#include <stdio.h>
#include <json.h>

#define ARRAY_TREE_DEPTH 1000

/*
 * This program intends to make a json structure that has arrays inside arrays inside arrays ...
 */

int main(void)
{


	struct json_object *array_top = json_object_new_array();
	struct json_object *prev_array = array_top;

	int i=0;

	for(i=0;i<ARRAY_TREE_DEPTH;i++){

		struct json_object *tmp_arr =json_object_new_array();
		struct json_object *tmp_int = json_object_new_int(323232);
		struct json_object *tmp_string = json_object_new_string("TEMPORARY STRING");

		json_object_array_add(prev_array,tmp_int);
		json_object_array_add(prev_array, tmp_string);
		json_object_array_add(prev_array,tmp_arr);

		prev_array = tmp_arr;


	}
	
	json_object_put(array_top);
	
}
