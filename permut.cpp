#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int compare(const void *a, const void *b)
{
    return (*(cahr*)a - *(char*)b);
}

void swap(char *a,char *b)
{
    char *t = *a;
    *a = *b;
    *b = t;
}

void permute(char arr[])
{
    int size = strlen(arr);
    qsort(arr,size,sizeof(arr[0]),compare);

    //print the permutation one by one

}



int main()
{
    cout << "Program to print all permutations of a string " << endl;

    char arr[] = "AABCEF";
    permute(arr);



    return 0;
}
