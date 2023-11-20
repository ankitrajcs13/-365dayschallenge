class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>after(2*k+1,0);
        vector<int>curr(2*k+1,0);
        for(int ind = n-1; ind>=0; ind--){
            for(int trans = 2 * k -1; trans>=0; trans--){
                
                if(trans % 2 == 0){
                    curr[trans] = max( -prices[ind] + after[trans+1], 0 + after[trans]);
                }
                else
                    curr[trans] = max( prices[ind] +after[trans+1] , 0 + after[trans]);
            }
            after = curr;
        }
        return curr[0];
    }
};