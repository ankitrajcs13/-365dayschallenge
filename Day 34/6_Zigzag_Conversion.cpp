class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;

        int dir = -1, fl = 0;
        vector<string> vec(numRows,"");
        for(int i = 0; i<s.length(); i++){
            // conditon for zigzag conversion
            if(fl == numRows-1 || fl == 0)
                dir = dir * (-1);
            vec[fl] +=s[i];
            if(dir == 1)
                fl++;
            else
                fl--;
        }
        string res = "";
        // putting each character vector to string
        for(auto &it: vec){
            res+=it;
        }
        return res;
    }
};