#ifndef PARSERJSON_PARSER_H
#define PARSERJSON_PARSER_H

#include "Tokenizer.h"
#include <memory>
#include <map>
#include <vector>
#include <list>
class JSON_Node;

using JSONObject = std::map<std::string,std::shared_ptr<JSON_Node>>;
using JSONList = std::vector<std::shared_ptr<JSON_Node>>;
class JSONNode {
    enum class Type {OBJECT,LIST,STRING,NUMBER,BOOLEAN,NULL_TYPE};
    union Values {
        JSONObject* object;
        JSONList* list;
        std::string* s;
        float fValue;
        bool bValue;
    } value ;
    Type type;
    auto returnObject() {
        if(type==Type::OBJECT) {
            return *value.object;
        }
        throw std::logic_error("wrong return");
    }
    auto returnList() {
        if(type==Type::LIST) {
            return *value.list;
        }
        throw std::logic_error("wrong return");
    }

    auto returnString() {
        if(type==Type::STRING) {
            return *value.list;
        }
        throw std::logic_error("wrong return");
    }
    auto returnFloat() {
        if(type==Type::NUMBER) {
            return value.fValue;
        }
    }
    void setObject(JSONObject* object) {
        this->value.object=object;
        type=Type::OBJECT;
    }
    void setList (JSONList* list) {
        this->value.list=list;
        type=Type::LIST;
    }
    void setString (std::string *s) {
        this->value.s=s;
        type=Type::STRING;
    }
    void setFloat(float fValue) {
        this->value.fValue=fValue;
        type=Type::NUMBER;
    }
    void setBool(bool bValue) {
        this->value.bValue=bValue;
        type=Type::BOOLEAN;
    }
};
class JSONParser {
private:
    std::fstream file;
    std::shared_ptr<JSONNode> root;
    std::unique_ptr<JSONNode> current;
    Tokenizer tokenizer;
public:
    JSONParser(const std::string filename): tokenizer(filename) {}
    void parse();
    std::shared_ptr<JSONNode> parseObject();
    std::shared_ptr<JSONNode> parseString();
    std::shared_ptr<JSONNode> parseNumber();
    std::shared_ptr<JSONNode> parseList();
    std::shared_ptr<JSONNode> parseBoolean();
    std::shared_ptr<JSONNode> parseNull();
};

#endif //PARSERJSON_PARSER_H

