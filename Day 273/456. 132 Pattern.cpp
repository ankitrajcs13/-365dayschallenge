class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int nums_k = INT_MIN;
        stack<int>st;
        for(int i = n-1; i>=0; i--){
            if(nums[i] < nums_k) return true;

            while(!st.empty() && nums[i] > st.top()){
                nums_k = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};