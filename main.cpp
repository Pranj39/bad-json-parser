#include "Json.cpp"
int main(){
    Json j;    
    std::fstream file("data.json",std::ios::in);
    std::string text;
    std::stringstream ss;
    while(file>>text){
    ss<<text;
    }
    ss>>text;
    int t = -1;
    JsonValue x = j.ParseJson(text, t);
    x.print();
}