class Solution {
public:
    string decodeAtIndex(string encodedString, int k) {
        stack<long long> characterLengths; 
        characterLengths.push(0);
        for (size_t i = 0; i < encodedString.length(); ++i) {
            if (isdigit(encodedString[i])) {
                long long length = characterLengths.top() * (encodedString[i] - '0');
                characterLengths.push(length);
            } else {
                long long length = characterLengths.top() + 1;
                characterLengths.push(length);
            }
        }

        size_t ln = characterLengths.size();
        while (!characterLengths.empty()) {
            k %= characterLengths.top(); 
            ln--;

            if (k == 0 && isalpha(encodedString[ln - 1])) {
                return string(1, encodedString[ln - 1]);
            }
            characterLengths.pop();
        }
        return ""; 
    }
};

class Solution {
public:
    string decodeAtIndex(string s, int K) {
        int n = s.length();
        long long size = 0;
        
        for(char ch:s) {
            if(isdigit(ch)) {
                size = size*(ch-'0');
            } else {
                size++;
            }
        }
        
        for(int i = n-1; i>=0; i--) {
            K = K%size;
            
            if(K == 0  && isalpha(s[i]))
                return string(1, s[i]);
            
            if(isalpha(s[i]))
                size--;
            else
                size = size/(s[i]-'0');
        }
        
        return "";
    }
};