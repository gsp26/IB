/*
Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

*/

int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<char> st;
    int prevOpen = INT_MIN;
    int prevClose  = INT_MIN;
    
    bool startCons = false;
    bool endCons = false;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i] != ')')
        {
            st.push(A[i]);
        }
        else if(A[i] == ')')
        {
            string str;
            int nc = 0;
            while(st.top() != '(')
            {
                str += st.top();
                st.pop();
                nc++;
            }
            str += st.top();
            str += A[i];
            st.pop();
            if(str == "()" || nc == 1)
            {
                return 1;
            }
        }
    }
    return 0;
       
}
