class Solution {
public:
    int minFlips(string target) {
        // we just have to find the breaking point
        char curr = '0';
        int cnt = 0;
        for(int i = 0; i<target.size(); i++){
            if(target[i] != curr){ // we found the breakpoint
                curr = target[i]; // replace it with opposite char 
                cnt++;
            }
        }
        return cnt;
    }
};