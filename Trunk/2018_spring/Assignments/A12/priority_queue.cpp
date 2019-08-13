/////////////////////////////////
// List Based Queue
//
// First In First Out
//
// Method:
//    void push()
//    string pop()
//    bool empty()
//    bool full() ?????
/////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countLen(char *word)
{
    int l = 0;
    while (*word)
    {
        *word++;
        l++;
    }
    return l;
}

struct Node
{
    string val;
    Node *next;
    Node()
    {
        val = " ";
        next = NULL;
    }
    Node(string v)
    {
        val = v;
        next = NULL;
    }
};

/**
* class Queue
*     description of what this class does ...
* Methods:
*  - Queue()       : constructor
*  - string pop()  : 
*/
class Queue
{
  private:
    Node *Front;
    Node *Rear;

  public:
    /**
   * Queue
   * constructor
   * 
   * params:
   *     - none
   */
    Queue()
    {
        Front = Rear = NULL;
    }

    /**
   * pop
   * 
   */
    string pop()
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string v = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            return v;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return " ";
        }
    }

    void push(string v)
    {
        Node *n = new Node(v);

        // handle the empty case
        if (empty())
        {
            Front = n;
            Rear = n;
        }
        else
        {
            // not empty add to rear
            Rear->next = n;
            Rear = n;
        }
    }

    bool empty()
    {
        return (Front == NULL && Rear == NULL);
    }

    void print()
    {
        Node *temp = Front;
        while (temp)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    bool pop(string &v)
    {
        if (!empty())
        {
            Node *temp = Front;   // temp pointer so we can delete node
            string t = temp->val; // grab value out of node
            Front = Front->next;  // move pointer to next node
            delete temp;          // give mem back to system
            v = t;
            return true;
        }
        else
        {
            cout << "error: cannot pop off empty queue." << endl;
            return false;
        }
    }
};

int main()
{
    Queue Q;
    string animal;

    Q.push("owl");
    Q.push("cat");
    Q.push("dog");

    while (Q.pop(animal))
    {
        cout << animal << endl;
    }
}
