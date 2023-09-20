class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), i = 0, j = 0, maxi = 0, total_sum = 0;
        for(auto it : nums)
            total_sum += it;
        if(total_sum < x)
            return -1;
        if(total_sum == x)
            return n;
        int req_sum = total_sum - x, curr_sum = 0;
        while(j < n){
            curr_sum += nums[j];
            while(curr_sum > req_sum)
                curr_sum -= nums[i++];
            if(curr_sum == req_sum)
                maxi = max(maxi, j - i + 1);
            j++;
        }
        return (maxi != 0) ? n - maxi : -1;
    }
};