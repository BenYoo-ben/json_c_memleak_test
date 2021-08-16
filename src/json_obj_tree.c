/*
 * author: byong.yoo
 * description:
 * this program shows that a very very deep structured json-c object can be freed with
 * single call of json_object_put on the root object.
 */
#include <stdio.h>
#include "json.h"

#define TREE_DEPTH 5000


int main(void) {

	struct json_object *object_top = json_object_new_object();
	struct json_object *prev_object = object_top;
	int i = 0;

	for (i = 0; i < TREE_DEPTH; i++) {

		struct json_object *tmp_object = json_object_new_object();
		struct json_object *tmp_int = json_object_new_int(323232);
		struct json_object *tmp_string = json_object_new_string(
				"TEMPORARY STRING");

		json_object_object_add(prev_object, "INT", tmp_int);
		json_object_object_add(prev_object, "STRING", tmp_string);
		json_object_object_add(prev_object, "OBJECT", tmp_object);


		prev_object = tmp_object;

	}

	printf("json_structure is : \n%s\n\n",json_object_to_json_string_ext(object_top,0));


	json_object_put(object_top);
	printf("json_object_put on tree's root.\n");

}
