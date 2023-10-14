class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>ankires, tmp;
        int ankicnt = 0;
        for(auto it:words){
            if(it == "prev"){
                ankicnt++;
                if(ankicnt > tmp.size()) ankires.push_back(-1);
                else ankires.push_back(tmp[tmp.size()-ankicnt]);
            }
            else{
                ankicnt = 0;
                tmp.push_back(stoi(it));
            }
        }
        return ankires;
        
    }
};