/*
 * author: byongjin.yoo
 * description:
 * must be careful when using json objects in function.
 * programmer must be aware that reference to allocated memory can be lost
 * when json-c is used in functions.
 *
 * if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */

//#define FIX

#include <stdio.h>

#include "json.h"


int ReadFromFileGetSport(char* filename);

int ReadFromFileGetSport(char *filename)
{
	struct json_object *tmp;

	tmp = json_object_from_file(filename);

	struct json_object *return_me;

	return_me = json_object_object_get(
			json_object_object_get(tmp,"quiz"),
			"sport");

	/*
	 * @LEAKAGE #1: if quiz->sport is not found in the above statement,
	 * tmp is not freed and can not be in the future since there's no reference to it.
	 *
	 */

#ifndef FIX
	if(!return_me)
	{
		printf("no sport found, return 0. WITH NO object_put \n");
		return 0;
	}
#else
	if(!return_me)
	{
		printf("no sport found, return 0. WITH object_put\n");
		json_object_put(tmp);

		return 0;
	}
#endif
	/*
	 * Do something with return_me...
	 */
	printf("return me = \n%s\n",json_object_to_json_string(return_me));

	json_object_put(tmp);

	return 1;


}


int main(void)
{
	
	ReadFromFileGetSport("./sample_json/example_2.json");
	ReadFromFileGetSport("./sample_json/adobe_server_ex.json");



}
