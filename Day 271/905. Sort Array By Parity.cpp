class Solution {
public:
    static bool cmp(int &a, int &b){
        return a%2 < b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even, odd;
        for(int it:nums){
            if(it%2 == 0)even.push_back(it);
            else odd.push_back(it);
        }
        vector<int>res;
        for(int i = 0; i<even.size(); i++){
            res.push_back(even[i]);
        }
        for(int i = 0; i<odd.size(); i++){
            res.push_back(odd[i]);
        }
        return res;
    }
};