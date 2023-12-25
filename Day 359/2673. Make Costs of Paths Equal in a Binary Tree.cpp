class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> v;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int child = 2 * (i + 1);
            if(child > n){
                int par = (i + 1) / 2;
                int sum = 0;
                int x = i + 1;
                while(x){
                    sum += cost[x - 1];
                    x /= 2;
                }
                v.push_back(sum);
            }
        }
        while(v.size() > 1){
            vector<int> v1;
            for(int i = 0;i<v.size();i+=2){
                int a = v[i] , b = v[i+1];
                int diff = abs(b - a);
                ans += diff;
                int mx = max(a, b);
                v1.push_back(mx);
            }
            v = v1;
        }
        return ans;
    }
};