#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <curl/curl.h>

size_t writer(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size* nmemb);
    return size*nmemb;
}

std::map<std::string, std::string> curl_GET(std::string url) {
    CURL *curl = NULL;
    CURLcode res;
    std::string user_agent = "TEST_USER_AGENT";
    std::map<std::string, std::string> response;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

#ifdef SKIP_PEER_VERIFICATOIN
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif
#ifdef SKIP_HOSTNAME_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

        std::string response_string;
        std::string response_header;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response_header);

        res = curl_easy_perform(curl);
        response = {{"response_string", response_string},
                    {"response_header", response_header}
        };
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed." << std::endl
                      << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return response;
}

int main(int argc, char** argv) {
    std::map<std::string, std::string> test = curl_GET("https://heise.de");
    std::cout << test["response_string"];
    return 0;
}
