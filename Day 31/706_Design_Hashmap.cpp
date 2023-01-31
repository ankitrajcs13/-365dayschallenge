// create a linkedlist class
class Node{
public:
    int val;
    int key;
    Node* next;
    Node(int _key,int _val){
        val = _val;
        key = _key;
        next= NULL;
    }
};
class MyHashMap {
public:
    // initializing head pointer to NULL
    Node* head = NULL;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        // if the key is present 
        Node * curr = head;
        while(curr){
            if(curr->key== key){
                curr->val = value;
                return;
            }
            curr= curr->next;
        }

        if(!head){
            head = new Node(key,value);
        }
        else{
            Node* tmp = new Node(key,value);
            tmp->next = head;
            head = tmp;
        }
    }
    
    int get(int key) {
        Node * curr = head;
        while(curr){
            if(curr->key== key){
                return curr->val;
            }
            curr= curr->next;
        }
        // if not found then
        return -1;
    }
    
    void remove(int key) {
        Node * curr = head, *prev = NULL;
        while(curr){
            if(curr->key== key)
                break;
            prev = curr;
            curr= curr->next;
        }
        if(!curr) return;

        // means there is only one node
        if(!prev) head = head -> next;
        // else point the prev pointer to next of curr
        else 
            prev -> next = curr -> next;
        
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */



// 2nd Approach

class MyHashMap {
public:
//approach using std map
    unordered_map<int, int> umap;
    MyHashMap() { 
    }
    
    void put(int key, int value) {
        umap[key]=value;
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end())  
           return -1;
        auto it=umap.find(key);
        return it->second;
    }
    
    void remove(int key) {
        umap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */