/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.
*/

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>res;
    bool as = true;
    if(A.size()==1)
    {
        res.push_back(A[0]);
        int j = res.size()-1;
        if(res[j] < 9)
            res[j] = res[j] +1;
        else
        {
            res[j] = 0;
           vector<int>::iterator it;
            it = res.begin();
            res.insert(it,1);
        }
        return res;
        
    }
    for(int i=0;i<A.size();++i)
    {
        if(A[i]==0 && as)
            continue;
        as = false;
        res.push_back(A[i]);
    }
    int carr = 0;
    int j = res.size()-1;
    if(res[j] < 9)
        res[j] = res[j] +1;
    else
    {
        res[j] = 0;
        carr = 1;
    }
    j = j-1;
    while(carr && j >=0)
    {
        if(res[j] < 9)
        {
            res[j] = res[j] +1;
            carr = 0;
        }
        else
        {
            res[j] = 0;
            carr = 1;
        }
        j--;
    }
    if(carr)
    {
        vector<int>::iterator it;
        it = res.begin();
        res.insert(it,carr);
    }
    return res;
}
