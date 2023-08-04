/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //edge case
        if(root == NULL) return "";

        string s = "";

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            // if the node is not null add it to string 
            if(node) s.append(to_string(node->val)+ ',');
            else s.append("#,");
            if(node){
                // as we have to get # for null values
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //edge case
        if(data.empty()) return NULL;
        // coverting data string to object
        stringstream s(data);
        string tmp;
        // it will store the first element of string in tmp
        getline(s,tmp,',');
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // left
            getline(s,tmp,',');
            if(tmp == "#") node->left = NULL;
            else{
                TreeNode* lnode = new TreeNode(stoi(tmp));
                node->left = lnode;
                q.push(lnode);
            }
            //right
            getline(s,tmp,',');
            if(tmp == "#") node->right = NULL;
            else{
                TreeNode* rnode = new TreeNode(stoi(tmp));
                node->right = rnode;
                q.push(rnode);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));