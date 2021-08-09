#include <stdio.h>
#include "json.h"

#define TREE_DEPTH 10

/*
 * This program intends to make a json structure that has arrays inside arrays inside arrays ...
 */

int main(void) {

	struct json_object *object_top = json_object_new_object();
	struct json_object *prev_object = object_top;
	struct json_object *obj_obj_get_ex = NULL;
	int i = 0;

	for (i = 0; i < TREE_DEPTH; i++) {

		struct json_object *tmp_object = json_object_new_object();
		struct json_object *tmp_int = json_object_new_int(323232);
		struct json_object *tmp_string = json_object_new_string(
				"TEMPORARY STRING");

		json_object_object_add(prev_object, "INT", tmp_int);
		json_object_object_add(prev_object, "STRING", tmp_string);
		json_object_object_add(prev_object, "OBJECT", tmp_object);

		if (i == 0) {
			if (0
					!= json_object_object_get_ex(prev_object, "OBJECT",
							&obj_obj_get_ex)) {
				printf("Copied.\n");
			}

		}
		prev_object = tmp_object;

	}

//	printf("%s\n",json_object_to_json_string_ext(array_top,0));

	printf("copied pointer by json_object_object_get_ex points to : %p\n",obj_obj_get_ex);
	printf("which has value of \n%s\n\n",json_object_to_json_string_ext(obj_obj_get_ex,0));

	json_object_object_add(obj_obj_get_ex,"ADDING",json_object_new_object());

	json_object_put(object_top);
	printf("json_object_put on tree's root.\n");

/*	printf("copied pointer by json_object_object_get_ex points to : %p\n",obj_obj_get_ex);
	printf("which has value of \n%s\n\n",json_object_to_json_string_ext(obj_obj_get_ex,0));
*/

	//json_object_object_add(obj_obj_get_ex,"ADDING",json_object_new_object());



}
