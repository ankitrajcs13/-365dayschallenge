class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i< n; i++){
            if(n % i == 0){
                // to get the substring from 0 to i
                string curr = s.substr(0,i);
                bool flag = true;
                for(int j = i; j < n; j+= curr.size()){
                    // comparing it with the generated substr
                    if(curr != s.substr(j,i)){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return true;
            }
        }
        return false;

    }
};