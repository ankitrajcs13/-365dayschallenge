class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int AnkiS = A.size();
        vector<int> AnkiVecAns;
        
        
        
        for(int i = 0; i<AnkiS; i++){
            // map to store occurence of both arrays
            unordered_map<int,int> AnkiMP1;
            unordered_map<int,int> AnkiMP2;
            for(int j = 0; j<=i; j++){
                AnkiMP1[A[j]]++;
                AnkiMP2[B[j]]++;
            }
            int AnkiTmp = 0;
            // now find the number of similar items in every ith position
            for(int j = 0; j<=i; j++){
                if(AnkiMP1.find(A[j]) != AnkiMP1.end() && AnkiMP2.find(B[j]) != AnkiMP2.end() )
                    AnkiTmp = AnkiTmp +  min(AnkiMP1[A[j]], AnkiMP2[A[j]]);
            }
            AnkiVecAns.push_back(AnkiTmp);
        }
        
        return AnkiVecAns;
    }
};