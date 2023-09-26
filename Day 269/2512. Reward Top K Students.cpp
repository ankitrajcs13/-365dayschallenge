class Solution {
public:
    
    static bool cmp( pair<int,int>&a, pair<int,int>&b){
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
    
    vector<int> topStudents(vector<string>& posi, vector<string>& nega, vector<string>& report, vector<int>& student_id, int k) {

        int n = report.size();
        unordered_map <int,int> mp;
        unordered_set <string> pos( begin(posi), end(posi) ),neg ( begin(nega), end(nega) );

        for(int i = 0; i < n; i++){
            string rep = report[i];
            int id = student_id[i], m = rep.length(), score = 0;
            for(int j = 0; j < m; j++){
                string tmp;
                while(j < m and rep[j] != ' ') tmp += rep[j++];
                if(pos.count(tmp)) score += 3;
                else if(neg.count(tmp)) score --;
            }
            mp[id] = score;
        }

        vector <pair<int,int>> vp;
        for(auto &[k,v] : mp) vp.push_back({v,k});
        sort( begin(vp), end(vp) , cmp);
        vector<int> res;

        
        for(int i = 0; i < k; i++){
            res.push_back(vp[i].second);
        }
        return res;
    }
};