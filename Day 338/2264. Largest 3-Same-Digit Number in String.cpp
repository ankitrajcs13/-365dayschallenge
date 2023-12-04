class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res = "";
        for(int i = 1; i<n; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                string tmp = {num[i-1],num[i],num[i+1]};
                res = max(res,tmp);
            }
        }
        return res;
    }
};