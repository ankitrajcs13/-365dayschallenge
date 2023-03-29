class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>() );

        vector<int> res = satisfaction;

        for(int i = 1; i < n; i++){
            res[i] += res[i-1];
        }
        int maxi = 0, curr = 0;
        for(int i = 0; i<n; i++){
            curr += res[i];
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};