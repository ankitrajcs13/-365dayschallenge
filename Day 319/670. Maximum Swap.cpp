class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = s;
        sort(t.begin(), t.end(), greater<int>());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
            {
                int j,k;
                for(j=i+1;j<s.size();j++)
                {
                    if(s[j]==t[i])
                        k=j;
                    
                }
                
                swap(s[i],s[k]);
                break;
            }
        }
        return stoi(s);
    }
};