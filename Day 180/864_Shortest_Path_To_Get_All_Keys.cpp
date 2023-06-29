class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1, y = -1, m = grid.size(), n = grid[0].size(), maxi = -1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                char ch = grid[i][j];

                if(ch == '@'){
                    // starting point
                    x = i;
                    y = j;
                }
                if(ch >='a' && ch <= 'f'){
                    // these are keys
                    maxi = max(ch-'a' + 1,maxi);
                }
            }
        }

        queue<vector<int>> q;
        vector<int> st = {0,x,y};
        unordered_set<string> vis;
        vector<vector<int>> dirs {{-1,0}, {1,0}, {0,1}, {0,-1}};
        vis.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
        q.push(st);
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                vector<int> tmp = q.front();
                q.pop();
                if(tmp[0] == (1 << maxi) -1 ) // it means we found every keys present
                    return step;

                for(auto it: dirs){
                    int i = tmp[1] + it[0];
                    int j = tmp[2] + it[1];
                    int keys = tmp[0];


                    if(i >= 0 && i < m && j >=0 && j < n){ // we are in the grid
                        char ch = grid[i][j];
                        if(ch == '#') continue; // wall
                        if(ch >= 'a' && ch <= 'f') // to add key in the bit mask
                            keys = keys |  1 << (ch -'a');

                        if(ch >= 'A' && ch <= 'F' && ( (1 << (ch-'A')) & keys)== 0 )
                            continue; // key is not present

                        if(!vis.count(to_string(keys) + " " + to_string(i) + " " + to_string(j))){
                            vis.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
                            q.push({keys,i,j});
                        }
                    }
                }


            }
            step++;

        }
        return -1;

    }
};