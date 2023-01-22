class Solution {
public:
        bool compare(int a[], int b[]) {
        return a[0] > b[0];
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int r = score.size();
        
        int c = score[0].size();
        // traversing the array by keeping the col constant
        for(int i = 0; i<r-1; i++){
            for(int j = i+1; j<r; j++){
                if(score[i][k] < score[j][k]){
                    // swap the elements while traversing the matrix
                    // without using the inbuilt function
                    vector<int> tmp = score[i];
                    score[i] = score[j];
                    score[j] = tmp;
                }
            }
        }
        return score;
        
    }
};