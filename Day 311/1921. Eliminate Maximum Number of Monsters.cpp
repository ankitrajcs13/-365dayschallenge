class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>time(n);

        for(int i = 0; i<n; i++){
            time[i] = ceil((float)dist[i] / speed[i]);
        }
        // kill the monster who is nearest to the ciry
        sort(time.begin(), time.end());
        int ans = 1;
        for(int i = 1; i<n; i++){
            if(time[i] - i <=0) return ans;
            ans++;
        }
        return ans;
    }
};