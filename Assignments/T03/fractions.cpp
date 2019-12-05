#include<iostream>

using namespace std; 

int sum_digits(int x){
    if(x == 0){
        return 0;
    }
    return x % 10 + sum_digits(x / 10);
}

class Fraction{
private:
    int num;
    int den;

    // Function to return gcd of a and b 
    int Gcd(int a, int b) 
    { 
        if (a == 0) 
            return b;
        //cout<<(b%a)<<","<<a<<endl;
        return Gcd(b%a, a); 
    } 
    
    void Lowest() 
    { 

        int common_factor = Gcd(num,den); 
    
        den = den/common_factor; 
        num = num/common_factor; 
    } 
public:

    Fraction(){
        num = 1;
        den = 1;
    }
    Fraction(int n, int d){
        if(d == 0){
            cout<<"Error: denominator == 0!";
            exit(0);
        }
        num = n;
        den = d;
    }
    
    ~Fraction(){}

    int GetDen(){
        return den;
    }

    int GetNum(){
        return num;
    }

    void SetDen(int d){
        den = d;
    }

    void SetNum(int n){
        num = n;
    }

    void Add(Fraction rhs){
        
        int common = den * rhs.den;

        num = ((common / den) * num) + ((common / rhs.den) * rhs.num);
        den = common;
        Lowest();
    }

    void Mul(Fraction rhs){

        num *= rhs.num;
        den *= rhs.den;
        Lowest();
    }

    void Print(){
        cout<<"("<<num<<"/"<<den<<")";
    }
};
  
// Driver program 
int main() 
{ 

    Fraction f1(2,8);
    Fraction f2(3,11);

    f1.Add(f2);
    f1.Print();
    return 0; 
} 
