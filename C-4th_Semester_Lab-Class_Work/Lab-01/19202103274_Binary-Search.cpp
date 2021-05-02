#include<iostream>
#include<conio.h>
using namespace std;

int binary(int a[], int n)
{
    int big, end, mid, k;
    cout << endl;
    cout << "Enter a value to find you : ";
    cin >> k;
    big = 0;
    end = n - 1;
    mid = (big+end)/2;
    while (big <= end)
    {
        if(a[mid] < k)
            big = mid + 1;

        else if (a[mid] == k)
        {
            cout<<"\n" << k << " found at location " << mid+1 <<"\n\n\t\t\t###THANK YOU###"<<endl;
            break;
        }
        else
            end = mid - 1;
        mid = (big + end)/2;
    }
    if(big > end)
        cout << "Not found your Inputed Value!" << endl;

 getch();
}

/////////////////////////////////////////////////////////////////////

int main()
{
    int i, n, a[100];
    cout << "Enter The number of Elements: ";
    cin >> n;

  //Your inputed Sorted value
    cout <<"\n"<< "Please Enter the  Sorted " << n << " integers:" << endl;
    for(i = 0; i < n; i++)
        cin >> a[i];

    binary(a, n);
}
