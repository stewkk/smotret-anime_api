
#include <curl/curl.h>
#include <string>
#include <iostream>

class SmotretAnime {
public:
    SmotretAnime();
    ~SmotretAnime();
    std::string api_series_get_id_by_shiki_id(long long shiki_id);
    std::string api_translations_get_by_seriesId(long long seriesId);
    void download_sub_by_translation_id(long long id, const std::string& download_path,
            const std::string& filename);
private:
    CURL* curl;
    const std::string smotret_anime_api_domain = "https://smotret-anime.online/";
    const std::string smotret_anime_subs_domain = "https://sub.smotret-anime.online/";
};

