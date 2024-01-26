/*class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        const int M = 1000000000 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[x][y] = 1;
        int count = 0;

        for (int moves = 1; moves <= N; moves++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;

                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M
                    ) % M;
                }
            }
            dp = temp;
        }

        return count;
    }
};*/

class Solution {
public:
    // Helper function to check if a cell is within the boundary of the grid
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // Recursive function with memoization
    int dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& memo) {
        // Base case: if we are out of moves, return 0 (no more paths)
        if (N == 0) {
            return 0;
        }

        // Check if the result for this state is already memoized
        if (memo[N][i][j] != -1) {
            return memo[N][i][j];
        }

        // Array to represent possible moves in four directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int count = 0;

        // Explore all four directions
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            // If the next cell is outside the boundary, it contributes to the path count
            if (!isValid(ni, nj, m, n)) {
                count++;
            }
            // If the next cell is within the boundary, recursively explore it
            else {
                count = (count + dfs(m, n, N - 1, ni, nj, memo)) % 1000000007;
            }
        }

        // Memoize the result for this state
        memo[N][i][j] = count;

        return count;
    }

    // Main function to initialize the recursive DFS with memoization
    int findPaths(int m, int n, int N, int x, int y) {
        // Initialize the memoization table with -1
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));

        return dfs(m, n, N, x, y, memo);
    }
};


