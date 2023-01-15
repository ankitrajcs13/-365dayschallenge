class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ecnt = 0,dcnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            ecnt+= nums[i];
            if(nums[i] > 9){
                int temp = nums[i];
                while(temp != 0){
                    int digit = temp % 10;
                    dcnt += digit;
                    temp = temp/10;
                }
            }
            else{
                dcnt +=nums[i];
            }
        }
        int ddiff = abs(ecnt - dcnt);
        return ddiff;
    }
};
// TC - O(N)
// SC - O(1)