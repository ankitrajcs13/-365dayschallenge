class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = -1;

        vector<int> prev = intervals[0];

        for(vector<int> interval: intervals){
            if(interval[0] < prev[1])
                ans++;
            else
                prev = interval;
        }
        return ans;
    }
};