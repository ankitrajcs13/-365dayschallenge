class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, curBuy, curNotBuy;
        aheadBuy = aheadNotBuy = 0;

        for(int i = n-1; i>=0; i--){
            // sell
            curNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);

            // buy
            curBuy = max(-prices[i] - fee+ aheadNotBuy, aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;

    }
};

// TC - O(N)
// SC - O(1)

// Space Optimised

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int free = 0, hold = -prices[0];

        for(int i = 1; i<n; i++){
            int tmp = hold;
            hold = max(hold,free-prices[i]);
            free = max(free,tmp+prices[i]-fee);
        }
        return free;
    }
};