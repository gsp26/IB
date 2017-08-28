/*
Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.empty())
        return 0;
    
    map<char,int> hash;
    int l = 0;
    int ml = 0;
    for(int i=0;i<A.size();)
    {
        if(hash.find(A[i]) == hash.end())
        {
            l++;
            if(l > ml)
                ml = l;
            hash[A[i]] = i;
            i++;
        }
        else
        {
            l=0;
            i = hash[A[i]]+1;
            hash.clear();
            
        }
    }
    return ml;
}
