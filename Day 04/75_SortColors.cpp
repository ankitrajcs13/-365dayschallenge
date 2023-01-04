class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0,e = nums.size()-1;
        int mid = 0;

        while(mid<=e){
            switch(nums[mid]){
                // If the element is 0 
            case 0: 
                swap(nums[s++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[e--]); 
                break; 
            }
        }

    }
};

// TC: O(N)
// SC: O(1)