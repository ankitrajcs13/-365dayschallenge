class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

     vector<vector<string>> res;
     void solve(int st, string s, vector<string>tmp){
         //base case
         if(st == s.size()){
             res.push_back(tmp);
         }

         for(int i = st; i<s.length(); i++){
             if(isPalindrome(s,st,i)){
                 tmp.push_back(s.substr(st,i-st+1));
                 solve(i+1,s,tmp);
                 tmp.pop_back();
             }
         }
     }
    vector<vector<string>> partition(string s) {
        vector<string>tmp;
        solve(0,s,tmp);
        return res;
    }
};