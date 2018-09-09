#include<iostream>

using namespace std;


int solve( int arr[],int op[],int n,int m, int o)
{
    cout << "\navailable numbers- " << endl;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    cout << "\navailable operators- " << endl;
    for(int i=0;i<m;i++)
        cout << op[i] << " ";

    cout << "\nNumber to make - " << o << endl;




    return -1;
}

int main() 
{
    cout << "to solve the touchpad problem >>> " << endl;

    int t; //number of test cases
    cin >> t;
    int n,m,o;
    for(int i=0;i<t;i++)
    {
        cin >>n;
        cin >> m;
        cin >> o;
        int arr[n] ; //n numbers
        int op[m] ; //operands
        for (int j=0;j<n;j++)
            cin >> arr[j];
        for (int j=0;j<m;j++)
            cin >> op[j];

            
        for (int j=0;j<n;j++)
            cout <<  arr[j] << " ";
        cout << endl;
        for (int j=0;j<m;j++)
            cout <<  op[j] << " ";
        cout << endl;
        cout << solve(arr,op,n,m,o) << endl;
    }
    return 0;
}



