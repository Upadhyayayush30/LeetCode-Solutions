#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
		//dp[m+1][n] -> extra row to have zero padding in first row.
        vector<vector<ll> > dp(m+1,vector<ll>(n,0));
        int curr_max = 0;
        
        for(int i = 1; i <=m; i++){
            //Explicitly handling for first column
            dp[i][0] = mat[i-1][0] + dp[i-1][0];
            
			//Taking max(choice #1, choice #2)
            for(int j = 1; j < n; j++)
                dp[i][j] = max(mat[i-1][j] + dp[i-1][j], dp[i][j-1]-1);
            
            //Explicitly handling for last column
            dp[i][n-1] = max(dp[i][n-1],mat[i-1][n-1] + dp[i-1][n-1]);
            
			//Taking max with choice #3
            for(int j = n-2; j >=0; j--)
                dp[i][j] = max(dp[i][j], dp[i][j+1]-1);
        }
        
        return *max_element(dp[m].begin(),dp[m].end());
    }
};