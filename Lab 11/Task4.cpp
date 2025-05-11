# include <iostream>
# include <exception>
# include <typeinfo>
# include <cmath>
#include <type_traits>

using namespace std;

class BaseException : public exception 
{
    public:
        virtual const char* what() const noexcept = 0;
};

template<typename N>
class NegativeNumberException: public BaseException
{
    public:
        N num;

        NegativeNumberException(N num): num(num){}

        const char* what() const noexcept override
        {
            return "NegativeNumberException - Input must be non-negative!";
        }
};

template<typename I>
class InvalidTypeException: public BaseException
{
    public:
        I var;

        InvalidTypeException(I var): var(var){}

        const char* what() const noexcept override
        {
            return "InvalidTypeExceptionException - Non-numeric data detected!";
        }
};

template<typename T>
void mySqrt(T num)
{
    if constexpr (!std::is_arithmetic<T>::value) 
    {
        throw InvalidTypeException<T>(num);
    }
    else if (num < 0)
    {
        throw NegativeNumberException<T>(num);
    }
    else
    {
        cout << "Square Root: " << sqrt(num) << endl;
    }
}

int main()
{
    try 
    {
        mySqrt(-10);
    }
    catch(BaseException &b)
    {
        cout << b.what() << endl;
    }

    try 
    {
        mySqrt("Hello");
    }
    catch(BaseException &b)
    {
        cout << b.what() << endl;
    }
    
}
