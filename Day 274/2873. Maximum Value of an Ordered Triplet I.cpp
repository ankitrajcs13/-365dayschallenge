class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ankires = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    long long tmp = (long long)(nums[i] - nums[j]) * nums[k];
                    ankires = max(ankires,tmp);
                }
            }
        }
        if(ankires <0) return 0;
        return ankires;
    }
};