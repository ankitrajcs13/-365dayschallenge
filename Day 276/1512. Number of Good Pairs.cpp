class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        map<int,int>mp;
        for(auto it:nums){
            // while traversing the array itself
            // add the occurence in result
            cnt += mp[it];
            mp[it]++;
        }
        return cnt;
    }
};