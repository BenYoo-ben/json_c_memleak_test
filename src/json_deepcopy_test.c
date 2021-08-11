#include <stdio.h>
#include "json.h"


int main(void){
	
	struct json_object *orig_root = json_object_new_object();
	
	json_object_object_add(orig_root, "str",json_object_new_string("First child"));
	json_object_object_add(orig_root, "int",json_object_new_int(32));


	printf("Original : \n%s\n", json_object_to_json_string(orig_root));


	struct json_object *copy_root = NULL;
	//dst field of json_object_deep_copy must be set to NULL.

	printf("h");
	int result = json_object_deep_copy(orig_root, &copy_root, json_c_shallow_copy_default);
	printf("result = %d\n",result);
	if(copy_root!=NULL){
		printf("Copied :\n%s\n",json_object_to_json_string(copy_root));
	}
	
	printf("json_object_put(Original)\n");

	printf("Copied :\n%s\n",json_object_to_json_string(copy_root));

	
}
