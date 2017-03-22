#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct LocationInfo {
    string street;
    string city;
    string state;
    string zipcode;
};
struct ContactInfo {
    string email;
    string phone;
    string cell;
};

struct PersonInfo {
    string fname;
    string lname;
    string dob;
    string ssn;
};

ostream& operator<<(ostream& os, const PersonInfo& pi)
{
    os << pi.fname << ' ' << pi.lname << ' ' << pi.dob << ' ' << pi.ssn << "\n";
    return os;
}

struct Employee {
    LocationInfo address_data;
    ContactInfo contact_data;
    PersonInfo person_data;
};

struct Results {
    int num_found;
    int list[50];
};

Results FindEmployee(Employee* array, int size, string key)
{
    Results r;
    r.num_found = 0;

    for (int i = 0, j = 0; i < size; i++) {
        if (array[i].person_data.lname == key) {
            //r.num_found++;
            //r.list[j++] = i;
            r.list[r.num_found++] = i;
        }
    }
    return r;
}

int main()
{

    Employee* DataArray;

    DataArray = new Employee[500];

    ifstream fin;
    fin.open("people.txt");
    string street;
    string fname;
    string lname;
    string dob;
    string ssn;
    string email;
    string city;
    string state;
    string phone;
    string cell;

    int i = 0;

    while (!fin.eof()) {
        getline(fin, DataArray[i].person_data.lname);
        getline(fin, DataArray[i].person_data.fname);
        getline(fin, DataArray[i].person_data.dob);
        getline(fin, DataArray[i].person_data.ssn);
        getline(fin, DataArray[i].contact_data.email);
        getline(fin, DataArray[i].address_data.street);
        getline(fin, DataArray[i].address_data.city);
        getline(fin, DataArray[i].address_data.state);
        getline(fin, DataArray[i].contact_data.phone);
        getline(fin, DataArray[i].contact_data.cell);
        i++;
    }

    i = 381;
    cout << DataArray[i].person_data.lname << endl;
    cout << DataArray[i].person_data.fname << endl;
    cout << DataArray[i].person_data.dob << endl;
    cout << DataArray[i].person_data.ssn << endl;
    cout << DataArray[i].contact_data.email << endl;
    cout << DataArray[i].address_data.street << endl;
    cout << DataArray[i].address_data.city << endl;
    cout << DataArray[i].address_data.state << endl;
    cout << DataArray[i].contact_data.phone << endl;
    cout << DataArray[i].contact_data.cell << endl;

    Results r = FindEmployee(DataArray, 500, "smith");

    cout << r.num_found << endl;
    for (int i = 0; i < r.num_found; i++) {
        cout << r.list[i] << endl;
        cout << DataArray[r.list[i]].person_data;
    }

    return 0;
}
