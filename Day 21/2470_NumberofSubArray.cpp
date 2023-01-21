class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            int d = nums[i];
            if(d == k)
                cnt++;
            for(int j = i+1; j<n; j++){
                // finding the lcm of subarray by selecting two elements
                d = lcm(d,nums[j]);
                // and if it equal to k, them increment count
                if(d == k)
                    cnt++;
                else if(d<k)
                    continue;
                else 
                    break;

            }
        }
        return cnt;
    }
};

// TC - O(N)
// SC - O(1)