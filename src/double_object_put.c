/*
 * author: byong.yoo
 * description:
 * Testing: call object_put on child object then call object_put on parent object.
 *
 */

#include <stdio.h>

#include "json.h"

int main(void){
	
	json_object *INTEGER = json_object_new_int(2021);
	json_object *STRING = json_object_new_string("OBJ1");
	json_object *OBJECT = json_object_new_object();

	json_object *root = json_object_new_object();
	
	json_object_set_int(INTEGER,2021);
	json_object_set_string(STRING,"Hello World");
	json_object_object_add(OBJECT,"OBJ2",json_object_new_object());


	json_object_object_add(root,"INT",INTEGER);
	json_object_object_add(root,"STR",STRING);
	json_object_object_add(root,"OBJ",OBJECT);

	printf("json structure : \n %s \n",json_object_to_json_string(root));

	printf("\n calling object_put on OBJ . \n");
	json_object_put(OBJECT);

	/* double object_put_on OBJECT --> double free
	 * unexpected behaviour
	 */
	printf("\n calling object_put on root . \n ");
	json_object_put(root);


}
