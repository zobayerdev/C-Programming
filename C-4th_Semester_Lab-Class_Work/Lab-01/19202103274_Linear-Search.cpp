#include <iostream>
#include<conio.h>
using namespace std;

void func(int data[], int count, int n)
{
    int i;
    for(i = 0; i < count; i++)
    {
        if(data[i] == n)
        {
            break;
        }
    }
    if (i < count){
         cout<<"\n" << n << " found in the index at = " << i+1;}
    else
         cout << "Sorry !! No data found!!";

getch();
}

int main()
{
    int data[] = {-1,-2,-3,15,17,4,3,9,10};
    int count, i, n;
    cout << "Enter a number to search in this Array [-1,-2,-3,15,17,4,3,9,10]\n\n";

    cout<<"Enter Your Finding Value: " ;
    cin >> n;
    func(data, count, n);
    return 0;
}
