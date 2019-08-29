#include <iostream>
#include <fstream>
//https://stackoverflow.com/questions/55116344/how-to-setup-vs-code-for-c-14-c-17
//https://github.com/nlohmann/json
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

int main(int argc,char **argv){

    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    json data;

    string s = j.dump();

    std::cout << j.dump(4) << std::endl;

    std::ifstream i("data.json");
    

    i >> data;

    std::cout << data.dump(4) << std::endl;

    std::cout << data["name"] << std::endl;

    std::cout << data["list"][1] << std::endl;

    return 0;
}