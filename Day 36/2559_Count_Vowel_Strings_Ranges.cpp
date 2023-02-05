class Solution {
public:
    bool check(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix_sum(n+1, 0);
        for (int i = 0; i <n; i++) 
        {
            if (check(words[i][0]) && check(words[i][words[i].size()-1]) )  prefix_sum[i+1] +=1;
            prefix_sum[i+1] += prefix_sum[i];
            
        }
        vector<int> ans;
        for (auto q : queries) 
        {
            int cal = prefix_sum[q[1] + 1] - prefix_sum[q[0]];
            ans.push_back(cal);
        }
        return ans;
    }


};