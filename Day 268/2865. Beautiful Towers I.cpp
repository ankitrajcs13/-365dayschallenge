// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0;
        int n = maxHeights.size();
        for(int i = 0; i<n; i++){
            long long minH = maxHeights[i]; long long tmp = maxHeights[i];

            // for left
            for(int j = i-1; j>=0; j--){
                minH = min((long long)maxHeights[j] , minH);
                tmp += minH;
            }
            cout<<tmp<<" For left " << j << " "<< i;
            minH = maxHeights[i];

            // for right
            for(int j = i+1; j<n; j++){
                minH = min((long long)maxHeights[j], minH);
                tmp += minH;
            }
            cout<<tmp<<" For right " << j << " "<< i;
            res = max(res,tmp);
        }
        return res;
    }

int main() {
    // Write C++ code here
    vector<int>h = {6,5,3,9,2,7};
    cout<<maximumSumOfHeights(h);

    return 0;
}