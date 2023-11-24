// USING QUEUE
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        deque<int>dq;
        for(auto it:piles)dq.push_back(it);
        while(!dq.empty()){
            dq.pop_back();
            ans += dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return ans;
    }
};

// USING JUST SORT

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        int n = piles.size();
        int time = n/3;
        int j = n-2, i = 0;
        for(int i = 0; i<time; i++){
            ans += piles[j];
            j = j-2;
        }
        return ans;
    }
};