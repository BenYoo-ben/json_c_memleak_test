#include <stdio.h>

#include "json.h"


int main(void)
{
	struct json_object *json_generated_by_file = json_object_from_file("./sample_json/example_2.json");
	printf("json_file has value of\n%s\n",json_object_to_json_string_ext(json_generated_by_file,0));
	
	json_object_put(json_generated_by_file);

}
