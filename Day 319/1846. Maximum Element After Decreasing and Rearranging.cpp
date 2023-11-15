class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int n = arr.size();
        for(int i = 1; i<n; i++){
            int diff = arr[i] - arr[i-1];
            if(diff > 1){
                arr[i] = arr[i-1] + 1;
            }
        }
        return arr[n-1];
    }
};