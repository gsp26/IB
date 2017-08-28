/*
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

 Note: You may not slant the container. 
Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6
*/
int Solution::maxArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int max_area = 0;
    
    /*for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int area = min(A[i],A[j]) * (j-i);
            if(area > max_area)
                max_area = area;
        }
    }*/
    int start = 0;
    int end = A.size()-1;
    
    while(start<end)
    {
        int area = min(A[start],A[end]) * (end -start);
        if(area > max_area)
            max_area = area;
        if(A[start] > A[end])
            end--;
        else
            start++;
    }
    return max_area;
}
