/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be give 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*/

int gcd (int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(a*-1, b);
    if (b < 0) return gcd(a, b*-1);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ans = 0;
    map<pair<int, int>, int> M;
    
    for (auto i = 0; i<A.size(); ++i)
    {
        M.clear();
        int same = 1, currMax = 0; //same = 1 to handle case when there is only 1 point (X,Y).
        for (auto j = i+1; j<A.size(); ++j)
        {
            auto diffX = A[i] - A[j];
            auto diffY = B[i] - B[j];
            
            if (diffX == 0 && diffY == 0)
            {
                ++same;
                continue;
            }
            
            if (diffX < 0)
            {
                diffX *= -1;
                diffY *= -1;
            }
            
            int g = gcd(diffX, diffY);
            M[make_pair(diffX/g, diffY/g)]++;
            currMax = max(currMax, M[make_pair(diffX/g, diffY/g)]);
        }
        currMax += same;
        ans = max(currMax, ans);
    }
    return ans;
}
