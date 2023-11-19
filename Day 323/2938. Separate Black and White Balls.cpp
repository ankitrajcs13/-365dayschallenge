class Solution {
public:
    long long minimumSteps(string s) {
        long long ankis = s.size();
        long long i = 0, ankicnt = 0, tmp = 0;
        
        while(i<ankis){
            if(s[i] == '0'){
                ankicnt+= tmp;
            }
            else tmp++;
            i++;
        }
        return ankicnt;
    }
};