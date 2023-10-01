class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.length();
        string tmp = "";
        string res = "";
        while(i<n){
            if(s[i] == ' '){
                reverse(tmp.begin(), tmp.end());
                res += tmp;
                res += ' ';
                tmp = "";
            }
            else if(i == n-1){
                tmp += s[n-1];
                reverse(tmp.begin(), tmp.end());
                res += tmp;
            }
            else{
                tmp += s[i];
            }
            i++;
        }
        return res;
    }
};

// Using Two Pointers

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.length();
        while(i<n){
            int j = i+1;
            while(j<n && s[j] != ' ') j++;

            int l = i, r = j-1;
            while(l<=r){
                swap(s[l++],s[r--]);
            }
            i = j+1;
        }
        return s;
    }
};



