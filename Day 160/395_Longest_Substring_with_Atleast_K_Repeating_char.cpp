class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto it: s) mp[it]++;

        int idx = 0 ;
        while(idx < n && mp[s[idx]] >= k) idx++;

        if(idx == n) return n;
        int lft = longestSubstring(s.substr(0,idx),k);
        int rt = longestSubstring(s.substr(idx+1,n-1), k);
        return max(lft,rt);
    }
};