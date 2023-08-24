class Solution {
public:
    int MAX_WIDTH;
    string findLine(int i,int j, int eachGaddhaSpace,int extraSpaceGaddhe,vector<string>& words){
        string line;
        for(int k = i; k<j; k++){
            line+=words[k];

            if(k == j-1){// last word of our line->no space after that
                break;
            }

            for(int z = 1; z<=eachGaddhaSpace; z++){
                line+=" ";
            }
            if(extraSpaceGaddhe > 0){
                line+=" ";
                extraSpaceGaddhe--;
            }
        }

        while(line.length() < MAX_WIDTH){
            line+=" ";
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        MAX_WIDTH = maxWidth;

        int i = 0; 
        while(i<n){
            int lettersCount = words[i].length();
            int j = i+1;
            int gaddhe = 0;

            while(j<n && words[j].length() + 1 + gaddhe + lettersCount <= maxWidth){
                lettersCount += words[j].length();
                gaddhe++;
                j++;
            }
            int remainingGaddhe = maxWidth- lettersCount;

            int eachGaddhaSpace = gaddhe== 0?0: remainingGaddhe/gaddhe;
            int extraSpaceGaddhe = gaddhe==0?0: remainingGaddhe%gaddhe;

            if(j== n){ // last line->left justified
                eachGaddhaSpace = 1;
                extraSpaceGaddhe = 0;
            }

            res.push_back(findLine(i,j, eachGaddhaSpace,extraSpaceGaddhe,words));
            i = j;
        }
        return res;
    }
};