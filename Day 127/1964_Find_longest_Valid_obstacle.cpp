class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> tmp;
        vector<int> res(n);

        for(int i = 0; i<n; i++){
            int d = obstacles[i];
            if(tmp.size() == 0 || tmp.back() <= d ){
                tmp.push_back(d);
                res[i] = tmp.size();
            }
            else{
                int t = upper_bound(tmp.begin(), tmp.end(), d) - tmp.begin();
                tmp[t] = d;
                res[i] = t+1;
            }
        }
        return res;

    }
};