class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        if(left.size() != 0) maxi = *max_element(left.begin(),left.end());
        int ans = 0;
        ans = max(ans,maxi);
        for (int num : right) {
            ans = max(ans, n - num);
        }
        
        return ans;

    }
};