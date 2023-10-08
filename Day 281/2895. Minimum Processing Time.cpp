class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int ankiRes = INT_MIN;
        int ankiN = tasks.size();
        // to get max at last
        reverse(tasks.begin(), tasks.end());
        int pN = processorTime.size();
        for(int i = 0; i<pN; i++){
            //cout<<processorTime[i];
            int tmp = INT_MIN;
            for(int t = i *4 ;t < i*4+4; t++) tmp = max(tmp, processorTime[i] + tasks[t]);
            ankiRes = max(ankiRes,tmp);
        }
        return ankiRes;
    }
};