/*
 *  author: byong.yoo
 *  description:
 *  testing how to use json_tokener_parse_ex correctly.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "json.h"


int main(void)
{
	int fd;
	fd = open("./sample_json/example_2.json",O_RDONLY);
		
	char buffer[8192];

	int read_chars_count = read(fd,buffer,8192);

	if(read_chars_count <= 0){
		fprintf(stderr,"system:read fail.\n");
	}

	struct json_tokener *jt = json_tokener_new();

	struct json_object *jobj = json_tokener_parse_ex(jt,buffer,read_chars_count);

/*
 *  json_tokener is not freed automatically in json_tokener_parse_ex.
 *  programmer should free json_tokener after calling json_tokener_parse_ex.
 */
	json_tokener_free(jt);


	printf("What's inside the json:\n%s\n",json_object_to_json_string(jobj));
	printf("Sign : %d\n",jt->err);

	json_object_put(jobj);

}
