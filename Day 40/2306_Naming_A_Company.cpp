class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // to store the diff strings
        unordered_set<string> st1(ideas.begin(), ideas.end());
        long long ans = 0;
        unordered_map<char, unordered_map<char, int> > m;

        for(auto str: st1){
            string s = str;
            char prev = s[0];
            for(char c = 'a'; c<='z'; c++){
                s[0] = c;
                if(st1.find(s) == st1.end())
                    m[c][prev]++;
            }
        }
        for(auto & str: st1){
            string s = str;
            char prev = s[0];
            for(char c = 'a'; c<='z'; c++){
                s[0] = c;
                if(st1.find(s) == st1.end())
                    ans+= m[prev][c];
            }
        }
        return ans;
    }
};
// TC - O(N*M)
// SC - O(26*N)

// IN worst case it can have 