class Solution {
public:
    int xorOperation(int n, int start) {
        int arr[n];
        for(int i = 0; i<n; i++){
            arr[i] = start + 2 * i;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans ^ arr[i];
        }
    return ans;
        
    }
};
// TC- O(N)
// SC- O(1)