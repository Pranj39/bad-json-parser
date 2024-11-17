#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
struct JsonValue{
    int integer = 0;
    float decimal = 0;

    std::vector<double> a;

    std::string text = "";

    std::map<std::string, JsonValue> json_map;

    void print(){
        std::cout<<std::endl<<"Text: "<<text;
        std::cout<<" int: "<<integer;
        std::cout<<" dec: "<<decimal;
        std::cout<<" arr: [";
        for(int i = 0; i<a.size();i++){
            std::cout<<a[i];
            if(i!=a.size()-1){
                std::cout<<", ";
            }
        }
        std::cout<<"]";
        std::cout<<" map: {"<<std::endl;

        for(auto & x: json_map){
            if(x.first != "")std::cout<<x.first<<':';
            else{
                std::cout<<"Base: ";
            }
            x.second.print();
        }
        std::cout<<"}";

    }
};

class Json{
    public:
    void ParseValues(std::string, JsonValue&);
    
    JsonValue ParseJson(std::string, int&);

    std::pair<std::string, JsonValue> GetKeyValuePair(std::string, int&);
    std::string ReadFile(std::string);

    
};