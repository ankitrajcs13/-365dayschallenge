class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> fre(n+1,0);

        // for calculating the occurence of characters
        for(auto i: nums){
            fre[i]++;
        }

        // Find the missing digits in the vector (1,n)
        for(int i = 1; i<=n; i++){
            if(!fre[i])
                ans.push_back(i);
        }
        return ans;

    }
};

// 2nd Approach

int n = nums.size();
        vector<int>res{};
        
		// Negative elements (Marking foud)
        for(int i{}; i<n; ++i){
            
            int idx = abs(nums[i]) - 1; // since 0-based indexing
            nums[idx] = (nums[idx]>0)? -nums[idx]:nums[idx];
        }
        
		// Store positive index+1 as missing elements
        for(int i{}; i<n; ++i){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        
        return res;