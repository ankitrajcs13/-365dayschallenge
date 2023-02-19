class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> my_resanki;
        
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        while(i<n1 && j <n2){
            // it means we have to add elements from first list
            if(nums1[i][0] < nums2[j][0]){
                my_resanki.push_back(nums1[i]);
                i++;
                }
            // it means we have to add elements from second list
            else if(nums2[j][0] < nums1[i][0]){
                my_resanki.push_back(nums2[j]);
                j++;
                }
            // which means both id are equal
            else{
                my_resanki.push_back({nums1[i][0],nums1[i][1]+ nums2[j][1]});
                i++,j++;
            }
        }
        
        // now add all the remaining elements from both arrays
        while(i < n1){
            my_resanki.push_back(nums1[i]);
            i++;
        }
        while(j <n2){
            my_resanki.push_back(nums2[j]);
            j++;
        }
        return my_resanki;
        
        
    }
};