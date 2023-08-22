class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber){
            // to maintain the edge case when columnNumber is multiple of 26
            columnNumber--;
            int fst = (columnNumber) % 26;
            res+= 'A' + fst;
            columnNumber/=26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};