class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ankires;
        
        for(auto st:words){
            string ankiTmp= "";
            stringstream s(st);
            while(getline(s,ankiTmp,separator)){
                if(ankiTmp != "")ankires.push_back(ankiTmp);
            }
        }
        return ankires;
    }
};