class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, cnt = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n-1; i>0; i--){
            if(nums[i] != nums[i-1]){
                ans += cnt;
            }
            cnt++;
        }
        return ans;
    }
};

// PQ

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int>mp;
        // store the frequency 
        for(auto it:nums)mp[it]++;
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.first);
        }
        int ans = 0;
        while(pq.size() > 1){
            int d = pq.top();
            pq.pop();
            // add the freq of that node to ans
            ans+=mp[d];
            // now update the freq of nextlargest since we coverted it 
            mp[pq.top()] += mp[d];
            
        }
        return ans;
    }
};