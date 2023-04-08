//
// Created by teena on 29.03.2023.
//

#ifndef SEARCH_ENGINE_CONVERTERJSON_H
#define SEARCH_ENGINE_CONVERTERJSON_H
#include <string>
#include <vector>
#include "../nlohmann_json/include/nlohmann/json.hpp"

class ConverterJSON
{
private:
    struct
    {
        struct
        {
            std::string name;
            std::string version;
            int maxResponses = 0;
        } config;
        std::vector<std::string> filePaths;
    } configJSON;
    std::vector<std::string> requestsJSON;
    void readConfigJSON();
    void readRequestsJSON();
public:
    ConverterJSON();
    ~ConverterJSON() = default;
    std::vector<std::string> GetTextDocuments();
    std::string GetProgramName() const;
    std::string GetProgramVersion() const;
    int GetResponsesLimit() const;
    std::vector<std::string> GetRequests();
    void putAnswers(const std::vector<std::vector<std::pair<int, float>>> &answers);
};


#endif //SEARCH_ENGINE_CONVERTERJSON_H
