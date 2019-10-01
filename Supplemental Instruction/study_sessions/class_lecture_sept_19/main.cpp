#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool string_match(string big, string small)
{
    int index = big.find(small);
    return index >= 0;
}

string lower_string(string orig)
{
    string result = "";
    for (int i = 0; i < orig.size(); i++)
    {
        result += tolower(orig[i]);
    }
    return result;
}

struct Employee
{
    string name;
    string email;
    Employee()
    {
        name = "John Doe";
        email = "ilikecats@yahoo.com";
    }
    Employee(string n, string e)
    {
        name = n;
        email = e;
    }
};

struct Node
{
    Employee data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(Employee d, Node *n = NULL)
    {
        data = d;
        next = n;
    }
};

class List
{
public:
    List()
    {
        head = NULL;
    }

    void push(Employee e)
    {
        head = new Node(e, head);
    }

    Employee pop()
    {
        Employee result = head->data;
        Node *to_delete = head;
        head = head->next;
        delete to_delete;
        return result;
    }

    vector<Employee> find(string email)
    {
        vector<Employee> results;
        Node *temp = head;
        while (temp != NULL)
        {
            string l_emp_email = lower_string(temp->data.email);
            string l_key_email = lower_string(email);
            if (string_match(l_emp_email, l_key_email))
            {
                results.push_back(temp->data);
            }
            temp = temp->next;
        }
        return results;
    }

private:
    Node *head;
};

int main()
{
    List staff;
    staff.push(Employee());
    staff.push(Employee("Jeremy Glebe", "no@gmail.com"));
    staff.push(Employee("Trevor", "trevor@tr3v0r.net"));
    staff.push(Employee("Jane Doe", "ilikedogs@yahoo.com"));
    staff.push(Employee("Bob", "bbbbbbbbbbb@YAHOO.com"));
    //staff.pop();

    vector<Employee> v = staff.find("yahoo");
    cout << v.size() << endl;

    return 0;
}