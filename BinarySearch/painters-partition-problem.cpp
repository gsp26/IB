int getMax(vector<int>& arr)
{
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++)
        if(arr[i]> max)
            max = arr[i];
    return max;
}

int getSum(vector<int>& arr)
{
    int total = 0;
    for(int i=0;i<arr.size();i++)
        total += arr[i];
    return total;
}

int nop(vector<int>& arr,int maxLen)
{
    int total = 0, res = 1;
    for(int i=0;i<arr.size();i++)
    {
        total += arr[i];
        if(total > maxLen)
        {
            total = arr[i];
            res++;
        }
    }
    return res;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long lo = getMax(C);
    long hi = getSum(C);
    
    while(lo < hi)
    {
        int mid = lo + (hi-lo)/2;
        int rp = nop(C,mid);
        
        if(rp <= A)
            hi = mid;
        else
            lo = mid+1;
    }
    return (lo*B)%10000003;
}


