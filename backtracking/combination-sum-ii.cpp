/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 
*/
void backTrack(int start,vector<vector<int>>& res,vector<int> &A,vector<int> temp,int& B,int sum,
    vector<int>& index)
{
    if(sum >= B)
    {
        if(sum == B)
        {
            auto it = find(res.begin(),res.end(),temp);
            if(it == res.end())
            res.push_back(temp);
            //for(int i=0;i<index.size();i++)
              //  A[index[i]] = -1;
            //index.clear();
        }
        //temp.clear();
        //index.clear();
        return;
    }
    if(start == A.size())
        return;
    //if(A[start] == -1)
      //  return;
    temp.emplace_back(A[start]);
    sum += A[start];
    index.push_back(start);
    backTrack(start+1,res,A,temp,B,sum,index);
    sum -= A[start];
    temp.pop_back();
    index.pop_back();
    backTrack(start+1,res,A,temp,B,sum,index);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> res;
    
    sort(A.begin(),A.end());
    vector<int> temp,index;
    backTrack(0,res,A,temp,B,0,index);
    sort(res.begin(),res.end());
    return res;
}
