class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> res[n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[j] - nums[i];
                int cnt = 1;
                
                if(res[j].count(diff)) cnt = res[j][diff];
                res[i][diff] = 1 + cnt;
                ans = max(ans,res[i][diff]);
            }
        }
        return ans;
    }
};