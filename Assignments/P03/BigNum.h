#include <string>
#include "DLList.hpp"

using namespace std;


/**
 * Basic idea for the layout of main()
 * 
 * - Read in strings X and Y from the file
 * 
 * - Read an operation OP from the file
 * 
 * - Create two BigNums using the strings X and Y.
 * 
 * - Perform OP on X and Y resulting in a BigNum Z.
 *     ex) Z = X.Add(Y)
 * 
 * - Get a string S from Z and print it to a file.
 *     ex) S = Z.ToString()
 * 
 * 
 * Example algorithm for operation (Add, Subtract, Multiply)
 * 
 * - Assuming we are inside BigNum X and passed in BigNum Y:
 *     Make a copy of X (called xx)
 *       Ex) xx.Copy(X)
 *     Make a copy of Y (called yy)
 *       Ex) yy.Copy(Y)
 * 
 * - This will prevent us from destroying the original lists.
 * 
 * - Perform the actual operation on the two copies, creating a
 *   new BigNum called zz.
 * 
 * - Return the zz to main.
 */

/**
 * A BigNum is just a doubly-linked list with some math operations. Each Node
 * should represent a single digit of some large number.
 */
class BigNum: public DLList{
public:
    /**
     * Create a BigNum with an empty list. No value yet.
     */
    BigNum(){

    }
    /**
     * Create a BigNum from a string. Each digit will be stored in a Node.
     */
    BigNum(string big_number){
        for(int i=0;i<big_number.size();i++){
            InsertBack(big_number[i]-'0');
        }
    };
    /**
     * Add some other BigNum to this BigNum and return the
     * result (as a BigNum). The original two BigNums should be unaffected.
     */
    BigNum Add(BigNum other){
        DLList
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
    string ToString();


private:


};