22. Generate Parentheses || Backtracking

03 August 2023
22:35




class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i = 0;i<s.length(); i++){
            if(s[i] == '(') 
                st.push('(');
            else{
                if(!st.empty()) st.pop();
                else return false;
            }
        }
        if(st.size() == 0) return true;
        return false;
    }

    void solve(int n1, int n2, string tmp, vector<string> & ans){
        // base case 
        if(n1 == 0 && n2 == 0){
            if(isValid(tmp)){
                ans.push_back(tmp);
            }
            else return;
        }
        // Recursive calls
        if(n1 != 0){
            tmp.push_back('(');
            solve(n1-1,n2,tmp,ans);
            tmp.pop_back();
        }
        if(n2 != 0){
            tmp.push_back(')');
            solve(n1,n2-1,tmp,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,"", ans);
        return ans;
    }
};
