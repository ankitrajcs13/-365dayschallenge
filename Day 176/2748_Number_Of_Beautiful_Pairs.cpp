class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ankin = nums.size();
        int Ankicnt = 0;
        for(int i = 0; i<ankin; i++){
            for(int j = i+1; j<ankin; j++){
                string An1 = to_string(nums[i]);
                string An2 = to_string(nums[j]);
                int Ax = An1[0]-'0', Ay = An2[An2.size()-1]-'0';
                if(__gcd(Ax,Ay) == 1) Ankicnt++;
                
            }
        }
        return Ankicnt;
    }
};