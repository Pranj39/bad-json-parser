
#include "Json.hpp"
std::string ReadFile(std::string filePath){
    std::fstream file(filePath,std::ios::in);
    std::string text;
    std::stringstream ss;
    while(file>>text){
    ss<<text;
    }
    ss>>text;
    return text;
}

JsonValue Json::ParseJson(std::string text, int n){
    std::map<std::string, JsonValue> json_map;
    for(int i = n+1; i<text.size();i++){
        if(text[i]==' '){
            continue;
        }
        if(text[i]=='{'){
            auto [key, value] = GetKeyValuePair(text, i+1);
        }   
    }
    return {.json_map = json_map};
}

std::pair<std::string, JsonValue> Json::GetKeyValuePair(std::string text, int n){
    JsonValue value;
    std::string key;
    std::string v;
    for(int i = n; i < text.size(); i++){
        if(text[i] == ' '){
            continue;
        }
        if(text[i] == '"'){
            i++;
            for(int j = i; j<text.size(); j++){
                if(text[j]!='"'){
                    key.push_back(text[j]);
                }else{
                    i = j+1;
                    break;
                }
            }
        }

        if(text[i] == ':'){
            continue;
        }
        if(text[i]==' '){
            continue;
        }
        if(text[i]=='}'){
            ParseValues(v, value);
            continue;
        }
        if(text[i]== '{'){
            value = ParseJson(text, i+1);
        }
        v.push_back(text[i]);
    }
    std::cout<<key;
    return {key, value};
}

void Json::ParseValues(std::string s, JsonValue& v){
    if(s.find('[')==std::string::npos)
    {    
        if(s.find('.')!=std::string::npos){
            std::string c = s;
            c.erase(c.begin()+c.find('.'));
            int i = 0;
            while(i<c.size() && ::isdigit(c[i])){
                i++;
            }
            if(i==c.size()){
                v.decimal = std::stod(s);
            }else{
                v.text = s;
            }
        }else{
            std::string c = s;
            int i = 0;
            while(i<c.size() && ::isdigit(c[i])){
                i++;
            }
            if(i==c.size()){
                v.integer = std::stod(s);
            }else{
                v.text = s;
            }
            
        }
    }else{
        std::vector<int> i =
        for(int i = 0; i<s.size();i++){

        }
    }
}