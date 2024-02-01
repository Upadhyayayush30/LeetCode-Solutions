class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        if (size % 3 != 0)
            return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        result.reserve(size / 3);
        for (int i = 0; i < size; i += 3) {
            if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
                result.emplace_back(nums.begin() + i, nums.begin() + i + 3);
            }
            else {
                return {};
            }
        }
        return result;
    }
};
