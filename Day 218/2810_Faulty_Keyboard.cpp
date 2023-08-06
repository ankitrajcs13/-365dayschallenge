class Solution {
public:
    string finalString(string s) {
        string ankitmp = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'i'){
                reverse(ankitmp.begin(), ankitmp.end());
            }
            else{
                ankitmp += s[i];
            }
        }
        return ankitmp;
    }
};

class Solution {
public:
    string finalString(string s) {
        string str = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'i'){
                string tmp = "";
                stack<char>s;
                for(auto it:str)s.push(it);
                str.clear();
                while(!s.empty()){
                    tmp+= s.top();
                    s.pop();
                }
                str = tmp;
            }
            else{
                str += s[i];
            }
        }
        return str;
    }
};