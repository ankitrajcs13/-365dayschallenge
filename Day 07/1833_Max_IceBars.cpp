class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int ans = 0;
        // sort the array to calculate easily
        sort(costs.begin(),costs.end());
        for(int i = 0; i<costs.size(); i++){
            // to check if we can buy that icecream from the coins or not
            if(costs[i] <= coins){
                // if yes, then incremenet the ans and reduce the cost of 
                // ice-cream from our coins
                ans++;
                coins -=costs[i];
            }
        }
        return ans;

    }
};

// TC- O(NlogN)
// SC- O(1)