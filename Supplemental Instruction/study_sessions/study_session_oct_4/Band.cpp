#include"Band.h"

Band::Band(){
    num = 0;
    band_name = "";
    logo = ' ';
    members = std::vector<std::string>();
}

Band::Band(std::string name, char l){
    num = 0;
    band_name = name;
    logo = l;
    members = std::vector<std::string>();
}

void Band::add_member(std::string member_name){
    members.push_back(member_name);
    num++;
}

Band Band::operator+(Band other){
    Band result = *this;
    for(int i = 0; i < other.num; i++){
        result.num++;
        result.members.push_back(other.members[i]);
    }
    return result;
}

std::ostream &operator<<(std::ostream & out, Band b){
    out << b.band_name << '\n' << b.logo << '!' << '\n';
    out << b.num << " members:\n";
    for (int i = 0; i < b.num; i++){
        out << b.members[i] << '\n';
    }
    return out;
}