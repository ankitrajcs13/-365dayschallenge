class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;

        int maxi = INT_MIN;
        for(int i = 0; i < candies.size(); i++)
            maxi = max(maxi, candies[i]);
        
        for(auto it: candies){
            if(it + extraCandies >= maxi){
                res.push_back(true);
            }
            else
                res.push_back(false);
        }
        return res;
    }
};