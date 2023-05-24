class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i)
            ess[i] = {nums2[i], nums1[i]};
        sort(rbegin(ess), rend(ess));
        long long sumS = 0, res = 0;
        //min heap
        priority_queue <int, vector<int>, greater<int>> pq; 
        for (auto& [e, s] : ess) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = max(res, sumS * e);
        }
        return res;
    }
};