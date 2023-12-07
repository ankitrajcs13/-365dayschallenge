class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        if(n == 1)return 1;
        vector<int>c(26,0);
        int maxi = 1;
        for(int i = 0;i<n;i++){
            if(c[s[i]-'a']==0){
                c[s[i] - 'a'] = maxi;
            }else{
                c[s[i] - 'a'] = max(maxi, c[s[i] - 'a']);
            }
            if(i+1 < n && (s[i] == 'z' && s[i+1] == 'a')|| s[i+1]==s[i]+1)maxi++;
            else maxi = 1;
        }
        int ans = 0;
        for(auto it : c){
            ans += it;
        }
        return ans;
    }
};