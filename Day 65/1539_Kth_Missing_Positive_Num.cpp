class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // By creating a vector
        vector<int> tmp;
        arr.push_back(78678132);
        int n = arr.size();
        int ptr = 0;
        int i = 1;
        while(tmp.size() <=k){
            if(ptr != n && arr[ptr] == i )
                ptr++;
            else 
                tmp.push_back(i);
            i++;
        }
        return tmp[k-1];
    }
};
