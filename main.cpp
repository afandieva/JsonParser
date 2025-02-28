#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class JSON_Node;

using JSONObject = std::map<std::string,std::shared_ptr<JSON_Node>>;
using JSONList = std::vector<std::shared_ptr<JSON_Node>>;
class JSON_Node {
    enum class Type {OBJECT,LIST,STRING,NUMBER,BOOLEAN,NULL_TYPE};
    union Values {
        JSONObject* object;
        JSONList* list;
        std::string* s;
        float fValue;
        bool bValue;
    } value;
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
        throw std::logic_error("wrong return");
    }
    void setObject(JSONObject* object) {
        this->value.object = object;
        type = Type::OBJECT;
    }
    void setList(JSONList* list) {
        this->value.list = list;
        type = Type::LIST;
    }
    void setString(std::string* s) {
        this->value.s = s;
        type = Type::STRING;
    }
    void setFloat(float fValue) {
        this->value.fValue = fValue;
        type = Type::NUMBER;
    }
    void setBool(bool bValue) {
        this->value.bValue = bValue;
        type = Type::BOOLEAN;
    }
};
