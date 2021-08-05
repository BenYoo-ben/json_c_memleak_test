#include <stdio.h>
#include <json.h>
 
//Code is from:
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=yababies&logNo=220029067066

int main(int argc, char **argv)
{
    json_object *obj, *dataobj;

    obj = json_object_new_object();
    dataobj = json_object_new_object();

    json_object_object_add(dataobj,"test1", json_object_new_int(1));
    json_object_object_add(obj,"test2",dataobj);

    printf("myobj = %s\n",json_object_to_json_string(obj));

    return(0);
}
