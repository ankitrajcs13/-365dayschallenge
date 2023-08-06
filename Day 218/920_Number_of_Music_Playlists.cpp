// 1st Appraoch

class Solution {
public:
    int mod = 1e9 + 7;
    long long solve(int n, int goal, int k,vector<vector<int>>& dp){
        // base case
        if(n == 0 && goal == 0) return 1;
        if(n == 0 || goal == 0 ) return 0;
        
        if(dp[n][goal] != -1) return dp[n][goal];

        long long pick = solve(n-1,goal-1,k,dp) * n % mod;
        long long npick = solve(n,goal-1,k,dp) * max(0, n-k) % mod;

        return dp[n][goal] = (pick + npick) % mod;

    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1,vector<int>(goal+1,-1));

        return solve(n,goal,k,dp);
    }
};

// 2nd Approach

# define ll long long int

class Solution {
public:
    ll dp[101][101];
    int mod = 1e9 + 7;
    int N, G,k;

    ll solve(int used, int currL){
        if(currL == G)
            return used == N;
        //memorisation
        if(dp[used][currL] != -1) return dp[used][currL];

        ll newPlay = (solve(used+1, currL+1) * (N-used))% mod;
        ll usedPlay = (solve(used, currL+1) * max(used-k,0))% mod;
        ll t = (newPlay + usedPlay) % mod;
        return dp[used][currL] = t % mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->N = n;
        this->G = goal;
        this->k = k;
        memset(dp, -1, sizeof(dp));
        return (int)solve(0,0);
    }
};