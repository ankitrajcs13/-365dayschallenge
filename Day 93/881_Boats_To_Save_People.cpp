class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end(), greater<int>());

        // using two pointer approach
        int i = 0, j= people.size()-1, cnt = 0;
        
        while(i<=j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;

            }
            else // only one can go alone
                i++;
            cnt++;
        }
        return cnt;




    }
};