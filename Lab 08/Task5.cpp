#include<iostream>
#include<string>
using namespace std;

class Fraction{
    private:
    int numerator, denominator;
    int gcd(int a, int b)const{
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplify(){
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
    public:
    Fraction(int n = 0, int d = 1):numerator(n),denominator(d){
        simplify();
    }
    Fraction operator+(const Fraction& obj){
        int num = (numerator * obj.denominator) + (obj.numerator * denominator);
        int den = denominator * obj.denominator;
        return Fraction(num, den);
    }
    Fraction operator-(const Fraction& obj){
        int num = (numerator * obj.denominator) - (obj.numerator * denominator);
        int den = denominator * obj.denominator;
        return Fraction(num, den);
    }
    Fraction operator*(const Fraction& obj){
        return Fraction(numerator * obj.numerator, denominator * obj.denominator);
    }
    Fraction operator/(const Fraction& obj){
        return Fraction(numerator * obj.denominator, denominator * obj.numerator);
    }\
    friend ostream& operator<<(ostream& os, const Fraction& obj){
        os<<obj.numerator<<"/"<<obj.denominator;
        return os;
    }
};
int main(){
    Fraction f1(3,2), f2(5,4);
    cout<<f1<<" + "<<f2<<" = "<<(f1 + f2)<<endl;
    cout<<f1<<" - "<<f2<<" = "<<(f1 - f2)<<endl;
    cout<<f1<<" * "<<f2<<" = "<<(f1 * f2)<<endl;
    cout<<f1<<" / "<<f2<<" = "<<(f1 / f2)<<endl;
    return 0;
}
