class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> Ankist;
        int Afl = 0;
        int Ankicnt = 0;
        // traverse from back
        for(int i = n-1; i>=0; i--){
            if(nums[i] <= k)
                Ankist.insert(nums[i]);
            Ankicnt++;
            // cout<<st.size();
            if(Ankist.size() == k){
                Afl = 1;
                break;
            }
        }
        if(Afl == 1) return Ankicnt;
        return -1;
    }
};