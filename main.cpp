#include "Json.cpp"
int main(){
    Json j;
    std::string text = "{\"wowwow\":{\"hellohilkj\"}}";
    j.ParseJson(text, -1);
}