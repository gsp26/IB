/*

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/

void combk(int start,vector<int>& A,vector<vector<int>>&res,vector<int> temp,int &k)
{
    if(start == A.size())
    {
        if(temp.size()==k)
            res.push_back(temp);
        return;
    }
    combk(start+1,A,res,temp,k);
    temp.push_back(A[start]);
    combk(start+1,A,res,temp,k);
    temp.erase(temp.begin()+temp.size()-1);
    
}

vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> A;
    for(int i=1;i<=n;i++)
        A.push_back(i);
    vector< vector<int> > res;
    if(n==1 && n == k)
    {
        res.push_back(A);
        return res;
    }
    if(k > n)
        return res;
        //return res;
    
    vector<int> temp;
    combk(0,A,res,temp,k);
    sort(res.begin(),res.end());
}
