class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int idx, int n){
        if(idx == special.size()){
            int temp = 0;
            for(int i=0; i<n; i++){
                temp += (needs[i] * price[i]);
            }
            return temp;
        }

        int flag = 0;
        for(int i=0; i<n; i++){
            if(special[idx][i] > needs[i]) flag = 1;
        }


        if(flag == 0){
            for(int i=0; i<n; i++){
                needs[i] -= special[idx][i];
            }
            int consider = special[idx][n] + solve(price, special,needs,idx,n);
            for(int i=0; i<n; i++){
                needs[i] += special[idx][i];
            }
            return min(consider, solve(price, special,needs,idx+1,n));
        }

        return solve(price, special,needs,idx+1,n);;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int ans = solve(price,special,needs,0,n);
        return ans;
    }
};31