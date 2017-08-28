/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4
*/

int Solution::nTriang(vector<int> &A) {
    int N = A.size();
    if(N <= 2) return 0;
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < N; i++) {    // first side
        int k = i + 2;
        for(int j = i + 1; j < N; j++) {    // second side
            for(; (k < N) && (A[i] + A[j] > A[k]); k++);
            ans = ans + (k - 1 - j);    // all indices of between j to k are possible
            if(ans >= 1000000007) ans = ans % 1000000007;
        }
    }
    return ans;
}

