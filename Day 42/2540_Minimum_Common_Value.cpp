class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = min(n1,n2);
        int ans = INT_MAX;
        // using binary search
        int i = 0,j = 0;
        while(i<n1 && j<n2){
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] > nums2[j])
                j++;
            else 
                i++;
        }
        return -1;
    }
};
// TC - O(N)
// SC - O(1)