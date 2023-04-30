class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
     
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> Ankitmp(n * m);
        for(int i = 0; i<n*m; i++){
            Ankitmp[arr[i] -1 ] = i;
        }
        
        vector<int> AnkiR(n);
        vector<int> AnkiC(m);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                AnkiR[i] = max(AnkiR[i], Ankitmp[mat[i][j]-1]);
                AnkiC[j] = max(AnkiC[j], Ankitmp[mat[i][j]-1]);
            }
        }
        
        int mini1 = INT_MAX, mini2 = INT_MAX;
        
        for(int i = 0; i<n; i++){
            if(AnkiR[i] < mini1)
                mini1 = AnkiR[i];
        }
        for(int i = 0; i<m; i++){
            if(AnkiC[i] < mini2)
                mini2 = AnkiC[i];
        }
        // return min (*min_element(AnkiR.begin(), AnkiR.end()), *min_element(AnkiC.begin(), AnkiC.end()));
        return min(mini1,mini2);
        
    }
};