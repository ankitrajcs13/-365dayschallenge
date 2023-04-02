class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // firstly storing the occurence in map
        map<int,int> AnkiMp;
        
        for(auto& it:nums) AnkiMp[it]++;
        
        vector<vector<int> > MyRes;
        // till the occurence get nots empty as we have to include every eleement of array
        while(!AnkiMp.empty()){
            vector<int> Atmp,Atmp2;
            for(auto it: AnkiMp){
                Atmp.push_back(it.first);
                AnkiMp[it.first]--;
                if(AnkiMp[it.first] == 0)
                    Atmp2.push_back(it.first);
            }
            MyRes.push_back(Atmp);
            // remove those values from map which have been used
            for(auto &it: Atmp2)
                AnkiMp.erase(it);
            
        }
        return MyRes;
    }
};