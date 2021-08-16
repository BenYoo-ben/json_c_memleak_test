/*
 * from: unknown;
 * description:
 *  testing sample usage of json-c.
 */

#include <stdio.h>
#include "json.h"

#define set_json_obj(base, key, val) json_object_object_add(base, key, val);
#define set_json_str(base, key, val) json_object_object_add(base, key, json_object_new_string(val))

int MacFilter(struct json_object **jsobj)
{
    struct json_object *outTable = NULL;
    struct json_object *objVal = NULL;
    struct json_object *arrayobj = NULL;
    struct json_object *tmp = NULL;
	struct json_object_iter iter;

    /* Create json object */
    tmp = json_object_new_object();
    arrayobj = json_object_new_array();
    /* Get mac filter from cms data model */
    set_json_str(tmp, "MAC", "0");

    json_object_object_foreachC(tmp, iter)
    {
		objVal = json_object_new_object();
		set_json_str(objVal, "mac", iter.key);
		json_object_array_add(arrayobj, objVal);
    }

    outTable = json_object_new_object();
    set_json_obj(outTable, "table", arrayobj);

    *jsobj = json_object_new_object();
    json_object_object_add(*jsobj, "out-body", outTable);

    if (tmp)
        json_object_put(tmp);

    return 1;
}

int main(void){

	struct json_object *jso;

	MacFilter(&jso);

	printf("inside jso = \n%s\n",json_object_to_json_string(jso));

	printf("\n calling json_object_put(jso)\n");
	json_object_put(jso);

	return 0;

}
