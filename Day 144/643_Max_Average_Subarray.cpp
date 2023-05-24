class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        int ans = INT_MIN;
        
        int start = 0, end=0;

        while(end<nums.size()){
           
            sum+=nums[end];

            if( (end - start + 1)==k){
                ans = max(sum,ans);
                sum -= nums[start];
                start++;
            }

            end++;
            
        }
        return ((double)ans/k);
    }
};