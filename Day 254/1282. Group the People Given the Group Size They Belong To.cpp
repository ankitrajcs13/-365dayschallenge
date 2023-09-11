zclass Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        vector<vector<int>> mp(n+1);
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++) {
            
            int l = groupSizes[i];
            
            mp[l].push_back(i);
            
            if(mp[l].size() == l) {
                result.push_back(mp[l]);
                mp[l] = {};
            }
            
        }
        
        return result;
        
    }
};