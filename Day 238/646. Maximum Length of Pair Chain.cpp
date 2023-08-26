class Solution {
public:
    

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const std::vector<int>& v1, const std::vector<int>& v2) 
        {
            return v1[1] < v2[1];
        });
        int cur = INT_MIN, ans = 0;
        
        for (const auto& pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }
        
        return ans;
    }
};