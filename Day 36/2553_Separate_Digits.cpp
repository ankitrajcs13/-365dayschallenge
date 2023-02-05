class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 9){
                int n = nums[i];
                vector<int> tmp;
                while(n != 0){
                    int digit = n % 10;
                    tmp.push_back(digit);
                    n = n/10;   
                }
                reverse(tmp.begin(),tmp.end());
                for(int i = 0; i<tmp.size(); i++){
                    ans.push_back(tmp[i]);
                }
            }
            else
                ans.push_back(nums[i]);
        }
        return ans;

    }
};