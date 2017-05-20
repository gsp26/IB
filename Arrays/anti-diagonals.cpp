/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int> > result;
    int l = -1;
    int i = 0;
    int c = 0;
    
    int r = 0;
    int col = 0;
    for (auto j = 0; j<n; ++j)
    {
        i = 0;
        ++l;
        result.emplace_back();
        result[l].emplace_back(A[i][j]);
        c = j;
        while (c>0)
        {
            --c;
            result[l].emplace_back(A[i+1][c]);
            ++i; 
        }
    }
    for (auto x = 1; x<n; ++x)
    {
        r = x;
        ++l;
        result.emplace_back();
        result[l].emplace_back(A[x][n-1]);
        col = n-1;
        while (r<n-1)
        {
            result[l].emplace_back(A[r+1][col-1]);
            ++r; --col;
        }
    }
    return result;
}
