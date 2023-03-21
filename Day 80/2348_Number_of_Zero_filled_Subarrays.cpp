class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, tmp = 0;

        for(int i =0;i<=nums.size();i++){
            if(i<nums.size() && nums[i]==0 ) tmp++;
            else if(tmp != 0){
                // /. sum of N numbers
                res +=(tmp*(tmp+1)/2);
                tmp=0;
            }
        } 
        return res;
    }
};

//2nd Approach

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long numOfZeroFilledSubarray = 0;
        long long countZeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                countZeros++;
            else {
                numOfZeroFilledSubarray += (countZeros * (countZeros + 1) / 2);
                countZeros = 0;
            }
        }
        numOfZeroFilledSubarray += (countZeros * (countZeros + 1) / 2);
        return numOfZeroFilledSubarray;
    }
};