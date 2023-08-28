class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int> st;
        long long sum= 0;
        int curr= 0, num= 1;
        while(curr< n){
            int diff= target - num;
            if(!st.contains(diff)){
                st.insert(num);
                sum+=num;
                curr++;
                num++;
            }
            else num++;
        }
        return sum;
    }
};