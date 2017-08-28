/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

int Solution::threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*sort(A.begin(),A.end());
    //int sum = INT_MAX;
    int diff = INT_MAX;
    for(int i=0;i<A.size()-2;++i)
    {
        //sum = 
        int x  = B - (A[i]+A[i+1]+A[i+2]);
        if(x < diff)
            diff = x;
    }
    return B-diff;*/
    
        if(A.size() < 3){
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int i = 0;
    int sum, minDiff = INT_MAX;
    int count = 0;
    
    while(i < A.size()-2){
        int left = i+1;
        int right = A.size()-1;
        while(right > left){
            int temp = A[i]+A[left]+A[right];
            int diff = abs(temp-B);
            if(diff == 0){
                return B;
            }
            if(diff < minDiff){
                minDiff = diff;
                sum = temp;
            }
            if(temp < B){
                left++;
            }
            else{
                right--;
            }
        }
        i++;
    }
    
    return sum;
}
