class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int far= 0;
        int curr = 0;
        for(int i = 0; i<nums.size()-1; i++){
            // to calculate that from that index how much far we can go
            far = max(far,nums[i]+i);
            if(i == curr){
                // it means that we have reached the position we can jump from that element
                curr = far;
                jumps++;
            }
        }
        return jumps;
    }
};
// TC - O(N)
// SC - O(1)