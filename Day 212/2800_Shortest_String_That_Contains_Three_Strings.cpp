class Solution {
public:
    void maxi(string &merged, string &res){
        if(res.empty() || merged.length() < res.length() || (merged.length()== res.length() && merged < res)){
            res = merged;
        }
    }
    string check(string a, string b){
        //1st case: if the second string is present in the first string
        if(a.find(b) != string::npos)//it means we found b in a
            return a;
        
        // 2nd case: if some last characters of a is present in starting of b
        for(int i = min(a.length(), b.length()); i>=0; i--){
            if(a.substr(a.length() - i) == b.substr(0,i)) return a + b.substr(i);
        }
        // in worst case we have to return both
        return a+b;
    }

    string minimumString(string a, string b, string c) {
        vector<string> arr = {a,b,c};
        int n = arr.size();
        string res = "";    
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(i!= j && j != k && k != i){
                        string merged = check(arr[i], arr[j]);
                        merged = check(merged,arr[k]);
                        maxi(merged,res);
                    }
                }
            }
        }
        return res;
    }
};