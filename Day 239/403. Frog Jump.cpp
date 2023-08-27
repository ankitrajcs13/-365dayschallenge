class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>mp;
        mp[1]= {1};
        int n = stones.size();
        for(int i = 1; i<n; i++){
            for(auto it:mp[stones[i]]){
                mp[stones[i] + it-1].insert(it-1);
                mp[stones[i] + it].insert(it);
                mp[stones[i] + it+1].insert(it+1);
            }
        }
        return mp[stones.back()].size()!= 0;
    }
};