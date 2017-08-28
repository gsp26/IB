/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int i = 0, j = 1;
    int sum, flag = 0;
    vector<vector<int> >sol;
    if(A.size() < 4){
        return sol;
    }
    sort(A.begin(), A.end());
    
    while(i < A.size()-3){
        j = i+1;
        while(j < A.size()-2){
            int num = B - (A[i]+A[j]);
            int k = j+1;
            int l = A.size()-1;
            while(k < l){
                int sum = A[k]+A[l];
                if(sum == num){
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[k]);
                    temp.push_back(A[l]);
                    sol.push_back(temp);
                    temp.erase(temp.begin(), temp.end());
                    while(A[k] == A[k+1] && k < A.size()-1){
                        k++;
                    }
                    while(A[l] == A[l-1] && l > 0){
                        l--;
                    }
                    k++;
                    l--;
                }
                else if(sum < num){
                    k++;
                }
                else{
                    l--;
                }
            }
            while(A[j] == A[j+1]){
                j++;
            }
            j++;
        }
        while(A[i] == A[i+1]){
            i++;
        }
        i++;
    }
    
    return sol;
}
