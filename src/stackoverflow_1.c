/*
 * From: https://stackoverflow.com/questions/8746155/memory-leak-using-json-c
 */

/* if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */

//#define FIX

#include <stdio.h>
#include "json.h"



int main(void) {

	struct json_object *new_obj = NULL;
	new_obj = json_object_from_file("./sample_json/example_2.json");

#ifdef FIX
	struct json_object *root_object = NULL;
	root_object = new_obj;
#endif

	printf("structure is \n%s\n", json_object_to_json_string(new_obj));

	/*
	 * @LEAKAGE #1, previous reference to json_object root is lost.
	 * new_obj is NOT pointing to json_object's root.
	 */
	new_obj = json_object_object_get(new_obj, "quiz");


	if (NULL == new_obj) {
		printf("\nquiz not found in JSON");
		return 0;
	}

	/*
	 * @LEAKAGE #2, losing reference to root + object before(Line 30)
	 */
	new_obj = json_object_object_get(new_obj, "maths"); // [stackvoerflow] I m re-using new_obj, without free it?
	if (NULL == new_obj) {
		printf("\nsport not found in JSON");
		return 0;
	}
	// [stackoverflow]
	// DO I need to clean new_obj, if yes then how ??

#ifdef FIX
	json_object_put(root_object);
#else
	/*
	 * @LEAKAGE #3, this call only free, json_object acquired from Line 41.
	 */
	json_object_put(new_obj);
#endif
}
