class Solution {
public:
    bool chk(vector<int>&arr){
        sort(arr.begin(), arr.end());

        int d = arr[1] - arr[0];

        for(int i = 2; i<arr.size(); i++){
            if(arr[i] - arr[i-1] != d) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>res;
        for(int i = 0; i<n; i++){
            vector<int>tmp;
            for(int j = l[i]; j<=r[i]; j++){
                tmp.push_back(nums[j]);
            }
            res.push_back(chk(tmp));
        }
        return res;
    }
};g