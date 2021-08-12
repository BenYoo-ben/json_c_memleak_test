#include <stdio.h>
#include <string.h>
#include "json.h"

#define set_json_str(base, key, val) json_object_object_add(base, key, json_object_new_string(val))
#define set_json_int(base, key, val) json_object_object_add(base, key, json_object_new_int(val))
#define set_json_obj(base, key, val) json_object_object_add(base, key, val);

#define WEB_STS_OK 1


int api_device_info_get(char *path, char *body, int blen, FILE *stream,
		int readonly) {
	struct json_object *val = NULL;
	struct json_object *outBody = NULL;
	char ipv4AddrStrBuf[11] = { 0 };
	char ipv4SubnetStrBuf[11] = { 0 };
	char tmpStr[32] = { 0, };


	val = json_object_new_object();

	/*if (gddbGetInt("/airfores/singlesignon") == 1)
		set_json_str(val, "mode", "master");
	else*/
		set_json_str(val, "mode", "slave");

	/*qdmIpIntf_getIpv4AddrAndSubnetByNameLocked_dev2("br0", ipv4AddrStrBuf,
			ipv4SubnetStrBuf);*/
	set_json_str(val, "ip", ipv4AddrStrBuf);
	strcpy(tmpStr, "/sys/friendlyname");
	set_json_str(val, "name", tmpStr);

	strcpy(tmpStr, "/lan/wireless5:1/wirelessbssid");
	set_json_str(val, "bssid", tmpStr);

	strcpy(tmpStr, "/sys/modelname");
	set_json_str(val, "model", tmpStr);
	strcpy(tmpStr, "/sys/modelnumber");
	set_json_str(val, "serial", tmpStr);
	strcpy(tmpStr, "/fwupgradeinfo/currfwversion");
	set_json_str(val, "software_version", tmpStr);
	strcpy(tmpStr, "/fwupgradeinfo/devicemac");
	set_json_str(val, "mac", tmpStr);

	outBody = json_object_new_object();
	set_json_obj(outBody, "info", val);

	/*api_send_headers(stream, 200, "Ok", NULL, "application/json",
	 (char *)json_object_to_json_string_ext(outBody, JSON_C_TO_STRING_PRETTY));
	 */

	if (outBody)
		json_object_put(outBody);
	return WEB_STS_OK;
}

int main(void){

	api_device_info_get("", "", 1, NULL, 1);

}
