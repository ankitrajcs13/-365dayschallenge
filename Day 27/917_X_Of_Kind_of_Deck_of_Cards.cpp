class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        // storing the occurence of all the elements
        for(auto i: deck)
            mp[i]++;  
        int g = mp[deck[0]];
        for(auto x: mp)
        // to find gcd of all the counts
            g = gcd(g,x.second);
        
        if(g>1)
            return true;
        else
            return false;
    }
};
// TC- O(N)
// SC - O(N)