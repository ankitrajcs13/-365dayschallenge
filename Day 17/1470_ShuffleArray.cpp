class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // create an array to store our answer
        vector<int> ans(n * 2);

        for(int i = 0; i<n; i++){
            // to get even indexes of array
            ans[2*i] = nums[i];
            // to get odd indexes of array
            ans[2*i+1] = nums[n+i];
        }
        return ans;
    }
};
// TC - O(n)
// SC - O(n)

// 2nd Approach -> Optimised Solution
/// *****************   IMPORTANT 
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for(int i = 0; i<nums.size(); i++){
            int currNum = nums[i];
            int currPos = i;
            // To swap inplace elements
            while(currNum > 0){
                int newPos;
                // formula to find new position of element
                // if i is below n
                if(currPos < n){
                    newPos = 2 * currPos;
                }
                else{
                    newPos = 2 * (currPos-n) + 1;
                }
                // storing the value of new positon, so that it didn't get lost
                int newNum = nums[newPos];
                // marking it as visited by making it negative, so we don't visit it again
                nums[newPos] = -currNum;
                // update the element
                currNum = newNum;
                // update the position
                currPos = newPos;
            }
        }
        
        // Now replace all the negative values with positive values
        for(int i= 0; i<2 * n; i++){
            if (nums[i]<0)
                nums[i] = -nums[i];
        }
        return nums;

    }
};
// TC - O(N)
// SC - O(1)