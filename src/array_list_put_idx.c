/*
 * author : byong.yoo
 * description:
 * This code shows that use of json_object_array
 * and json_object_array_put_idx is 100% memory leak safe.
 *
 * json_object_array_put_idx, frees array element previously in the array
 * then replaces it with new element.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "json.h"

#define ARR_DUMMY_NUM 10



int main(void) {

	//root array object.
	struct json_object *json_arr = json_object_new_array();

	//last element in the array.
	struct json_object *ending_elem = json_object_new_string("last");

	//json_object elements to fill in spaces.
	struct json_object *arr_dummy_elements[ARR_DUMMY_NUM];



	int i=0;

	//adding elements..
	for(i=0;i<ARR_DUMMY_NUM;i++)
	{

		arr_dummy_elements[i] = json_object_new_int(i);
		json_object_array_add(json_arr,arr_dummy_elements[i]);

	}

	//add last element.
	json_object_array_add(json_arr, ending_elem);

	//print json
	printf("json_arr has value of\n%s\n",
			json_object_to_json_string_ext(json_arr, 0));

	//new json object to be switched
	struct json_object *arr2 = json_object_new_string("NEW");


	//switch with fifth element.
	printf("\njson_object_array_put_idx(5->NEW)\n\n");
	json_object_array_put_idx(json_arr, 5, arr2);

	printf("Now, json_arr has value of\n%s\n",
			json_object_to_json_string_ext(json_arr, 0));

	json_object_put(json_arr);


}
