class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int,int> Ankimp;
        int n = nums.size();
        for(int i = 0; i<n; i++)
            Ankimp[nums[i]] = 1;
        
        int tmp = moveFrom.size();
        for(int i = 0; i<tmp; i++){
            if(Ankimp.find(moveFrom[i]) != Ankimp.end()){
                Ankimp.erase(moveFrom[i]);
                Ankimp[moveTo[i]] = 1;
            }
        }
        vector<int> ankiRes;
        for(auto it:Ankimp){
            ankiRes.push_back(it.first);
        }
        sort(ankiRes.begin(), ankiRes.end());
        
        return ankiRes;
        
    }
};