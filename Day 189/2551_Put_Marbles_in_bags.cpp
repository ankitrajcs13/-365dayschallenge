class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> st;

        for(int i = 1; i<weights.size(); i++)
            st.push_back(weights[i] + weights[i-1]);

        sort(st.begin(), st.end());

        int n = st.size();
        long long mini = 0;
        for(int i = 0; i<k-1; i++)
            mini += st[i];

        long long maxi = 0;
        for(int i = 0; i<k-1; i++)
            maxi+=st[n-i-1];

        return maxi-mini;
    }
};