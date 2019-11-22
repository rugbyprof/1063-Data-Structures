#include "DLList.hpp"
#include <string>

using namespace std;

/**
 * A BigNum is just a doubly-linked list with some math operations. Each Node
 * should represent a single digit of some large number.
 */
class BigNum : public DLList {
public:
    /**
     * Create a BigNum with an empty list. No value yet.
     */
    BigNum() {
        InsertBack(0);
    }

    BigNum(const BigNum &B) {
        Node *temp = B.Head;

        while (temp) {
            InsertBack(temp->data);
            temp = temp->Next;
        }
    }
    /**
     * Create a BigNum from a string. Each digit will be stored in a Node.
     */
    BigNum(const string big_number) {
        for (int i = 0; i < big_number.size(); i++) {
            InsertBack(big_number[i] - '0');
        }
    };
    /**
     * Add some other BigNum to this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Add(BigNum other) {
        // Make copies of each list
        BigNum lhs(ToString());
        BigNum rhs(other.ToString());
        BigNum result;
        int sum = 0;
        int carry = 0;

        cout<<"lhs"<<lhs.ToString()<<endl;


        while (lhs.Size()) {
            sum = lhs.GetBack() + rhs.GetBack() + carry;
            cout<<"size: "<<lhs.Size()<<endl;
            carry = sum / 10;
            sum = sum % 10;
            result.InsertFront(sum);

            lhs.Delete();
            rhs.Delete();
        }

        rhs.Print();

        if (rhs.Size()) {
            while (rhs.Size()) {
                sum = rhs.GetBack() + carry;
                carry = sum / 10;
                sum = sum % 10;
                result.InsertFront(sum);

                rhs.Delete();
            }
        } else {
            if (carry > 0) {
                result.InsertFront(carry);
            }
        }

        return result;
    }

    /**
     * Subtract some other BigNum from this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Sub(BigNum other);
    /**
     * Multiply some other BigNum with this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Mul(BigNum other);

    /**
     * Traverse list and add the number from each Node to a string. Return
     * that string.
     */
    string ToString() {
        // Points to "Head" of the
        Node *temp = Head;
        string s;

        while (temp) {
            int d = temp->data;
            s += to_string(d);
            temp = temp->Next;
        }

        return s;
    }

    void Print() {
        cout << ToString() << endl;
    }

    BigNum &operator=(const string &big_number) {
        DestroyList();
        for (int i = 0; i < big_number.size(); i++) {
            InsertBack(big_number[i] - '0');
        }
        return *this;
    }

    BigNum operator=(const BigNum &bignum) {
        BigNum B(bignum);
        return B;
    }

    BigNum operator+(BigNum &other) {
        cout << "adding" << endl;
        BigNum B;
        B.Add(*this);

        B.Print();

        B.Add(other);
        B.Print();
        return B;
    }

    friend ostream &operator<<(ostream &os, BigNum &bn){
        os << bn.ToString() ;
        return os;
    }

private:
};