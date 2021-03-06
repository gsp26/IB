/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/
vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<long, vector<int> > results;
    vector<int> arr;
    long sum = 0;
    long maxSum = 0;
    //cout << A.size() << endl;
    //for(int i=0;i<A.size();++i)
    //            std::cout << A[i] << " ";
    for(int i=0;i<A.size();++i)
    {
        if(A[i] >= 0)
        {
            sum += A[i];
            if(sum >= maxSum)
                maxSum = sum;
            arr.push_back(A[i]);
            //for(int i=0;i<arr.size();++i)
              //  std::cout << arr[i] << " ";
            //std::cout << "\n";
        }
        else
        {
            map<long,vector<int> >::iterator it = results.find(sum);
            if(it != results.end())
            {
                //std::cout << "Found" << std::endl;
                if(arr.size() > it->second.size())
                    results[sum] = arr;
            }
            else
                results[sum]  = arr;
            arr.clear();
            sum = 0;
        }
    }
    map<long,vector<int> >::iterator it = results.find(sum);
            if(it != results.end())
            {
                //std::cout << "Found" << std::endl;
                if(arr.size() > it->second.size())
                    results[sum] = arr;
            }
            else
                results[sum]  = arr;
    return results[maxSum];
}
