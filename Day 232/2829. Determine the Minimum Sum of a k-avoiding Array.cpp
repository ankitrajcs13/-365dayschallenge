class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> st;
        int ankisum = 0;
        int ankCurr = 0, anknum = 1;
        while(ankCurr < n){
            int ankDiff = k - anknum;
            if(!st.contains(ankDiff)){
                st.insert(anknum);
                ankisum+=anknum;
                ankCurr++;
                anknum++;
            }
            else anknum++;
        }
        return ankisum;
    }
};