class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        for(int i=0;i<n;i++){
            mp2[nums[i]]++; // update frequency of every element
        }
        int start = 0,end = n-1;
        for(int i=0;i<n;i++){
            // for every i update freq of map 1 till now and reduce freq of map2 till now 
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            
            //check if nums[i] is still dominant in left part and right part if yes return i
            if(mp1[nums[i]]*2 > i-start+1 && mp2[nums[i]]*2 > end-i)
            return i;
            
        }
        return -1;
    }
};