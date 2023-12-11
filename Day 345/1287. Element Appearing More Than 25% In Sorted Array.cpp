class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        
        return 0;
    }
};