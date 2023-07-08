class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = -1; 
        for(int i =0; i<nums.size(); i++){
            int ankicnt = 1, fl = 0;
            
            for(int j = i+1; j<nums.size(); j++){
                if(fl == 0 && nums[j] == nums[i] + 1){
                    ankicnt++;
                    fl=1;
                }
                else if(fl == 1 && nums[i] == nums[j]) 
                    ankicnt++, fl = 0;
                else break;
            }
            if(ankicnt > 1)
                res = max(res,ankicnt);
            
        }
        return res;
    }
};