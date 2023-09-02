class Solution {
public:
    long long f(vector<int>&nums, long long j, unordered_map<int,int>&mp){
        long long Ankiadd = 0;
        for(int it = 0; it<j-1; it++){
            int ankist = nums[it];
            mp[ankist]++;
            Ankiadd += nums[it];
        }
        return Ankiadd;
    }
    long long maxSum(vector<int>& nums, int m, int k) {
        long long tmp = k, ankiR = m, Ankires = 0, remV = 0;
        unordered_map<int,int>mp;
        remV = f(nums,tmp,mp);
        for(int i = tmp-1; i<nums.size(); i++){
            mp[nums[i]]++;
            remV+=nums[i];
            if(mp.size()>=ankiR)Ankires=max(Ankires,remV);
            mp[nums[i-tmp+1]]--;
            remV-=nums[i-tmp+1];
            if(mp[nums[i-tmp+1]] == 0) mp.erase(nums[i-tmp+1]);
        }
        return Ankires;
    }
};