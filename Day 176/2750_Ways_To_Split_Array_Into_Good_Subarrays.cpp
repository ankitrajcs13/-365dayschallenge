class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int Ankif1 = -1, Ankil1 = -1;
        int mod = 1e9+7;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                Ankil1 = i;
                if(Ankif1 == -1) Ankif1 = i;
            }
        }
        if(Ankif1 == -1) return 0;
        vector<int> zCnt;
        int Ankitmp = 0;
        
        for(int i = Ankif1; i<=Ankil1 ; i++){
            if(nums[i] == 0) Ankitmp++;
            else {
                zCnt.push_back(Ankitmp);
                Ankitmp = 0;
            }
        }
        long long res = 1;
        for(int it: zCnt){
            res = (res * (it+1)) % mod;
        }
        return (int)res;
    }
};