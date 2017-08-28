/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/

void backTrack(int start,vector<vector<int>>& res,vector<int>&A,vector<int> temp)
{
    if(start >= A.size())
    {
        auto it = find(res.begin(),res.end(),temp);
        if(it == res.end())
            res.push_back(temp);
        return;
    }
    
    
    backTrack(start+1,res,A,temp);
    temp.emplace_back(A[start]);
    backTrack(start+1,res,A,temp);
    temp.pop_back();
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> res;
    vector<int> temp;
    sort(A.begin(),A.end());
    backTrack(0,res,A,temp);
    sort(res.begin(),res.end());
    return res;
}
