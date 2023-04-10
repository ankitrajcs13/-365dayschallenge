class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('a');

        // now check
        for(auto it: s){
            // if it is the opening braces
            if(it =='(' || it == '{' || it == '['){
                st.push(it);
            }
            else if ( ( it == ')' && st.top() == '(') || (it == '}' && st.top() == '{') || (it == ']' && st.top() == '[')   )     st.pop();
            else
                return false;
        }
        if(st.size() == 1 ) return true;
        return false;
    }
};