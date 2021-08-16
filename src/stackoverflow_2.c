/*
 * From: https://stackoverflow.com/questions/37338425/memory-leak-in-json-c
 * description:
 * Q:
 * I tried to freed the memory with "json_object_put(result)" 
 * but it dosnet seems to free everything. Can somebody help?

 */
#include <stdio.h>
#include "json.h"
#define mark_one 6
#define mark_two 18
#define mark_three 36

json_object* json_devicedata() {

	json_object *jobj_device_data = json_object_new_object();
	json_object *jobj_array_typen = json_object_new_array();
	json_object *jobj_array_werte = json_object_new_array();

	json_object_array_add(jobj_array_typen, json_object_new_int(101)); //Key
	json_object_array_add(jobj_array_werte, json_object_new_int(2));

	json_object_array_add(jobj_array_typen, json_object_new_int(102)); //Timestamp
	json_object_array_add(jobj_array_werte,
			json_object_new_int(12));

	json_object_array_add(jobj_array_typen, json_object_new_int(103));

	json_object_array_add(jobj_array_typen, json_object_new_int(994));

	json_object_object_add(jobj_device_data, "type", jobj_array_typen);
	json_object_object_add(jobj_device_data, "value", jobj_array_werte);

	return jobj_device_data;
}

void json_writer() {
	json_object *tiny = json_object_new_object();
	json_object *result = json_object_new_object();

	json_object *minimalistic = json_object_new_array();

	json_object *shorty;
	for (unsigned short counterStrang = 0; counterStrang < mark_one;
			counterStrang++) {
		for (unsigned short counterModul = 0; counterModul < mark_two;
				counterModul++) {
			for (unsigned short counterZelle = 0; counterZelle < mark_three;
					counterZelle++) {
				shorty = json_devicedata();
				json_object_array_add(minimalistic, shorty);
			}
		}
	}

	json_object_object_add(tiny, "value", minimalistic);

	json_object *mini = json_object_new_array();
	json_object_array_add(mini, tiny);
	json_object_object_add(result, "value", mini);

	/*
	 * result = root of all the objects.
	 * no memory leak happens
	 */
	printf("%s", json_object_to_json_string(result));
	printf(",");

	json_object_put(result);
}

int main(void){


	json_writer();

}


