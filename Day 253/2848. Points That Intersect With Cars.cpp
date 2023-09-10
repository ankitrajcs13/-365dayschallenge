class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int>ankist;
        for(auto& it:nums){
            int a1 = it[0], a2 = it[1];
            for(int i = a1; i<=a2; i++) ankist.insert(i);
            
        }
        return ankist.size();
    }
};