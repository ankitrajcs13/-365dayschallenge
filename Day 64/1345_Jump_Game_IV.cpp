class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // map to store indices of occurence of same element
        unordered_map<int, vector<int>> mpIndx;
        for(int i = 0; i<n; i++)
            mpIndx[arr[i]].push_back(i);// it will push all the occurence in a vector form
        vector<bool> visited(n); 
        visited[0] = true;
        // queue is used to do BFS traversal
        queue<int> q;
        q.push(0);
        int totalStep = 0;
        while(!q.empty()){
            for(int size = q.size() - 1; size>=0; size--){
                // pop the front element and store it
                int tmp = q.front(); q.pop();
                // if that node is the last node, it means we reached to the last of array
                if(tmp == n-1) return totalStep;
                vector<int>& nxtNodes = mpIndx[arr[tmp]];
                nxtNodes.push_back(tmp-1);
                nxtNodes.push_back(tmp+1);
                for(int j:nxtNodes){
                    if(j >=0 && j < n && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
                // To remove all the occurence of element from the map which are already visited
                mpIndx[arr[tmp]].clear();
            }
            totalStep++;
        }
        return -1;
    }
};
// TC - O(N)
// SC - O(N)