class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int sz = st.size();
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            set<int> tmp;
            for(int j = i; j<nums.size(); j++){
                tmp.insert(nums[j]);
                if(tmp.size()== sz) cnt++;
            }
        }
        return cnt;
    }
};