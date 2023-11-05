class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        if(k>= n)
            return maxi;
        int res = arr[0];
        int wins = 0;
        for(int i = 1; i<n; i++){
            if(res > arr[i]) wins++;
            else {
                res = arr[i];
                wins = 1;
            }
            if(wins == k) return res;
        }
        return res;
        
    }
};