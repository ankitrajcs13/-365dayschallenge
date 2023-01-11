class Solution {
public:
    bool rotateString(string s, string goal) {
        // first check that both the string are equal or not
        if(s.size() != goal.size())
            return false;

        bool flag = false;
        int cnt = 0;
        // we are concatenating the string 2 times 
        // Like s = abcde + abcde = abcdeabcde
        s = s + s;
        for(int i = 0; i<s.size(); i++){
            if(goal[0] == s[i]){
                for(int j = 0; j<goal.size(); j++){
                    if(goal[j] == s[i+j]){
                        // This means that from that index of i we have the same string in s
                        // as the string in Goal
                        cnt++;
                        flag = true;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                if(flag== true)
                    break;
                else
                    cnt = 0;
            }
        }
        if(cnt == goal.size())
            return true;
        else
            return false;
    }
};

