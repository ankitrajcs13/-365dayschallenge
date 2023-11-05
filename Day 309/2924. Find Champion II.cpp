class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>ankideg(n,0);
        // topo sort indeg
        for(auto it:edges){
            int u = it[0];
            int v= it[1];
            ankideg[v]++;
        }
        int ankichamp = -1, ankicnt = 0;
        for(int i= 0;i<n; i++){
            // cout<<ankideg[i]<<"F"<<endl;
            if(ankideg[i] == 0){
                if( ankichamp == -1){
                    ankichamp = i; 
                    ankicnt++;
                }
                else return -1;
                    
            }
        }
        return (ankicnt == 1)? ankichamp:-1;    
    }
};