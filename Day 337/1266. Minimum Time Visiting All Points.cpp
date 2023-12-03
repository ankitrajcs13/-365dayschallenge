class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i<points.size()-1; i++){
            int p1 = points[i][0];
            int q1 = points[i][1];

            int p2 = points[i+1][0];
            int q2 = points[i+1][1];

            // diag move
            int dp = abs(p2-p1);
            int dq = abs(q2-q1);

            int dig = min(dp,dq);
            int r = abs(dp-dq);
            ans +=(dig+r);
        }
        return ans;
    }
};