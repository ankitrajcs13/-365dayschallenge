class TrieNode {

    public:
        char data;
        TrieNode * children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
            
        }
};

class Trie {

    TrieNode* root;
public:

    /** Initialize your data structure here. */
    Trie() {

        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        // Assumption- Word will be in Caps

        int index = word[0] - 'a';
        TrieNode* child;

        // If Present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child,word.substr(1));

    }
    void insert(string word) {
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0 ){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        // Present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child,word.substr(1));
    }
    bool search(string word) {
        
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0 ){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        // Present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // Absent
            return false;
        }

        // Recursion
        return prefixUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};


// 2nd Approach

class Trie {
public:
    unordered_map<string,int> mp1,mp2;
    Trie() {
        
    }
    
    void insert(string word) {
        mp1[word]++;
        string s;
        for(auto it:word){
            s.push_back(it);
            if(mp2[s] == 0) mp2[s]++;
        }
    }
    
    bool search(string word) {
        if(mp1[word]) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp2[prefix]) return true;
        return false;
    }
};