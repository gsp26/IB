/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
 */
 
 vector<int> Solution::lszero(vector<int> &A) {
    
    map<int,int> presum;
    int sum = 0;
    int maxlen = -1;
    int l=-1,r=-1;
    for(int i=0;i<A.size();i++)
    {
        sum +=A[i];
        if(A[i] == 0 && l==-1)
        {
            l = i;
            r=i;
            if(1>maxlen)
                maxlen = 1;
        }
        if(sum == 0)
        {
            if(i+1 > maxlen)
            {
                maxlen = i+1;
                l = 0;
                r = i;
            }
        }
        
        if(presum.find(sum) != presum.end())
        {
            int len = i-presum[sum];
            if(len > maxlen)
            {
                maxlen = len;
                l = presum[sum]+1;
                r = i;
            }
            
        }
        else
            presum[sum] = i;
    }
    vector<int> res;
    if(l==-1 || r== -1)
        return res;;
    
    for(int i=l;i<=r;i++)
        res.push_back(A[i]);
    return res;
}
