/*
Please Note:

There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

 Food for thought : 
* Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow. 
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them. 
Another approach is to only multiple numbers from k + 1 ... n to calculate the result. 
Obviously approach 1 is more susceptible to overflows. 
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    int xor1;   /* Will hold xor of all elements and numbers from 1 to n */
  int set_bit_no;  /* Will have only single set bit of xor1 */
  int i;
  int x = 0;
  int y = 0;
    int n = arr.size();
  xor1 = arr[0];
 
  /* Get the xor of all array elements elements */
  for(i = 1; i < n; i++)
     xor1 = xor1^arr[i];
 
  /* XOR the previous result with numbers from 1 to n*/
  for(i = 1; i <= n; i++)
     xor1 = xor1^i;
 
  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xor1 & ~(xor1-1);
 
  /* what is this */
  for(i = 0; i < n; i++)
  {
    if(arr[i] & set_bit_no)
     x = x ^ arr[i]; /* arr[i] belongs to first set */
    else
     y = y ^ arr[i]; /* arr[i] belongs to second set*/
  }
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
     x = x ^ i; /* i belongs to first set */
    else
     y = y ^ i; /* i belongs to second set*/
  }
  bool xtrue = false;
  for(int i=0;i<n;++i)
    if(arr[i] == x)
        xtrue = true;

    if(xtrue)
    {
        res.push_back(x);
  res.push_back(y);
    }
    else
    {
        res.push_back(y);
  res.push_back(x);
    }
  
  
  return res;
}
