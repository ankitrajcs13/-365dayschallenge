class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length()-1;
        int n2 = b.length()-1;
        string ans = "";
        int tmp = 0;
        while(n1 >=0 || n2 >=0 || tmp == 1){
            tmp += (  (n1 >= 0)? a[n1]-'0': 0);
            tmp += (  (n2 >= 0)? b[n2]-'0': 0);
            ans = char(tmp% 2 + '0') + ans;
            tmp /=2;
            n1--, n2--;
        }
        return ans;

    }
};