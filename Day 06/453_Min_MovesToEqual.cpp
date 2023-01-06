class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n = nums.size();
        //if(n <=1)   return 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        int min = nums[0];// to get the minimum elements as the array is sorted
        
        //calculating the difference between the element and the min element 
        // and storing it into the array
        for(int i =n-1; i>=0; i--){
            ans = ans + (nums[i]-min);
        }
        
        return ans;

    }
};
// TC- O(n)
// SC- O(1)