/*
 * From: https://chipmaker.tistory.com/entry/jsonc-simple-generator-json-ojbect
 */

/* if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */

//#define FIX


#include <stdio.h>
#include <string.h>
#include "json.h"

// reference => https://linuxprograms.wordpress.com/2010/08/19/json_object_new_object/



int main()
{

    system("free");

    // create new json ojbect
    json_object *jobj = json_object_new_object();

    // create a json string
    json_object *jstring = json_object_new_string("heesoon.kim");
    // create a json integer
    json_object *jint1 = json_object_new_int(41);
    // create a json double
    json_object *jdouble = json_object_new_double(172.20);
    // create a json boolean
    json_object *jboolean = json_object_new_boolean(0);

    // create a json array
    json_object *jarray = json_object_new_array();
    // create a json data for array
    json_object *jstring1 = json_object_new_string("c");
    // create a json data for array
    json_object *jstring2 = json_object_new_string("c++");
    // create a json data for array
    json_object *jstring3 = json_object_new_string("javascript");
    // create a json data for array
    json_object *jstring4 = json_object_new_string("phython");

    // add data to array
    json_object_array_add(jarray, jstring1);
    json_object_array_add(jarray, jstring2);
    json_object_array_add(jarray, jstring3);
    //json_object_array_add(jarray, jstring4);
    json_object_array_put_idx(jarray, 4, jstring4);

    // create a json object to be included above outer object
    json_object *jinner_object = json_object_new_object();
    // create a json integer
    json_object *jint2 = json_object_new_int(10);

    // add data to inner object
    json_object_object_add(jinner_object, "name", jstring);
    json_object_object_add(jinner_object, "Number of Posts", jint2);

    // add data to outer object
    json_object_object_add(jobj, "name",            jstring);
    json_object_object_add(jobj, "student",         jboolean);
    json_object_object_add(jobj, "age",             jint1);
    json_object_object_add(jobj, "height",          jdouble);
    json_object_object_add(jobj, "interestings",    jarray);
    json_object_object_add(jobj, "author-details",  jinner_object);

    printf("The json ojbect created: %s\n", json_object_to_json_string(jobj));

    system("free");

    // delete all memory allocated in heap region
    json_object_put(jstring);
    json_object_put(jint1);
    json_object_put(jdouble);
    json_object_put(jboolean);

    // delete all data in array
    for(int i = 0; i < json_object_array_length(jarray); i++)
    {
        json_object_array_del_idx(jarray, 0, 1);
    }

    json_object_put(jarray);
    json_object_put(jinner_object);
    json_object_put(jobj);

    system("free");

    return 0;
}
