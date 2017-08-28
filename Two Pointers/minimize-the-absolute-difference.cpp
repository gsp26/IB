/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/
int max(int a,int b,int c)
{
    if( a >=b && a >= c)
        return a;
    if( b >= a && b >= c)
        return b;
    if(c >=a && c >= b)
        return c;
}
int min(int a,int b,int c)
{
    if( a <=b && a<=c)
        return a;
    if( b<=a && b<=c)
        return b;
    if(c<=a && c<=b)
        return c;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int res = INT_MAX;
    /*for(int i=0;i<A.size();++i)
    {
        for(int j=0;j<B.size();j++)
        {
            for(int k=0;k<C.size();++k)
            {
                int x = abs(max(A[i],B[j],C[k]) - min(A[i],B[j],C[k]));
                if( x< res)
                    res = x;
            }
        }
    }*/
    
    int x = A.size()-1;
    int y = B.size()-1;
    int z = C.size()-1;
    
    while(x >=0 && y >= 0 && z >=0)
    {
        int diff = max(A[x],B[y],C[z]) - min(A[x],B[y],C[z]);
        if( diff < res)
            res = diff;
        if(max(A[x],B[y],C[z]) == A[x])
        {
            x--;
            continue;
        }
        if(max(A[x],B[y],C[z]) == B[y])
        {
            y--;
            continue;
        }
        if(max(A[x],B[y],C[z]) == C[z])
        {
            z--;
            continue;
        }
    }
    return res;
}
