class Solution {
public:
    int strStr(string haystack, string needle) {
        // USing Two pointers Approach
        for(int i = 0; i<haystack.length(); i++){
            // if first char is equal
            if(haystack[i] == needle[0]){
                int ind = i+1;
                int j = 1;
                while(haystack[ind] && needle[j]){
                    if(haystack[ind] != needle[j])
                        break;
                    ind++,j++;
                }
                // it means we found the occurence of string needle;
                if( j == needle.length()) return i;
            }
        }
        return -1;

    }
};

//2nd Approach

class Solution {
public:
    int strStr(string haystack, string needle) {
        
         int h=0;
    int occ = -1; // first occurence 
    while( h < haystack.size() ){
        
        if( needle[0] == haystack[h] ){
            
            occ = h;
            int i = 0;
            int j = h;
            
            while( j < h + needle.size() ){
                
                if( haystack[j++] == needle[i++] ){
                }
                else {        // if pattern doesnt match revert back occ to -1 and start searching for next h
                    occ = -1;
                    break;
                }
            }
            
            if( occ == h) return occ; // if pattern matches return occ
        }
        
        h++;
        
    }
    
    return occ;
        
    }
};