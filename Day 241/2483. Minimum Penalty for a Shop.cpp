class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>preN(n,0),sufY(n,0);
        preN[0] = (customers[0]=='N')? 1:0;
        for(int i = 1; i<customers.size(); i++){
            if(customers[i] == 'N') {
                preN[i] = preN[i-1] + 1;
            }
            else{
                preN[i] = preN[i-1];
            }
        }
        sufY[n-1] = (customers[n-1] == 'Y')? 1:0;
        for(int i = n-2; i>=0;i--){
            if(customers[i] == 'Y'){
                sufY[i] = sufY[i+1] + 1;
            }
            else sufY[i] = sufY[i+1];
        }

        int res = INT_MAX,ind = 0;
        for(int i = 0; i<n-1; i++){
            int tmp = preN[i] + sufY[i+1];
            if(tmp < res){
                res = tmp;
                ind = i;
            }
        }
        ind++;// to add for 0th hour
        //check for 0th hour
        if(sufY[0]<=res){
            ind = 0;
            res = sufY[0];
        }
        // check for nth hour
        if(preN[n-1]<res){
            ind = n;
        }
        return ind;

    }
};