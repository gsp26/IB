/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
*/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0; //index for color 0
    int j=0; //index for color 1
    int k= 0;//index for color 2
    for(int x=0;x<A.size();x++)
    {
        if(A[x] == 0)
            i++;
        if(A[x] == 1)
            j++;
        if(A[x] == 2)
            k++;
    }
    for(int x=0;x<i;x++)
        A[x] = 0;
    for(int x=i;x<(i+j);x++)
        A[x] = 1;
    for(int x=(i+j);x<(i+j+k);x++)
        A[x] = 2;
}
