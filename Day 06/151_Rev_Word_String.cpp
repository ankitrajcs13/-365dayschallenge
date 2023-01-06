class Solution {
public:
    string reverseWords(string s) {
        string res = "";

        int n = s.size()-1;

        while(n >=0){
            while(n >=0 && s[n] == ' ')
                n--;
            // there are no words present
            if(n < 0)
                break;

            int start= n;
            while(start >=0 && s[start] != ' ')
                start--;

            // Now add that last word to the string so that it will come at first position
            for(int i = start+1; i<=n; i++){
                res += s[i];
            }
            // now add one space so that it can be separated
            res += ' ';
            // now to get the position of last second char and so on
            n = start;
        }

        while(!res.empty() && res.back() == ' ')
            res.pop_back();

        return res;

    }
};

// TC- O(n)
// SC - O(n)