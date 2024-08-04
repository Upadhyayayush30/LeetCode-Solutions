class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD=1e9+7;
        vector<int>subArraySum;
        for(int i =0;i<n;i++){
            int currSum=0;
            for(int j=i;j<n;j++){
                currSum+=nums[j];
                subArraySum.push_back(currSum);
            }
        }
        sort(subArraySum.begin(),subArraySum.end());
        long long result=0;
        for(int i=left-1;i<right;i++){
            result = (result + subArraySum[i]) % MOD;
        }
        return result;
    }
};