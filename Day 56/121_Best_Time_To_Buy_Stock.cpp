class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    if(n == 0)  return 0;
    // let first element be the minimum element
    int mini = prices[0];
    int profit = 0;
    
    for(int i = 1 ; i<n; i++){
        int tCost = prices[i] - mini;
        profit = max(profit,tCost);
        mini = min(mini,prices[i]);
    }
    return profit;
    }
};