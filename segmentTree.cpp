#include<iostream>

using namespace std;

int * constructST(int arr[],int n)
{
    int x = (int) ceil(log2(n));

    int max_size = 2*(int)pow(2,x)-1;
int main()
{
    int arr[] = {1,3,5,7,9,11}
    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructST(arr,n);

    cout << "Sung of values in range " << getSum(arr,n,1,3) << endl;

    updateValue(arr,st,n,1,10);

    cout << "\nSum of values in range " << getSum(arr,n,1,3) << endl;


    return 0;
}

