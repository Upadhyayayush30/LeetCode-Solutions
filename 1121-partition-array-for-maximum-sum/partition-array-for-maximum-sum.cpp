class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> maxVals(n, 0);

        for (int i = 0; i < n; ++i) {
            int maxVal = 0;

            for (int j = 1; j <= min(k, i + 1); ++j) {
                maxVal = max(maxVal, arr[i - j + 1]);
                maxVals[i] = max(maxVals[i], (i - j < 0 ? 0 : maxVals[i - j]) + maxVal * j);
            }
        }

        return maxVals[n - 1];
    }
};
