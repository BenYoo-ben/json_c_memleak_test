#include <stdio.h>

#include <json.h>


int main(void)
{
	struct json_object *jso = json_object_new_object();

#ifdef _json_object_private_h_

printf("DEFINED.\n");

#endif
/*
	if(!jso)
		printf("json null\n");
	
	if(!(jso->c_object))
		printf("lh table null\n");

	if(!(jso->c_object->table))
		printf("lh table->table null\n");

*/
	

//	json_object_put(jso);

}
