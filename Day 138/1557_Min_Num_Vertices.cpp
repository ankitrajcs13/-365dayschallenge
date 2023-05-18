class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        
        // now iterating through it, check all the nodes for incoming edge and mark it true
        vector<int> chk(n,0);
        for(auto it: edges){
            chk[it[1]]++;
        }

        // now put all those into ans for which there is no incoming edge
        for(int i = 0; i<n; i++){
            if(chk[i] == 0) res.push_back(i);
        }
        return res;


    }
};

// alternate:
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        
        // now iterating through it, check all the nodes for incoming edge and mark it true
        vector<bool> chk(n,false);
        for(auto it: edges){
            chk[it[1]] = true;
        }

        // now put all those into ans for which there is no incoming edge
        for(int i = 0; i<n; i++){
            if(!chk[i]) res.push_back(i);
        }
        return res;


    }
};

// TC - O ( E+V )
// SC - O ( N )