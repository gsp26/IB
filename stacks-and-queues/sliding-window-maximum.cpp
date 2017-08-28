/*
A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. You have to find the maximum for each window. The following example will give you more clarity.

Example :

The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
 	 
[1 3 -1] -3 5 3 6 7	3
1 [3 -1 -3] 5 3 6 7	3
1 3 [-1 -3 5] 3 6 7	5
1 3 -1 [-3 5 3] 6 7	5
1 3 -1 -3 [5 3 6] 7	6
1 3 -1 -3 5 [3 6 7]	7
Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

 Note: If w > length of the array, return 1 element with the max of the array. */
 
 vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    queue<int> slider;
    vector<int> res;
    int maxInd = 0;
    auto l = A.size();
    
    if (B >= l)
    {
        auto maxEle = *max_element(A.begin(), A.begin()+l);   
        return { maxEle };
    }
    
    for (auto i = 0; i<B; ++i)
    {
        slider.push(A[i]);
        if (A[i] > A[maxInd])
            maxInd = i;
    }
    res.push_back(A[maxInd]);
    
    for (auto j = B; j<l; ++j)
    {
        if (slider.front() == A[maxInd])
        {
            maxInd = j;
            for (auto k = (j-B+1); k<j+1; ++k)
            {
                if (A[k] > A[maxInd])
                    maxInd = k;
            }
        }
        else if (A[j] > A[maxInd])
            maxInd = j;
        slider.pop();
        slider.push(A[j]);
        res.emplace_back(A[maxInd]);
    }
    return res;
}
