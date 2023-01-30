class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stuCount = students.size();
        int circ_sand = 0, squa_sand = 0;

        for(int i = 0; i<stuCount; i++){
            if(students[i] == 0)
                circ_sand++;
            else
                squa_sand++;
        }
        for(int i = 0; i<students.size(); i++){
            if(sandwiches[i] == 0){
                if(circ_sand > 0){
                    stuCount--;
                    circ_sand--;
                }
                else
                    return stuCount;
            }
            else{
                if(squa_sand>0){
                    stuCount--;
                    squa_sand--;
                }
                else
                    return stuCount;
            }
        }
        return stuCount;
    }
};

// 2nd Approach

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> choice;
        for(int i= 0; i<n; i++){
            choice.push(students[i]);
        }
        int rot = 0,cnt = 0;
        while(choice.size() && rot < choice.size()){
            if(choice.front() == sandwiches[cnt]){
                choice.pop();
                cnt++;
                rot = 0;
            }
            else{// remove from front and push back in last
                int d = choice.front();
                choice.pop();
                choice.push(d);
                rot++;
            }
        }
        return choice.size();

    }
};

// TC- O(N)
// SC- O(N)