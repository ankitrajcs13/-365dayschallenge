class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> mp;
       stack<int> st;
       st.push(-1);

       for(int i = nums2.size()-1; i>=0; i--){
           while(st.top() !=-1 && nums2[i] > st.top())
                st.pop();
        mp[nums2[i]] = st.top();
        st.push(nums2[i]);
       }    
       for(int i = 0; i<nums1.size(); i++){
           // replacing the values in n1 from the map values
           nums1[i] = mp[nums1[i]];
       }
       return nums1;
    }
};