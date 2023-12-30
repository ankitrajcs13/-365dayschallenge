class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n == 1) return true;
        map<char,int>mp;
        for(int i = 0; i<words.size(); i++){
            for(auto it:words[i]){
                mp[it]++;
            }
        }
        int tsum = 0;
        for(auto it:mp){
            if(it.second % n != 0) return false;
        }
        return true;
    }
};