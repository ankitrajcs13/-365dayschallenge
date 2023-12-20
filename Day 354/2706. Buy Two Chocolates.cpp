class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        if(prices[0] + prices[1] <= money) return money-(prices[0] + prices[1]);
        else return money;
    }
};