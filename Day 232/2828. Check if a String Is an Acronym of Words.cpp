class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() > s.size()) return false;
        
        string ankires;
        for(int i = 0; i<words.size(); i++){
            string st = words[i];
            ankires += st[0];
        }
        return (ankires == s);
    }
};