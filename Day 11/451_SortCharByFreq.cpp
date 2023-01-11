class Solution {
public:
    bool static comp(pair<char,int>&a,pair<char,int>&b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char,int> mp;
        // we are storing frequency of every characters
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        // Now storing the char with their frequenices to the vector
        vector<pair< char,int> > v;
        for(auto &i: mp){
            v.push_back(i);
        }
        string res;
        // Sorting the vector with an comparator because the vector contains pair values
        sort(v.begin(),v.end(), comp);

        // At last storing the characters according to their frequencies which are in descending order of frequencies 
        // Into our resultant string
        for(auto it:v){
            for(int i = 0; i<it.second; i++){
                res+=it.first;
            }
        }
        return res;


    }
};