class Solution {
public:
    int oneCnt(int n){
        int cnt = 0;
        while(n>0){
            if(n%2 == 1) cnt++;
            n/=2;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int cnt = oneCnt(i);
            if(cnt == k) ans +=nums[i];
        }
        return ans;
    }
};