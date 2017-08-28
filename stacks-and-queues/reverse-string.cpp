/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
PROBLEM APPROACH :

Complete solution in hints.*/

string Solution::reverseString(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> st;
    for(int i=0;i<A.size();i++)
    {
        st.push(A[i]);
    }
    for(int i=0;i<A.size();i++)
    {
        A[i] = st.top();
        st.pop();
    }
    return A;
}
