#include <stdio.h>
#include "json.h"

#define set_json_str(base, key, val) json_object_object_add(base, key, json_object_new_string(val))
#define set_json_int(base, key, val) json_object_object_add(base, key, json_object_new_int(val))
#define set_json_obj(base, key, val) json_object_object_add(base, key, val);

int api_upgrade_remote_get(char *path, FILE *stream)
{
   struct json_object *val = NULL;
   struct json_object *outBody = NULL;

   val = json_object_new_object();

   if (1)
   {
      set_json_str(val, "protocol", "remoteUpgradeObj->protocol");
      set_json_str(val, "url", "remoteUpgradeObj->URL ");
      set_json_str(val, "username", "remoteUpgradeObj->username");
      set_json_str(val, "password", "remoteUpgradeObj->password");
      set_json_int(val, "port", "remoteUpgradeObj->port");
      set_json_int(val, "meta_last", "remoteUpgradeObj->metaTimestamp");
      set_json_str(val, "meta_version", "remoteUpgradeObj->metaVersion");

      //cmsObj_free((void **) &remoteUpgradeObj);
   }
   else
   {
      set_json_str(val, "protocol", "");
      set_json_str(val, "url", "");
      set_json_str(val, "username", "");
      set_json_str(val, "password", "");
      set_json_int(val, "port", 0);
      set_json_int(val, "meta_last", 0);
      set_json_str(val, "meta_version", "");
   }

/* @Shin, 20210312. Account Access Control */
#ifdef SUPPORT_KAON_WEBUI_MULTI_USER
   set_json_int(val, "account", gAuthFlag);
#endif

   outBody = json_object_new_object();
   set_json_obj(outBody, "upgrade_server", val);

   outBody = json_object_new_object();
   set_json_obj(outBody, "upgrade_server", val);

  /* api_send_headers(stream, 200, "Ok", NULL, "application/json",
                    (char *)json_object_to_json_string_ext(outBody, JSON_C_TO_STRING_PRETTY));
*/
   if (outBody)
      json_object_put(outBody);

   return 0;
}

int main(void)
{
	api_upgrade_remote_get("",NULL);

}
