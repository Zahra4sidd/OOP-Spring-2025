#include "iostream"
#include <cstring>
using namespace std;

class Reverse
{
    // member functions
    public:
    char string[30];
    int getString(char arr[])
    {
        int i = 0;
        char ch;
        cout<<"Enter a string: ";
        while(i < 100)
        {
            ch = getchar();
            if(ch=='\n')
            {
                break;
            }
            else
            {
                arr[i] = ch;
                i++;
            }
        }
        arr[i] = '\0';
        return strlen(arr);
    }
    void displayString(char arr[],int length)
    {
        for(int i=0;i<length;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    void reverseString(char arr[],int length)
    {
        
        for(int i = 0; i < length/2; i++)
        {
            char temp = arr[i];
            arr[i] = arr[length-i-1];
            arr[length-i-1] = temp;
        }
        for(int i=0;i<length;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    void reverseWords(char arr[],int length)
    {
        int start = 0;
        for(int i=0;i<=length;i++)
        {
            if(arr[i]=='\0' || arr[i]==' ')
            {
                int end = i-1;
                while(start<end)
                {
                    char temp = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    start++;
                    end--;
                }
                start = i+1;
            }
        }
        for(int i=0;i<length;i++)
        {
            cout<<arr[i];
        }
    }
};

int main()
{
    Reverse r1;
    char arr[100];
    int length = r1.getString(arr);
    r1.displayString(arr,length);
    r1.reverseString(arr,length);
    r1.reverseWords(arr,length);
}
