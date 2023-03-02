class Solution {
public:
    int compress(vector<char>& chars) {
        
        // using two pointer approach
        int i = 0; 
        int ind = 0;
        int n = chars.size();

        while(i<n){
            int j = i+1;
            while(j<n && chars[i] == chars[j])
                j++;

            chars[ind++] = chars[i];

            int cnt = j-i;

            if(cnt > 1){
                // means we have to convert cnt into a single digit
                string cont = to_string(cnt);
                for(char ch: cont)
                    chars[ind++] = ch;
            }
            i = j;
        }
        return ind;
        



    }
};