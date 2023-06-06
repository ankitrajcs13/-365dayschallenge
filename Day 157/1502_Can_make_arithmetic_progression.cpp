// using sorting

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1]-arr[0];
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i+1] - arr[i] != diff ) return false;
        }
        return true;
    }
};


// using set

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());

        if(maxi - mini == 0) return true;
        int n = arr.size();
        int diff = (maxi- mini) / ( n-1);
        // edge case
        if( (maxi- mini) % ( n-1) != 0 ) return false;
        
        set<int> st;
        for(int i = 0; i<n; i++){
            if( (arr[i] - mini) % diff != 0 ) return false;
            st.insert(arr[i]);
        }
        return (st.size() == n);
    }
};