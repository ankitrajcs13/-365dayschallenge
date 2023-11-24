class Solution {
public:
typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        //pq
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll> > > pq;
        vector<ll>dist(n,LLONG_MAX), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (1e9+7);
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                ll adjNode = it.first;
                ll edW = it.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis+edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};