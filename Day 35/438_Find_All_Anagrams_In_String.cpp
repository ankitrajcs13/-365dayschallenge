class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();

        if(s.size() < p.size()) return {};

        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<n2;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) ans.push_back(0);
        
        for(int i=n2;i<n1;i++){
            window[s[i-n2] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) ans.push_back(i-n2+1);
        }
        return ans;

    }
};
// TC - O(N)
// SC - O(1)