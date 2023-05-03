class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<vector<int>>ans={{},{}};

       

        for(int it: st1){
            if(st2.count(it) == 0)
                ans[0].push_back(it);
        }

        for(int it:st2){
            if(st1.count(it) == 0)
                ans[1].push_back(it);
        }
        return ans;
       
        
    }
};