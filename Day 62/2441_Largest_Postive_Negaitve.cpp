class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> m;

        for(auto i:nums)
            m[i]++;
        
        int res = INT_MIN;
        bool chk = false;

        for(int i = 0; i<nums.size(); i++){
            // if any positive value is encountered
            if(nums[i] > 0){
                // then find for its negative value in the map
                if(m.find(0-nums[i]) != m.end()){
                    res = max(res,nums[i]);
                    chk = true;
                }
            }
        }
        if(chk) return res;
        else return -1;
    }
};