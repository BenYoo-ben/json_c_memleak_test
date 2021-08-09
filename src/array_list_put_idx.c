#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "json.h"

#define ARR_DUMMY 10

int main(void) {

	struct json_object *json_arr = json_object_new_array();

	struct json_object *arr1 = json_object_new_string("arr1");
	struct json_object *arr2 = json_object_new_string("NEW OBJECT");

	struct json_object *arr_dummy[ARR_DUMMY+1];



	int i=0;
	for(i=0;i<ARR_DUMMY;i++)
	{

		arr_dummy[i] = json_object_new_int(i);
		json_object_array_add(json_arr,arr_dummy[i]);

	}

	json_object_array_add(json_arr, arr1);
	printf("json_arr has value of\n%s\n",
			json_object_to_json_string_ext(json_arr, 0));

	printf("after json_object_array_put_idx\n");
	json_object_array_put_idx(json_arr, 5, arr2);

	printf("json_arr has value of\n%s\n",
			json_object_to_json_string_ext(json_arr, 0));

	json_object_put(json_arr);
}
