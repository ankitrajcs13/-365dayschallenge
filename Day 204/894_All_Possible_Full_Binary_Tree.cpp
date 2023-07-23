class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        vector<TreeNode*> list;
        if (n == 1) {
            list.push_back(new TreeNode(0));
        } else {
            for (int i = 1; i <= n - 1; i += 2) {
                vector<TreeNode*> lTrees = allPossibleFBT(i);
                vector<TreeNode*> rTrees = allPossibleFBT(n - i - 1);

                for (TreeNode* lt : lTrees) {
                    for (TreeNode* rt : rTrees) {
                        list.push_back(new TreeNode(0, lt, rt));
                    }
                }
            }
        }

        return list;
    }
};