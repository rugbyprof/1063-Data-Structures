#include <iostream>
#include <string>
#include <vector>

class Band
{
public:
    Band();
    Band(std::string, char);
    void add_member(std::string);
    // print the logo followed by all members
    friend std::ostream &operator<<(std::ostream &, Band);
    // adds members from b2 to b1,
    Band operator+(Band);

private:
    std::string band_name;
    char logo;
    int num;
    std::vector<std::string> members;
};