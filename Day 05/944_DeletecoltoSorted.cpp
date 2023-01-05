class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        // store length of row and col
        int m = strs.size();
        int n = strs[0].length();

        for(int col=0;col<n;col++){
            for(int row=1;row<m;row++){
                if(strs[row][col] < strs[row-1][col]) {
                    cnt++;
                    break;
                }
            }
        }

        return cnt;

    }
};
// TC - O(n2)
// SC - O(1)