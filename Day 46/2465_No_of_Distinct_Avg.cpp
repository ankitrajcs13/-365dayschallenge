class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<float>st;
    sort(nums.begin(),nums.end());
    
    int start=0;
    int end =nums.size()-1;
    
    while(start<end)
    {
        int nums1 = nums[start];
        int nums2 = nums[end];
        
        float avg = (nums1+nums2+0.00)/2.0;
        
        st.insert(avg);
        
        start++;
        end--;
    }         
    return st.size();
    }
};
// TC - O(Nlogm)