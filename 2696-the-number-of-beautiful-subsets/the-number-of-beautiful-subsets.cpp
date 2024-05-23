class Solution {
public:
    int result;
    int K;
    void solve(int idx, vector<int>&nums, unordered_map<int , int>&mp){
        if(idx>=nums.size()){
            result++;
            return;
        }

        //not take 
        solve(idx+1,nums,mp);

        //take
        if(!mp[nums[idx]-K] && !mp[nums[idx]+K]){
            mp[nums[idx]]++;//do
            solve(idx+1,nums,mp);//explore
            mp[nums[idx]]--;//undo
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        result=0;
        K=k;
        unordered_map<int,int>mp;
        solve(0,nums,mp);
        return result-1;//excluding empty set

    }


};