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

    int GetDen(){
        return den;
    }

    int GetNum(){
        return num;
    }

    int SetDen(int d){
        den = d;
    }

    int SetNum(int n){
        num = n;
    }

    void Add(Fraction rhs){
        
        int common = den * rhs.GetDen();

        cout<<"common:"<<common<<endl;

        num = ((common / den) * num) + ((common / rhs.GetDen()) * rhs.GetNum());
        den = common;
        Lowest();
    }

    void Print(){
        cout<<"("<<num<<"/"<<den<<")";
    }
};
  
// Driver program 
int main() 
{ 
    // int num1=3, den1=8, num2=2, den2=12, den3, num3; 
    // addFraction(num1, den1, num2, den2, num3, den3); 
    // printf("%d/%d + %d/%d is equal to %d/%d\n", num1, den1, 
    //                                num2, den2, num3, den3); 

    //cout<<sum_digits(11111111)<<endl;
    Fraction f1(2,8);
    Fraction f2(3,11);

    f1.Add(f2);

    cout<<f1.GetNum()<<"/"<<f1.GetDen()<<endl;
    f1.Print();
    return 0; 
} 