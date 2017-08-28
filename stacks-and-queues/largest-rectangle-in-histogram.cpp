Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.*/

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> st;
    
    int sol = 0;
    
    int i = 0, n = A.size();
    
    while(i < n){
        if(st.empty() || A[st.top()] <= A[i]){
            st.push(i);
            i++;
        }
        else{
            int top = st.top();
            st.pop();
            
            int area = 0;
            
            if(st.empty()){
                area = A[top] * i;
            }
            else{
                area = A[top] * (i - st.top() - 1);
            }
            
            sol = max(sol, area);
        }
    }
    
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        int area = 0;
        
        if(st.empty()){
            area = A[top] * i;
        }
        else{
            area = A[top] * (i - st.top() - 1);
        }
        
        sol = max(sol, area);
    }
    
    return sol;
    
}
