class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int i, flag=1, ans=0;
        for(i=0 ; i<energy.size() ; i++)
        {
            if(experience[i]<initialExperience){
                initialExperience += experience[i];
            }
            else if(experience[i]>=initialExperience){
                ans += experience[i] - initialExperience + 1;
                initialExperience += 2*experience[i] - initialExperience + 1;
            }
            if(energy[i]<initialEnergy){
                initialEnergy -= energy[i];
            }
            else if(energy[i]>=initialEnergy){
                ans += energy[i] - initialEnergy + 1;
                initialEnergy = 1;
            }
        }
        return ans;
    }
};