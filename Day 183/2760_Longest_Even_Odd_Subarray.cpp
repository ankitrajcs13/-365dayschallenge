class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        //edge case
        int a = nums.size();
        if(a == 1){
            if(nums[0] % 2 == 0 && nums[0] <= threshold) return 1;
            else return 0;
        }
        
        int ankiMaxi = 0, ankiCnt = 0, ankiG = 0;
        
        for(int i = 0; i<a-1; i++){
            if(nums[i] %2 == 0){
                if(nums[i] <= threshold){
                    if(1 > ankiMaxi) ankiMaxi =1;
                }
                for(int j = i; j<a-1; j++){
                    if(nums[j]%2 != nums[j+1]%2){
                        if(nums[j] <=threshold && nums[j+1]<=threshold){
                            ankiCnt++;
                            ankiG = 1;
                            if(ankiCnt > ankiMaxi) ankiMaxi = ankiCnt;
                        }
                        else break;
                    }
                    else break;
                }
            }
            ankiCnt = 0;
        }
        
        if(ankiMaxi >0 && ankiG == 1) return ankiMaxi+1;
        else if(ankiMaxi == 1) return 1;
        else if(nums[a-1]%2 == 0 && nums[a-1] <= threshold) return 1;
        else return 0;
    }
};