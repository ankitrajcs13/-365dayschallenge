class Solution {
public:
    int hIndexBruteForce(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            if(c[i] >= n - i) {
                maxi = max(maxi, n - i);
            }
        }
        return maxi;
    }

    int hIndex(vector<int>& citations) {
        return hIndexBruteForce(citations);
    }
};