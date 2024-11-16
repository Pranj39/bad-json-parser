#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
struct JsonValue{
    int integer;
    float decimal;

    int a[10];

    std::string text;

    std::map<std::string, JsonValue> json_map;
};

class Json{
    public:
    void ParseValues(std::string, JsonValue&);
    
    JsonValue ParseJson(std::string, int);

    std::pair<std::string, JsonValue> GetKeyValuePair(std::string, int);
    std::string ReadFile(std::string);

    
};