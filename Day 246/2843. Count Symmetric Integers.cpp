class Solution {
public:
    int A(int n){
        
        string st = to_string(n);
        int s = st.size();
        if(s%2 != 0)return false;
        int ankifst = 0;
        int ankiscnd = 0;
        for (int i = 0; i < s/2; i++) {
            ankifst += st[i] - '0';
            ankiscnd += st[s-i-1] - '0';
        }
        return ankifst == ankiscnd;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i= low; i<=high; i++)
            cnt+=A(i);
        return cnt;
    }
};