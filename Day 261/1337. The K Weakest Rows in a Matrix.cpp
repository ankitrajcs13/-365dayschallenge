class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         int n = mat.size();
    unordered_map<int,int> m;
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<mat[i].size();j++)
        {
            m[i] = m[i]+mat[i][j];
        }
    }
    
    vector<pair<int,int>>v;
    
    for(auto i:m)
    {
        v.push_back(make_pair(i.second,i.first));
        cout<<i.second<<i.first<<endl;
    }
    sort(v.begin(), v.end());
    vector<int>ans;
    for(int i = 0; i<k;i++)
    {
        ans.push_back(v[i].second);
    }
    return ans;
        
    }
};