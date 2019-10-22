#include <iostream>

using namespace std;

struct Node {
    int Value;
    Node *Next;
    Node(int x) {
        Value = x;
        Next = NULL;
    }
};

class LinkedList {
private:
    Node *Head;

public:
    LinkedList() {
        Head = NULL;
    }

    void frontSert(int x) {
        Node *Temp = new Node(x);

        if (Head == NULL) {
            Head = Temp;
        } else {
            Temp->Next = Head;
            Head = Temp;
        }
    }

    void endSert(int x) {
        Node *Temp = new Node(x);

        if (Head == NULL) {
            Head = Temp;
        } else {
            Node *Temp2 = Head;

            while (Temp2->Next != NULL) {

                Temp2 = Temp2->Next;
            }

            Temp2->Next = Temp;
        }
    }

    void print() {
        Node *Temp = Head;

        while (Temp != NULL) {
            cout << Temp->Value;
            if (Temp->Next) {
                cout << "->";
            }
            Temp = Temp->Next;
        }
    }
};

int menu() {
    int choice = 0;
    while (choice < 1 || choice > 3) {
        cout << "\nMenu of Operations:\n";
        cout << "    1 - Find Employee\n";
        cout << "    2 - Delete Employee\n";
        cout << "    3 - Quit\n";
        cout << "Choice: ";
        cin >> choice;
    }
    return choice;
}

bool substringMatch(string macro, string micro) {
    return (macro.find(micro) != std::string::npos);
}

int main() {

    LinkedList L;

    for (int i = 0; i < 8; i++) {
        L.frontSert(i);
    }

    for (int i = 0; i < 8; i++) {
        L.endSert(i);
    }
    L.print();

    int choice = 0;

    while (choice != 3) {
        choice = menu();
    }

    cout << substringMatch("boomer sooner", "soon") << endl;
    cout << substringMatch("boomer sooner", "Boom") << endl;
    cout << substringMatch("boomer sooner", "bum") << endl;

    string test = "Hello World";
    for (auto &c : test) {
        c = tolower(c);
    }

    cout << test << endl;
    return 0;
}
