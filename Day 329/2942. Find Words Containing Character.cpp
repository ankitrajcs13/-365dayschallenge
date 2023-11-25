class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ankir;
        for(int in = 0; in<words.size(); in++){
            string st = words[in];
            for(int i = 0; i<st.length(); i++){
                if(st[i] == x){
                    ankir.push_back(in);
                    break;
                }
            }
        }
        return ankir;
    }
};