class Solution {
public:
    int countSubstrings(string s) {
        return tabulation(s);
    }
    int tabulation(string& s) {
        vector<vector<int>> tab(s.size(), vector<int>(s.size()));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if (i == j) {
                    tab[i][j] = 1;
                } else if (i + 1 == j) {
                    tab[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    tab[i][j] = s[i] == s[j] ? tab[i+1][j-1] : 0;
                }
                count += tab[i][j];
            }
        }
        return count;
    }
};