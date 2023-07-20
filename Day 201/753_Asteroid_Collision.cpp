class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i<asteroids.size(); i++){
            if(st.empty() || asteroids[i] > 0)
                st.push(asteroids[i]);
            else{// it means that the asteroid is moving left
                // we will pop the element till the top element is smaller than the ith asteroid(which is moving left)
                while(!st.empty() && st.top() > 0 &&  st.top() < abs(asteroids[i]))  st.pop();
                // when both have same size, both will explode
                if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
                else{
                    // when the top of stack is having a negative value and the new element is also negative,
                    // then just simply push that element
                    if(st.empty() || st.top() < 0) st.push(asteroids[i]);
                }
            
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};