class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // edge case
        if(n==1)
            return 1;
        int cnt = 0;
        vector<int> pos(n+1);
        for(auto i: trust){
            pos[i[0]]--;

            pos[i[1]]++;
        }

        // now check which count has n-1 count
        for(int i = 0; i<pos.size(); i++){
            if(pos[i] == n-1){
                // it means that this is eligible for judge
                return i;
            }
        }
        return -1;
    }
};
// TC - O(N)
// SC - O(N)