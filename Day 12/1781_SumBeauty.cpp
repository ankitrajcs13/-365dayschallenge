class Solution {
public:
    int beautySum(string s) {
        // we are traversing the string and storing the frequency of each 
        // element in map
        int ans = 0;
        for(int i = 0; i<s.length(); i++){
            // we are creating the map inside this loop because we have to store 
            // the frequencies of each subarray
            unordered_map<char,int> mp;
            for(int j =i; j<s.length(); j++){
                mp[s[j]]++;
                int maxi= INT_MIN;
                int mini = INT_MAX;
                for(auto it:mp){
                    maxi = max(maxi, it.second);
                    mini = min(mini,it.second);
                }
                ans = ans + (maxi-mini);
            }

        }
        return ans;


    }
};
// TC- O(n2)
// SC- O(1)



// 2nd Approach :)
class Solution {
public:
    int beautySum(string s) {
        // using vector
        int ans = 0, n = s.size();
		for (int i = 0; i < n; ++i) {
			vector<int> ch(26, 0);
			int maxi = INT_MIN, mini = INT_MAX;
			for (int j = i; j < n; ++j) {
				ch[s[j] - 'a']++;
				maxi = max(maxi, ch[s[j] - 'a']);
                mini = 1e9;
				for (int k = 0; k < 26; ++k) {
					if (ch[k] >= 1) mini = min(mini, ch[k]);
				}
			 ans += maxi - mini;
			}
		}
		return ans;
    }
};
// TC- O(n)
// SC = O(n)