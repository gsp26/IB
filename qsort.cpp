/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>

using namespace std;


struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[],int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[],int x,int y)
{
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    
    if(subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
        subsets[yroot].rank += subsets[xroot].rank;
        subsets[xroot].rank = 0;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank += subsets[yroot].rank;
        subsets[yroot].rank = 0;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
        subsets[yroot].rank = 0;
    }
}
int compare_function(const void *a,const void *b) {
    int x = ((struct subset *) a)->rank;
    int y = ((struct subset *) b)->rank;
    return (x-y);
}
void printAns(struct subset subsets[],int n)
{
    qsort((void*)subsets,sizeof(subsets)/sizeof(*subsets), sizeof(*subsets), compare_function);
    for(int i=0;i<n;i++)
        if(subsets[i].rank != 0)
        cout << subsets[i].rank <<" ";
}
int main()
{
    int n,m;
    cin >> n>> m;
    struct subset * subsets = (struct subset*)malloc(n * sizeof(struct subset));
    for(int i=0;i<n;i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 1;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin >> x>>y;
        Union(subsets,x-1,y-1);
        printAns(subsets,n);
        cout <<endl;
    }
    
}

