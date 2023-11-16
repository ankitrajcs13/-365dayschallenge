class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            char ch = nums[i][i];

            if(ch == '1') res += '0';
            else res += '1';
        }
        return res;

    }
};