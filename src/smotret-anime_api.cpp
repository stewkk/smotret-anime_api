
#include "smotret-anime_api.h"

SmotretAnime::SmotretAnime() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

SmotretAnime::~SmotretAnime() {
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

static size_t WriteCallbackToString(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string SmotretAnime::api_series_get_id_by_shiki_id(long long shiki_id) {
    std::string ans;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ans);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallbackToString);
    curl_easy_setopt(curl, CURLOPT_URL, (smotret_anime_api_domain + "api/series/?" + 
                "myAnimeListId=" + std::to_string(shiki_id) + "&fields=id").c_str());
    curl_easy_perform(curl);
    return ans;
}

std::string SmotretAnime::api_translations_get_by_seriesId(long long seriesId) {
    std::string ans;
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ans);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallbackToString);
    curl_easy_setopt(curl, CURLOPT_URL, (smotret_anime_api_domain + "api/translations/?" + 
                "seriesId=" + std::to_string(seriesId) + 
                "&limit=10000&fields=id,episode,authorsSummary,type,embedUrl").c_str());
    curl_easy_perform(curl);
    return ans;
}

void SmotretAnime::download_sub_by_translation_id(long long id, const std::string& download_path,
        const std::string& filename) {
    FILE* subs_file = fopen((download_path + filename).c_str(), "wb");
    if (subs_file) {
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, subs_file);
        curl_easy_setopt(curl, CURLOPT_URL, (smotret_anime_subs_domain + "episodeTranslations/" + 
                    std::to_string(id) + ".ass").c_str());
        curl_easy_perform(curl);
        fclose(subs_file);
    }
}

