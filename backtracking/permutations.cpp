/*

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/

void swap(vector<int> &s,int a,int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void permute1(vector<int> s,int l , int r,vector<vector<int>>& res)
{
    //results.push_back(s.substr(l,r-l+1));
    if(l==r)
    {
        //cout << s << endl;
        res.push_back(s);
        //count++;
    }
    else
    {
        for(int i=l;i<=r;++i)
        {
            swap(s,l,i);
            permute1(s,l+1,r,res);
            swap(s,l,i);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &s) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int>> res;
    permute1(s,0,s.size()-1,res);
    return res;
    
}
