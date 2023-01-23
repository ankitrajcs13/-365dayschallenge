class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp;

        // while iterating through the array
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] == 0){
                tmp.push_back(0);
                tmp.push_back(0);
            }
            else
                tmp.push_back(arr[i]);
        }

        // replace it to the orginal array
        for(int i = 0; i<arr.size(); i++)
            arr[i] = tmp[i];
    }
};

// TC - O(N)
// SC - O(N)