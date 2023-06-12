class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        for(int i = 0; i<nums.size(); i++){
            int st = nums[i];

            while(i + 1 < nums.size() &&  nums[i] + 1 == nums[i+1]   ) i++;

            if(st != nums[i]) res.push_back(to_string(st)+"->" + to_string(nums[i]));
            else res.push_back(to_string(st));
        }
        return res;
    }
};