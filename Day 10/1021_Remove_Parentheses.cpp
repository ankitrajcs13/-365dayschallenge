// 1st Approach - Using Stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        string ans;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                // this means that stack is not empty, so that we are skipping the first element
                if(st.size()> 0){
                    ans +='(';
                }
                st.push('(');
            }
            else{
                // this conditions will skip the last closing bracket
                if(st.size() > 1){
                    ans += ')';
                }
                st.pop();
            }
        }
        return ans;


    }
};

// TC - O(N)
// SC - O(N)

// 2nd Approach -> Without stack

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int cnt = 0;
        string ans;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                // this means that stack is not empty, so that we are skipping the first element
                if(cnt > 0){
                    ans +='(';
                }
                cnt++;
            }
            else{
                // this conditions will skip the last closing bracket
                if(cnt > 1){
                    ans += ')';
                }
                cnt--;
            }
        }
        return ans;
    }
};
// TC - O(N)
// SC - O(1)