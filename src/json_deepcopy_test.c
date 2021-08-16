/*
 * author: byong.yoo
 * description:
 * json_object_deep_copy, makes exact copy of original json_object including its child objects.
 * it allocated memory separately too, so copy is not reference to original.
 */
#include <stdio.h>
#include "json.h"

//#define FIX

int main(void){
	
	struct json_object *orig_root = json_object_new_object();
	
	json_object_object_add(orig_root, "str",json_object_new_string("First child"));
	json_object_object_add(orig_root, "int",json_object_new_int(32));


	printf("Original : \n%s\n\n", json_object_to_json_string(orig_root));


	struct json_object *copy_root = NULL;
	/*
	 * ! dst field of json_object_deep_copy must be set to NULL. !
	 */

	int result = json_object_deep_copy(orig_root, &copy_root, json_c_shallow_copy_default);
	printf("result = %d\n",result);
	if(copy_root!=NULL){
		printf("Copied :\n%s\n\n",json_object_to_json_string(copy_root));
	}
	
	printf("json_object_put(Original)\n\n");
	json_object_put(orig_root);


	printf("Copied :\n%s\n\n",json_object_to_json_string(copy_root));

	//copy is not reference, so object_put must be called. If not = memory leak.
#ifdef FIX
	json_object_put(copy_root);
#endif
}
