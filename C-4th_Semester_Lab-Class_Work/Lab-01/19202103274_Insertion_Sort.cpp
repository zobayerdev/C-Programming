#include<iostream>
#include<conio.h>
using namespace std;

void insertion(int a[], int n, int i)
{
    int temp, j;
    for(i = 1; i < n; i++)
    {
        int temp = a[i];
        j = i-1;

        while(j>=0 &&  a[j]>temp)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
    }
    cout << endl;
    cout << "\nInsertion Sorted Array:  " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << endl;

getch();

}

///////////////////////////////////////////////////

int main()
{
    int i, n, a[100];
    cout << "Enter number of elements:  ";
    cin >> n;
    cout << "\nEnter the Unsorted " << n << " integers:" << endl;
    for(i = 0; i < n; i++)
        cin >> a[i];

    insertion(a, n, i);
}
