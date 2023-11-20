class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        long long totalMinutes =  garbage[0].size();  
        long long currentTravelTime = 0; 
        vector<int> lastGarbageIndices(3, -1);  
        for (int houseIndex = 1; houseIndex < garbage.size(); houseIndex++) {
            
            totalMinutes += garbage[houseIndex].size();
            if (garbage[houseIndex].find("M") != garbage[houseIndex].npos) 
                lastGarbageIndices[0] = houseIndex - 1;
            if (garbage[houseIndex].find("P") != garbage[houseIndex].npos) 
                lastGarbageIndices[1] = houseIndex - 1;
            if (garbage[houseIndex].find("G") != garbage[houseIndex].npos) 
                lastGarbageIndices[2] = houseIndex - 1;
        }

        for (int travelIndex = 0; travelIndex < travel.size(); travelIndex++) {
            
            currentTravelTime += travel[travelIndex];
            for (int truckIndex = 0; truckIndex < 3; truckIndex++) {
                if (lastGarbageIndices[truckIndex] == travelIndex) {
                    totalMinutes += currentTravelTime;
                }
            }
        }

        return totalMinutes;
    }
};