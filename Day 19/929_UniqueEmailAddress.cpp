class Solution {
  
public:
    int numUniqueEmails(vector<string>& emails) {
        // We are creating set, as it stores unique data
        unordered_set<string> st;
        for(string &email : emails) {
            string fmail;
            for(char c : email) {
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                // adding name into fmail variable
                fmail += c;
            }
            // adding the domain name into fmail
            fmail += email.substr(email.find('@'));
            st.insert(fmail);
        }
        return st.size();

    }
};
// TC - O(N)
// SC - O(N)