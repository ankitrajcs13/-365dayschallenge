class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int ankiRes = 0;
        
        while(!nums.empty()){
            int maxD = INT_MIN;
            
            for(int i = 0; i<nums.size(); i++){
                if(!nums[i].empty()){
                    int tmpAMaxi = *max_element(nums[i].begin(), nums[i].end());
                    // updating max of a row
                    maxD = max(maxD, tmpAMaxi);
                    nums[i].erase(find(nums[i].begin(),nums[i].end(), tmpAMaxi));
                    
                    if(nums[i].empty()){
                        nums.erase(nums.begin() + i);
                        i--;    
                    }
                }
            }
            
            ankiRes += maxD;
        }
        return ankiRes;
        
    }
};