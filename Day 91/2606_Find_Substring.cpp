class Solution {
public:
    int solve(vector<int> & Ankitv, int an){
        int mf = INT_MIN, me = 0;
        for(int i = 0; i<an; i++){
            me = me + Ankitv[i];
            if(mf < me) mf = me;
            if(me < 0) me = 0;
        }
        return mf;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        map<char,int> ankiMp;
        char ac = 'a';
        ankiMp[ac] = 1;
        for(int i = 1; i<26; i++){
            ac++; ankiMp[ac] = i+1;
        }
        int an = chars.size();
        for(int i = 0; i<an; i++)
            ankiMp[chars[i]] = vals[i];
        vector<int> ankV;
        for(int i = 0; i<s.length(); i++){
            ankV.push_back(ankiMp[s[i]]);
        }
        int AnkiRes = solve(ankV,ankV.size());
        if(AnkiRes > 0) return AnkiRes;
        else return 0;
        
        
    }
};