class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int fl = 0;
        for (int i : pushed) {
            st.push(i);
            while (!st.empty() && st.top() == popped[fl]) {
                st.pop();
                fl++;
            }
        }
        return st.empty();
    }
};