#ifndef PARSERJSON_PARSER_H
#define PARSERJSON_PARSER_H

#include "Tokenizer.h"
#include <memory>

class JSONParser {
private:
    std::fstream file;
    std::shared_ptr<JSON::JSONNode> root;
    std::unique_ptr<JSON::JSONNode> current;
    Tokenizer tokenizer;
public:
    JSONParser(const std::string filename): tokenizer(filename) {}
    void parse();
    std::shared_ptr<JSON::JSONNode> parseObject();
    std::shared_ptr<JSON::JSONNode> parseString();
    std::shared_ptr<JSON::JSONNode> parseNumber();
    std::shared_ptr<JSON::JSONNode> parseList();
    std::shared_ptr<JSON::JSONNode> parseBoolean();
    std::shared_ptr<JSON::JSONNode> parseNull();
};

#endif //PARSERJSON_PARSER_H