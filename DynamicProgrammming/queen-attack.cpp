/*
On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). While calculating answer for cell (i, j), assume there is no queen at that cell.

Notes:

Queen is able to move any number of squares vertically, horizontally or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity is worst case O(N*M).
For example,

Let chessboard be,
[0 1 0]
[1 0 0]
[0 0 1]

where a 1 denotes a queen at that position.

Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
and so on...

Finally, we return matrix
[3, 1, 2]
[1, 3, 3]
[2, 3, 0]

*/
//dp array
vector<vector<int> > dp[8];

//checks if cell (i, j) is valid or not
bool valid(int i, int j, int n, int m){
    if(i < 0 or i >= n or j < 0 or j >= m)return false;
    return true;
}

//direction vectors
int dir1[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir2[8] = {0, 1, 1, 1, 0, -1, -1, -1};

//returns dp(i, j, k) as defined in hint
int rec(int i, int j, int k, vector<string> & A, int n, int m){

    //memoisation
    int &ret = dp[k][i][j];
    if(ret != -1)return ret;
    
    ret=0;
    
    //new positions
    int ni = i + dir1[k];
    int nj = j + dir2[k];
    
    //if valid
    if(valid(ni, nj, n, m)){
        if(A[ni][nj] == '1') ret++;
        else ret += rec(ni, nj, k, A, n, m);
    }
    
    return ret;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    //init dp array
    int n = A.size(), m = A[0].size();
    for(int i = 0; i < 8; i++){
        dp[i].clear();
        dp[i].resize(n, vector<int>(m, -1));
    }

    vector< vector<int> > ret(n, vector<int>(m, 0));

    //calculate dp for all positions
    for(int k = 0; k < 8; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                ret[i][j] += rec(i, j, k, A, n, m);
            }
    return ret;
}
