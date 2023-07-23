class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ankiRes= 0;
        
        vector<long long> tmp(nums.begin(), nums.end());
        
        for(int i = tmp.size()-1; i>0; i--){
            if(tmp[i-1] <= tmp[i]){
                tmp[i-1] = tmp[i]+ tmp[i-1];
            }
        }
        ankiRes = *max_element(tmp.begin(), tmp.end());
        return ankiRes;
        
    }
};