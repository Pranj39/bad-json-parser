
#include "Json.hpp"
static std::string ReadFile(std::string filePath){
    std::fstream file(filePath,std::ios::in);
    std::string text;
    std::stringstream ss;
    while(file>>text){  
    ss<<text;
    }
    ss>>text;
    return text;
}

JsonValue Json::ParseJson(std::string text, int& n){
    std::map<std::string, JsonValue> json_map;
    int i = n+1;
    while(text[i]!='}' && text[i]!=']' && i<text.size()){
        if(text[i]==' '){
            i++;
            continue;
        }
        if(text[i]==','){
            i++;
            continue;
        }
            auto [key, value] = GetKeyValuePair(text, i);
            json_map[key] = value;
        i++;  
    }
    n=i;
    return {.json_map = json_map};
}

std::pair<std::string, JsonValue> Json::GetKeyValuePair(std::string text, int& n){
    JsonValue value;
    std::string key;
    std::string v;
    bool t  = false;
    for(int i = n; i < text.size(); i++){
        n = i;
        if(text[i] == ' '){
            continue;
        }
        if(text[i] == '"' && t==false){
            i++;
            for(int j = i; j<text.size(); j++){
                if(text[j]!='"'){
                    key.push_back(text[j]);
                }else{
                    i = j+1;
                    n = i;
                    t = true;
                    break;
                }
            }
        }else if(text[i]=='"'&&t==true){
            continue;
        }

        if(text[i] == ':'){
            continue;
        }
        if(text[i]==' '){
            continue;
        }
        if(text[i]=='['){
            i++;
            value.a.reserve(10);
            std::string mn;
            for(int j = i; j<text.size(); j++){
                if(text[j]==']'){
                    value.a.push_back(std::stod(mn));
                    mn.clear();
                    i = j+1;
                    n = i;
                    break;
                }
                if(text[j] == ','){
                    value.a.push_back(std::stod(mn));
                    mn.clear();
                    continue;
                }
                mn.push_back(text[j]);
            }
        }
        if(text[i]=='}'){
            if(v!="")ParseValues(v, value);
            n = i-1;
            break;
        }
        if(text[i]==',')break;
        if(text[i]== '{'){
            value = ParseJson(text, i);
            n = i;
            break;
        }
        v.push_back(text[i]);
    }
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
        std::vector<double> n;
        n.reserve(10);
        for(int i = 0; i<s.size();i++){
            if(s[i]==' '){
                continue;
            }
            if(s[i]=='['){
                i++;
                std::string nn;
                for(int j = i; j<s.size();j++){
                    if(s[j] == ']') continue;
                    if(s[j]==' ') continue;
                    if(s[j]==',') break;
                    nn.push_back(s[j]);
                }
                n.push_back(std::stod(nn));
            }
        }
    }
}