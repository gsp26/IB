/*
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

*/
vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector<vector<int> > res;
     vector<int> ans;
     A++;
    for(int i=0;i<A;i++)
    {
       
        if(i==0)
        {
            ans.push_back(1);
        }
        else
        {
            for(int j=0;j<=i;++j)
            {
                if(j==0)
                {
                    ans.push_back(1);
                    continue;
                }
                else
                {
                    if(res[i-1].size() > j)
                        ans.push_back(res[i-1][j-1] + res[i-1][j]);
                    else
                        ans.push_back(res[i-1][j-1]);
                }
                    
            }
       }
        res.push_back(ans);
        ans.clear();
            
    }
    return res[A-1];
}
