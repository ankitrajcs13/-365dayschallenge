class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> st;

        for(auto it: s){
            st.insert(it);
        }
        return st.size();

    }
};


// One Liner

class Solution {
public:
    int minimizedStringLength(string s) {
        return unordered_set<char>(s.begin(), s.end()).size();
    }
};