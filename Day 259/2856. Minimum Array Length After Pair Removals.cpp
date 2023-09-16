class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int>Ankimp;
        for(int it:nums)Ankimp[it]++;
        int n = nums.size();
        int fl = 0;
        int Ankimaxi = 0;
        for(auto it:Ankimp){
            Ankimaxi = max(Ankimaxi,it.second);
        }
        if(Ankimaxi> (n/2)) return 2 * Ankimaxi-n;
        if(n%2 == 0)return 0;
        return 1;
        
    }
};