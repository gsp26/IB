void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, unordered_map<int,int>& m){
    if(temp.size()==nums.size()){
        res.emplace_back(temp);
        return;
    }
    for(int i=0; i<nums.size(); i++){
        if(m[nums[i]]>0){
            if(i&&nums[i]==nums[i-1]) continue;
            temp.emplace_back(nums[i]);
            m[nums[i]]--;
            helper(res, temp, nums, m);
            m[nums[i]]++;
            temp.pop_back();
        }
    }
}
 
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    unordered_map<int,int> m;
    for(auto n:nums) m[n]++;
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, nums, m);
    return res;
}
 
vector<vector<int> > Solution::permute(vector<int> &A) 
{
    return permuteUnique(A);
    
}

void solve(vector<int> num,int l , int r, vector<vector<int>>& res){
        if(l==r){
            res.push_back(num);
            return;
        }
        for(int i = l;i <=r;i++){
            if(i != l && num[i] == num[l])continue;
            swap(num[i],num[l]);
            solve(num,l+1,r,res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        solve(nums,0,nums.size()-1,res);
        return res;
    }
