/*
 * From: https://chipmaker.tistory.com/entry/cjson-simple-parsing-example
 *
 * if FIX is defined = no memory leak
 * undefine it to see where memory leakage happens
 */

//#define FIX

#include <stdio.h>
#include <string.h>
#include "json.h"
 
int main()
{
    enum json_type type;
     
    char *string = "{\
            \"name\"            : \"heesoon.kim\",\
            \"student\"         : false,\
            \"age\"             : 41,\
            \"heigh\"           : 172.2,\
            \"interestings\"    : [ \"c\" , \"c++\", \"javascript\", \"phython\" ],\
            \"author-details\"  : { \"name\" : \"heesoon.kim\", \"Number of Posts\" : 10 }\
      }";
 
    // string type is converted to json object type
    json_object *jobj = json_tokener_parse(string);
 
    // parse each json object paired with key and val
    json_object_object_foreach(jobj, key, val)
    {
        // get current json object type
        type = json_object_get_type(val);
        printf("type = ");
 
        switch(type)
        {
            case json_type_null:
                printf("json_type_null\n");
                break;
            case json_type_boolean:
                printf("json_type_boolean\n");
                printf("key = %-15s : value = %s\n", key, json_object_get_boolean(val) ? "true" : "false");
                break;
            case json_type_double:
                printf("json_type_double\n");
                printf("key = %-15s : value = %lf\n", key, json_object_get_double(val));
                break;
            case json_type_int:
                printf("json_type_int\n");
                printf("key = %-15s : value = %d\n", key, json_object_get_int(val));
                break;
            case json_type_object:
                printf("json_type_object\n");
                printf("key = %-15s : value = \n", key);
                break;
            case json_type_array:
                printf("json_type_array\n");
                printf("key = %-15s : value = \n", key);
                break;
            case json_type_string:
                printf("json_type_string\n");
                printf("key = %-15s : value = %s\n", key, json_object_get_string(val));
                break;
        }
    }
#ifdef FIX
    json_object_put(jobj);
#endif
    printf("\n");
 
    return 0;
}

