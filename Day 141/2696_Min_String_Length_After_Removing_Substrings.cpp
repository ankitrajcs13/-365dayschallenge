class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto it:s){
             if(!st.empty() &&((st.top()=='A' && it=='B') || (st.top()=='C' && it=='D')))
                st.pop();
            else
                st.push(it);
        }
        return st.size();
    }
};