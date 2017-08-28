/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    map<int,int> Twosum;
    int l = -1,r=-1;
    for(int i=0;i<A.size();i++)
    {
        if(Twosum.find(A[i]) != Twosum.end())
        {
            if( l==-1 || r == -1)
            {
                l = Twosum[A[i]];
                r = i;
            }
            else if(i < r)
            {
                l = Twosum[A[i]];
                r = i;
            }
            else if(Twosum[A[i]] < l && i<=r)
            {
                l = Twosum[A[i]];
                r = i;
            }
            
        }
        else
        {
            if(Twosum.find(B-A[i]) == Twosum.end())
                Twosum[B-A[i]] = i;
        }
    }
    vector<int> res;
    if(l==-1 || r== -1)
        return res;
    res.push_back(l+1);
    res.push_back(r+1);
    return res;
}
