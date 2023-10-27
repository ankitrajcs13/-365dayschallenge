class Solution {
private:
    int m,t;
    vector<vector<int>> dp;
    bool game(int mask,int player,int score){
        if(dp[player][mask]!=-1) return dp[player][mask];
        for(int i=0;i<m;i++)
        {
            int cmask = 1<<i;
            if( (mask&cmask) == 0 )
                    if(score+i+1 >= t or game((mask|cmask),(player^1),score+i+1)==false ) return dp[player][mask]=1;
        }
        return dp[player][mask]=0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;
        t=desiredTotal;
        if((m*(m+1))/2 < t) return false;
        dp.resize(2,vector<int>(1<<m,-1));
        return game(0,0,0);
    }
};