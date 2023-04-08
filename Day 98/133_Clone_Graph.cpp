/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
        unordered_map<Node* , Node*> mp; 
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
      if(mp.find(node) == mp.end()) 
        {
            mp[node] = new Node(node -> val, {}); 
            for(auto adj: node -> neighbors) mp[node] -> neighbors.push_back(cloneGraph(adj)); 
        }
        return mp[node];

        // if(node == NULL) return NULL;


        // // by bfs traversal
        // queue<Node*> q;

        // q.push(node);
        // Node* clone = new Node(node->val, {});
        // // store it in map
        // mp[node] = clone;

        // // do bfs
        // while(!q.empty()){
        //     Node* t = q.front();
        //     q.pop();
        //     // create a vector to store adjacency
        //     for(auto it: t->neighbors){
        //         // if it is not visited
        //         if(!mp[it]){
        //             // create a new new
        //             mp[it] = new Node(it->val, {});
        //             q.push(it);
        //         }
        //         mp[t]->neighbors.push_back(mp[it]);
        //     }
        // }
        // return mp[node];

    }
};