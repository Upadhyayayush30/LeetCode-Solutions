class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        for (int c1 = 0; c1 < n; c1++) {
            std::vector<int> rowSum(m, 0);

            for (int c2 = c1; c2 < n; c2++) {
                for (int row = 0; row < m; row++) {
                    rowSum[row] += matrix[row][c2];
                }

                count += countSubarraySum(rowSum, target);
            }
        }

        return count;
    }

private:
    int countSubarraySum(std::vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumCount;

        prefixSumCount[0] = 1;

        for (int num : nums) {
            sum += num;
            count += prefixSumCount[sum - target];
            prefixSumCount[sum]++;
        }

        return count;
    }
};
