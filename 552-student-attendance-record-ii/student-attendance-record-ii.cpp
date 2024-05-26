/*class Solution {
public:
    const long long mod=1e9+7;
    int checkRecord(int n) {
        int dp[2][2][3]={0};// C-array is fast, optimized space
        fill(&dp[0][0][0], &dp[0][0][0]+6, 1);// dp[0][j][k]=1 for all j, k
        for(int i=1; i<=n; i++){
            for(int j=0; j<=1; j++){//absent
                for(int k=0; k<=2; k++){//late
                    long long ans=dp[(i-1)&1][j][0];//P
                    ans+=(k<2?dp[(i-1)&1][j][k+1]:0);// L
                    ans+=(j==0?dp[(i-1)&1][j+1][0]:0);// A
                    dp[i&1][j][k]=ans%mod;
                }
            }
        }
        
        return dp[n&1][0][0];
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();*/
class Solution {
public:
    const long long MOD = 1e9 + 7;

    int checkRecord(int n) {
        // 3D array for dynamic programming: dp[day % 2][absent_count][consecutive_late_count]
        int dp[2][2][3] = {{{0}}};

        // Initial state for day 0: there's exactly one way to have a valid record of length 0
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                dp[0][j][k] = 1;
            }
        }

        // Loop through each day from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Loop through whether we have used an 'A' (absent) or not
            for (int j = 0; j <= 1; ++j) {
                // Loop through the number of consecutive 'L's (late)
                for (int k = 0; k <= 2; ++k) {
                    long long count = dp[(i - 1) % 2][j][0]; // Adding 'P' (present)
                    
                    if (k < 2) {
                        count += dp[(i - 1) % 2][j][k + 1]; // Adding 'L' (late)
                    }
                    
                    if (j == 0) {
                        count += dp[(i - 1) % 2][j + 1][0]; // Adding 'A' (absent)
                    }
                    
                    dp[i % 2][j][k] = count % MOD; // Take the result modulo 1e9 + 7
                }
            }
        }

        // The result is the number of valid records of length n with no 'A' and no 'L' at the end
        return dp[n % 2][0][0];
    }
};