class Solution {
public:

    void dfs(string src,string des,unordered_map<string,vector<pair<string,double>>>&mp,map<string,int>m,double &ans,double temp){
        m[src] = 1;
        if(src == des){
            ans = temp;
            return;
        }
        for(auto k: mp[src]){
            if(m[k.first] == 0){
                dfs(k.first,des,mp,m,ans,temp*k.second);
            }
        }
        return;
    }

    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
          unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<e.size();i++){
            mp[e[i][0]].push_back({e[i][1],v[i]});
            mp[e[i][1]].push_back({e[i][0],1.0/v[i]});
        }
        vector<double>an;
        for(int i=0;i<q.size();i++){
            string src=q[i][0];
            string des=q[i][1];
            map<string,int>m;
            double ans=-1.0;
            double temp=1.0;
            if(mp.count(src))
            dfs(src,des,mp,m,ans,temp);
            an.push_back(ans);
            
        }
        return an;
    }
};