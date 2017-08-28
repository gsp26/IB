/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.



The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValidSudoku(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<map<int,bool>> row(9);
    vector<map<int,bool>> col(9);
    vector<map<int,bool>> grid(9);
    for(int i=0;i<A.size();++i)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j] == '.')
                continue;
            else
            {
                if(row[i].find(A[i][j])!= row[i].end())
                    return 0;
                else
                    row[i][A[i][j]] = true;
                if(col[j].find(A[i][j]) != col[j].end())
                    return 0;
                else
                    col[j][A[i][j]] = true;
                if(i<3 && j < 3)//first grid
                {
                    if(grid[0].find(A[i][j]) != grid[0].end())
                        return 0;
                    else
                        grid[0][A[i][j]] = true;
                }
                if(i<3 && j < 6 && j >2)//2nd grid
                {
                    if(grid[1].find(A[i][j]) != grid[1].end())
                        return 0;
                    else
                        grid[1][A[i][j]] = true;
                }
                if(i<3 && j < 9 && j >5)//2nd grid
                {
                    if(grid[2].find(A[i][j]) != grid[2].end())
                        return 0;
                    else
                        grid[2][A[i][j]] = true;
                }
                 if(i<6 && i >2 && j < 3)//first grid
                {
                    if(grid[3].find(A[i][j]) != grid[3].end())
                        return 0;
                    else
                        grid[3][A[i][j]] = true;
                }
                if(i<6 && i >2 && j < 6 && j >2)//2nd grid
                {
                    if(grid[4].find(A[i][j]) != grid[4].end())
                        return 0;
                    else
                        grid[4][A[i][j]] = true;
                }
                if(i<6 && i >2 && j < 9 && j >5)//2nd grid
                {
                    if(grid[5].find(A[i][j]) != grid[5].end())
                        return 0;
                    else
                        grid[5][A[i][j]] = true;
                }
                 if(i<9 && i >5 && j < 3)//first grid
                {
                    if(grid[6].find(A[i][j]) != grid[6].end())
                        return 0;
                    else
                        grid[6][A[i][j]] = true;
                }
                if(i<9 && i >5 && j < 6 && j >2)//2nd grid
                {
                    if(grid[7].find(A[i][j]) != grid[7].end())
                        return 0;
                    else
                        grid[7][A[i][j]] = true;
                }
                if(i<9 && i >5 && j < 9 && j >5)//2nd grid
                {
                    if(grid[8].find(A[i][j]) != grid[8].end())
                        return 0;
                    else
                        grid[8][A[i][j]] = true;
                }
            }
        }
    }
    return 1;
}
