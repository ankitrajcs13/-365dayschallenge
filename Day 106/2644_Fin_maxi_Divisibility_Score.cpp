    class Solution {
    public:
        int maxDivScore(vector<int>& nums, vector<int>& divisors) {
            
            int AnkiRES = 0;
            vector<int> AnkiV(divisors.size(),0);
            int a = nums.size();
            int b = divisors.size();
            int AnMp = 0, Maxi = INT_MAX;
            for(int i = 0; i<b; i++){
                int cn = 0;
                for(int j = 0; j<a; j++){
                    if(nums[j] % divisors[i] == 0)
                        cn++;
                }
                if(cn == AnMp){
                    AnMp = cn;
                    Maxi = min(Maxi,divisors[i]);
                }
                else if( cn > AnMp){
                    AnMp = cn;
                    Maxi = divisors[i];
                }
            }
            return Maxi;
            
            
        }
    };