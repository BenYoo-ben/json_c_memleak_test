/*
 * author: byong.yoo
 * description:
 * simple example testing memory leakage of json_tokener_parse.
 */

#include <stdio.h>
#include "json.h"


int main(void){
	char *json_str = "{\"name\":\"John\", \"age\":30, \"car\":null}";
	

	struct json_object *jobj = json_tokener_parse(json_str);

	printf("inside:\n%s\n",json_object_to_json_string(jobj));
	json_object_put(jobj);
}


