class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = INT_MIN, res = 0;
        for(int i = 0; i<gain.size(); i++){
            maxi = max(maxi,res);
            res += gain[i];
        }
        maxi = max(maxi,res);
        return maxi;
    }
};