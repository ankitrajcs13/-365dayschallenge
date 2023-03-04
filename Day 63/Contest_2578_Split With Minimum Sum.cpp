class Solution {
public:
    int splitNum(int num) {
        
        string myast = to_string(num);
        sort(myast.begin(), myast.end());
        
        // now create two splits for minimum
        string myst1 = "";
        string myst2 = "";
        for(int i = 0; i<myast.length(); i+=2)
            myst1 += myast[i];
        for(int i = 1; i<myast.length(); i+=2)
            myst2 += myast[i];
        int myin1 = stoi(myst1);
        int myin2 = stoi(myst2);
        
        return myin1+myin2;
        
    }
};