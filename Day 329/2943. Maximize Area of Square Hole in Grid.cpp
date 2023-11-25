class Solution {
public:
    int solve(vector<int>&arr){
        int t1 = 0, t2 = 1;
        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i+1] - arr[i] == 1) t2++;
            else{
                t1 = max(t1,t2+1);
                t2 = 1;
            }
        }
        return max(t1,t2+1);
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(), vBars.end());
        int ank1 = solve(vBars);
        int ank2 = solve(hBars);
        int ankiR = min(ank1,ank2);
        return ankiR * ankiR;
    }
};