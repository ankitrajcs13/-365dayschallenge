class Solution {
public:
//     int isDiv(string n){
        
//         int s = n.length();
//         vector<string> rt = {"00", "25", "50", "75"};

//         if (s < 2) return false;
        

//         string lastTwoDigits = n.substr(s - 2, 2);

//         for (int i = 0; i < 4; i++) {
//             if (lastTwoDigits == rt[i]) {
//                 return true; 
//             }
//         }

//         return false;
//     }
    int minimumOperations(string num) {
        int ankicnt = INT_MAX;
        int na = num.size();
        if(na == 1) return 1;
        else if(na == 2){
            if(num == "25" || num == "50" || num == "75" || num == "00") return 0;
            else if(num[0] == '0' || num[1] == '0') return 1;
            else return 2;
        }
        int cn = count(num.begin(), num.end(), '0');
        for(int i = 0; i<na; i++){
            for(int j = i+1; j<na; j++){
                int nd = (num[i] -'0') * 10 + (num[j]-'0');
                // cout<<nd<<endl;
                if(nd % 25 == 0){
                    int an1 = j-i-1;
                    int an2 = na-(j+1);
                    ankicnt = min(ankicnt, an1+an2);
                    // cout<<ankicnt<<an1<<an2;
                }
            }
        }
        if(ankicnt == INT_MAX) return na-cn;
        return ankicnt;
    }
};