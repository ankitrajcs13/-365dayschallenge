class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pqL, pqR;

        int n = costs.size();
        for (int i = 0; i < candidates; i++) {
            pqL.push(costs[i]);
        }
        for(int i = max(candidates, n-candidates); i< n; i++){
            pqR.push(costs[i]);
        }

        long long nxtL = candidates, nxtR = n - candidates - 1;
        long long res = 0;
        for (int i = 0; i < k; i++) {
            if (pqR.empty() || (!pqL.empty() && pqL.top() <= pqR.top())) {
                res += pqL.top();
                pqL.pop();
                if (nxtL <= nxtR) {
                    pqL.push(costs[nxtL++]);
                }
            } else if (!pqR.empty()) {
                res += pqR.top();
                pqR.pop();
                if (nxtL <= nxtR) {
                    pqR.push(costs[nxtR--]);
                }
            }
        }
       


        return res;
    }
};
