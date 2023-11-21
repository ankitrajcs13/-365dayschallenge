class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;
        aheadBuy = aheadNotBuy = 0;

        for(int ind = n-1; ind>=0; ind--){
            // sell
            currNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);
            //buy
            currBuy = max(-prices[ind] - fee + aheadNotBuy, 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};