class Solution {
public:
    bool isFascinating(int n) {
        string str = "";
        int scn = 2 * n;
        int thi = 3 * n;
        str = to_string(n) + to_string(n*2) + to_string(n*3);
        unordered_set<char> st(str.begin(), str.end());
        return ( st.size() == 9 && str.size() == 9 && st.find('0') == st.end() );
    }
};