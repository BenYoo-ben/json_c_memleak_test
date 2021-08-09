#include <stdio.h>

#include "json.h"

int main(void){
	
	json_object *INTEGER = json_object_new_int(2021);
	json_object *STRING = json_object_new_string("Hello World");
	json_object *OBJECT = json_object_new_object();

	
	json_object_set_int(INTEGER,2021);
	json_object_set_string(STRING,"Hello World");
	json_object_object_add(OBJECT,"New Obj",json_object_new_object());


	json_object_put(INTEGER);
	json_object_put(INTEGER);

	json_object_put(STRING);
	json_object_put(STRING);

	json_object_put(OBJECT);
	json_object_put(OBJECT);
}
