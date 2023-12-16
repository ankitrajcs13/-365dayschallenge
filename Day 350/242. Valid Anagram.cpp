class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case
        if(s.length() != t.length()) return false;
        map<char,int>st;
        for(auto it:s){
            st[it]++;
        }
        for(auto it:t){
            if(st.find(it) == st.end() || st[it] == 0) return false;
            st[it] = st[it] - 1;
        }
        return true;
    }
};