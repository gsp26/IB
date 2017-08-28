/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

*/
// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;    
    
    int i = 0, j = 0, temp_st = -1, temp_end = -1, temp_count = 0;
    int ov_st = -1, ov_end = -1, ov_count = 0;
    
    int temp = B;
    
    while(j < A.size()){
        if(A[j] == 1){
            temp_count++;
            if(temp_count == 1){
                temp_st = j;
            }
            temp_end = j;
            j++;
        }    
        else{
            temp--;
            if(temp < 0){
                int t_c = 1;
                while(A[i] == 1){
                    i++;
                    t_c++;
                }
                i++;
                temp_count = temp_count - t_c + 1;
                temp = 0;
                temp_st = i;
                temp_end = j;
            }
            else{
                temp_count++;
                if(temp_count == 1){
                    temp_st = j;
                }
                temp_end = j;
            }
            j++;
        }
        if(ov_count == 0){
            ov_count = temp_count;
            ov_st = temp_st;
            ov_end = temp_end;
        }
        else{
            if(ov_count < temp_count){
                ov_count = temp_count;
                ov_st = temp_st;
                ov_end = temp_end;
            }
        }
    }
    
    if(ov_count != 0){
       for(int t = ov_st; t <= ov_end; t++){
           sol.push_back(t);
       }
    }
    
    return sol;
}
