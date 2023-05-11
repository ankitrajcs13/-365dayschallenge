class Solution {
public:
  string count_sort(string s) {
        int mp[26] = {0};
        for (char c : s) {
            mp[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(mp[c], c + 'a');
        }
        return t;
    }
    vector<string> removeAnagrams(vector<string>& words) {
       vector<string>ans;
       int n=words.size();
       ans.push_back(words[0]);
       for(int i=1;i<n;i++){
           if(count_sort(words[i])==count_sort(words[i-1]));
           else ans.push_back(words[i]);
       }
       return ans;
    }
};