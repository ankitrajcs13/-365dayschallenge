class Solution {
public:
    vector<string> Keys = {"","", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv","wxyz"};
    void solve(string tmp, string digits,int st,vector<string>& ans){
        // base case
        if(st>= digits.length()){
            ans.push_back(tmp);
        }
        else{
            string l = Keys[digits[st]-'0']; // to get each character of typed string
            // like if digit is 2 then l will store "abc"
            // n then for each element of abc, it will call recursive calls
            for(char it:l){
                solve(tmp+it,digits,st+1,ans);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        solve("", digits,0,ans);
        return ans;
    }
};