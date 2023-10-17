class Solution {
public:
    int solve(int root,vector<int>& leftChild, vector<int>& rightChild ){
        if(root == -1) return 0;
        return 1 + solve(leftChild[root], leftChild,rightChild)+solve(rightChild[root],leftChild,rightChild);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indeg(n,0);

        for(int i = 0; i<n; i++){
            if(leftChild[i] != -1){
                if(indeg[leftChild[i]] == 1) return false;
                else indeg[leftChild[i]] =1;
            }
            if(rightChild[i] != -1){
                if(indeg[rightChild[i]] == 1) return false;
                else indeg[rightChild[i]] =1;
            }
        }
        // find root
        int root = -1;
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                if(root == -1) root = i;
                else return false;
            }
        }
        // no root node
        if(root == -1) return false;
        // do bfs/dfs to get nodes
        return solve(root,leftChild,rightChild) == n;
    }
};