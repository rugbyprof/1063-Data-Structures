#include <iostream>
#include <fstream>
#include <string>
#include "Band.h"

int main()
{
    Band b1("Killer Zombies", 'Z');
    Band b2("Blue Wave", 'W');
    // 2 members
    b1.add_member("Zed");
    b1.add_member("Stacy");
    // 3 members
    b2.add_member("Zach");
    b2.add_member("Landon");
    b2.add_member("Chris");

    // print both using our operator that we made
    std::cout << b1 << '\n' << b2;
    // combine them using our plus operator
    Band b3 = b1 + b2;
    // print again using our operator that we made
    std::cout << '\n' << b3;

    // super fancy one liner
    // std::cout << b1 << '\n' << b2 << '\n' << b1 + b2;

    //try it using a file
    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << b3;
    outfile.close();

    // exit main
    return 0;
}