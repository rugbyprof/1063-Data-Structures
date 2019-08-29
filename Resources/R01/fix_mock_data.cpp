#include <iostream>
#include <fstream>
//https://stackoverflow.com/questions/55116344/how-to-setup-vs-code-for-c-14-c-17
//https://github.com/nlohmann/json
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

json randomGrades(int min_count, int max_count, int min_val, int max_val ){

    json j;
    
    int val = 0;
    int num_grades = (rand() % (max_count-min_count)) + min_count;

    for(int i = 0;i<=num_grades;i++){
        val = (rand() % (max_val-min_val)) + min_val;
        j.push_back(val);
    }

    return j;
}

int main(int argc,char **argv){
    srand(time(0));
    json data;

    std::ifstream i("mock_data_v1.json");
    i >> data;

    //std::cout << data.dump(4) << std::endl;

    // iterate the array
    // for (json::iterator it = data.begin(); it != data.end(); ++it) {
    //     std::cout << *it << '\n';
    // }


    json newData;
    // range-based for
    for (auto& element : data) {
        //std::cout << element["grades"] << '\n';

        element["grades"] = randomGrades(8,14,67, 99 );

        cout<<element<<endl;
        newData.push_back(element);
    }


    std::ofstream o("mock_data_v2.json");
    o << newData << std::endl;


    return 0;
}