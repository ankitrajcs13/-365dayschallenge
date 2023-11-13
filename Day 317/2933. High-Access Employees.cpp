class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>>mp;
        for(auto it: access_times){
            mp[it[0]] .push_back(stoi(it[1]));
        }
        vector<string> ans;
        for(auto &it:mp){
            vector<int> &lst = it.second;
            sort(lst.begin(), lst.end());
            //now check for more than two access times
            for(int i = 2; i< lst.size(); i++){
                if(lst[i] - lst[i-2] < 100) {// as we are checking it for 60 + 40
                    ans.push_back(it.first);
                    // if found then just break
                    break;
                }
            }
        }
        return ans;

    }
};