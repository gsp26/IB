/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
 [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ] 
 */
 
 vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   // int m = A;
    //int n= A;
    int k = 1;
    vector<vector<int>> res(A,vector<int>(A,1));
    if(A ==1)
    {
        return res;
    }
    int t=0;
	int b = A-1;
	int r = A-1;
	int l = 0;
	int dir = 0;
	
    while(t<=b && l <=r)
	{
	    if(dir == 0) //left to right
	    {
	        for(int i=l;i<=r;++i)
	            res[t][i] = k++;
	        dir = 1;
	        t++;
	     }
	     else if(dir == 1)
	     {
	         for(int i=t;i<=b;++i)
	            res[i][r] = k++;
	         r--;
	         dir = 2;
	     }
	     else if( dir ==2)
	     {
	         for(int i=r;i>=l;i--)
	            res[b][i] = k++;
	         b--;
	         dir = 3;
	     }
	     else
	     {
	         for(int i=b;i>=t;i--)
	            res[i][l] =k++;
	         l++;
	         dir = 0;
	     }
	     
	}
    return res;
