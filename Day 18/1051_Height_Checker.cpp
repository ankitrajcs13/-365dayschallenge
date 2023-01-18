class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int size = heights.size();
        int expected[size];
        int cnt = 0;
        // create the new array and copy all the elements from the old array
        for(int i = 0; i<size; i++){
            expected[i] = heights[i];
        }
        // Then sort this so that it become the expected
        sort(expected, expected+size);
        for(int i = 0; i<size; i++){
            // And check which elements are not matching with the old array
            if(heights[i] != expected[i])
                cnt++;
        }
        return cnt;
    }
};
// TC - O(N)
// SC - O(N)

// 2nd approach - Using Map and vector

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // using counting sort 
    map<int,int> mp;  // to store no. of count
    
    for( auto i: heights){
        mp[i]++;
    }        
    
    vector<int> expected;  // to store the elements in sorted order
    
    for( auto it : mp ){
        while( it.second != 0){
            expected.push_back(it.first);
            it.second--;
        }
    }

    int i = 0;
    int count = 0;
    while( i<expected.size() ){
        if( expected[i] != heights[i] ){
            count++;
        }
        i++;
    }
    
    return count;
    }
};