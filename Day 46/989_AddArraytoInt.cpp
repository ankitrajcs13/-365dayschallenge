class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // start traversing from last
        int n = num.size();
        for(int i = n-1; i>=0; i--){
            int tmp = num[i] + k;
            num[i] = tmp % 10;
            k = tmp /10;
        }
        while(k>0){
            num.insert(num.begin(), k%10);
            k = k/10;
        }
        return num;



    }
};