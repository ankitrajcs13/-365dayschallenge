class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> st;
        int ans = INT_MAX;
        for(int i = x; i< nums.size(); i++){
            st.insert(nums[i-x]);

            auto it = st.upper_bound(nums[i]);

            if(it != st.end()) ans = min(ans, abs(nums[i] - *it));
            if(it != st.begin()) ans = min(ans, abs(nums[i] - *prev(it)));
        }
        return ans;
    }
};