#ifndef PARSER_JSON_PARSER
#define PARSER_JSON_PARSER

#include "Tokenizer.h"
#include "JSON.h"
#include <memory>

class JSONParser
{
private:
    std::fstream file;
    std::shared_ptr<JSON_Node> root;
    std::unique_ptr<JSON_Node> current;
    Tokenizer tokenizer;

public:
    JSONParser(const std::string filename): tokenizer(filename){}
    void parse();

    std::shared_ptr<JSON_Node> parseObject();
    std::shared_ptr<JSON_Node> parseString();
    std::shared_ptr<JSON_Node> parseNumber();
    std::shared_ptr<JSON_Node> parseList();
    std::shared_ptr<JSON_Node> parseBoolean();
    std::shared_ptr<JSON_Node> parseNull();
};



#endif //PARSER_JSON_PARSER