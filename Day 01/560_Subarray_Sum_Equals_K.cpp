class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum
        
        prefix[0] = nums[0]; // for element at index at zero, it is same
        
        // making our prefix array
        for(int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
            }
            
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};


// Second approach using only map

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int cnt = 0;
        mp.insert({0,1});
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            auto it = mp.find(sum-k);
            if(it!=mp.end()){
                cnt += it->second;
            }
            it = mp.find(sum);
            if(it!= mp.end()){
                it->second++;
            }
            else{
                mp.insert({sum,1});
            }
        }
        return cnt;
    }
    
};