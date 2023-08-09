class Solution {
public:
    int solve(vector<int>& nums, int t){
        int i= 0, cnt = 0;
        while(i<nums.size()-1){
            if(nums[i+1] - nums[i] <= t){
                cnt++;i++;
            }
            i++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums[nums.size()-1]- nums[0];
        int ans = -1;
        while(l<h){
            int mid = l + (h-l)/2;

            if(solve(nums,mid) >= p ){
                h = mid;
            }
            else l = mid+1;
            ans = l;
        }
        return l;
    }
};