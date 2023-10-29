class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, cnt1 = 0;
        long long sum2 = 0, cnt2 = 0; 

        for (auto ele : nums1) {
            if (ele)
                sum1 = sum1 + ele;
            else {
                sum1++; 
                cnt1++;
            }
        }
        for (auto ele : nums2) {
            if (ele)
                sum2 = sum2 + ele;
            else {
                sum2++; 
                cnt2++; 
            }
        }
        if (sum1 == sum2)
            return sum1; 
        if (sum1 > sum2) {
            if (cnt2 == 0)
                return -1;
            return sum1; 
        }
        if (cnt1 == 0)
            return -1;
        return sum2;
    }
};