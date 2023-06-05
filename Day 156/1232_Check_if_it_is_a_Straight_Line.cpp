class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        int a1 = coordinates[0][0];
        int b1 = coordinates[0][1];

        int a2 = coordinates[1][0];
        int b2 = coordinates[1][1];

        for(int i = 2; i<n; i++){
            int a = coordinates[i][0];
            int b = coordinates[i][1];

            if ( ( b-b1) * ( a - a2) != (b - b2) * (a - a1)) return false;
        }
        return true;

    }
};