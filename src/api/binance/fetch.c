#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "fetch.h"

typedef struct {
	char *data;
	size_t size;
} HttpResponse;

// adaptation of the WRITEFUNCTION example in the documentation
static size_t write_callback(void *data, size_t size, size_t nmemb, HttpResponse *resp) {
	size_t chunk = size * nmemb;
	char *ptr = realloc(resp->data, resp->size + chunk + 1);
	if (!ptr) return 0;
	memcpy(resp->data + resp->size, data, chunk);
	resp->size += chunk;
	resp->data[resp->size] = '\0';
	return chunk;
}

static char *http_get(const char *url) {
	HttpResponse resp = {
		.data = malloc(1),
		.size = 0
	};
	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resp);
	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	if (res != CURLE_OK) {
		free(resp.data);
		return NULL;
	}
	return resp.data;
}
