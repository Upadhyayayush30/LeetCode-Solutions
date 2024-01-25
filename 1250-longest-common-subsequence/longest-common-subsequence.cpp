class Solution {
public:
int lcs(int i, int j, string & text1, string & text2, vector < vector < int >> & dp) {
    if (i == 0 || j == 0) {

        return 0;
    } else if (dp[i][j] != -1) {

        return dp[i][j];
    } else if (text1[i - 1] == text2[j - 1]) {

        int length = lcs(i - 1, j - 1, text1, text2, dp) + 1;

        dp[i][j] = length;

        return length;
    } else {

        int length = max(lcs(i, j - 1, text1, text2, dp), lcs(i - 1, j, text1, text2, dp));

        dp[i][j] = length;

        return length;
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector < vector < int >> dp(n + 1, vector < int > (m + 1, -1));

        return lcs(text1.size(), text2.size(), text1, text2, dp);

    }
};

