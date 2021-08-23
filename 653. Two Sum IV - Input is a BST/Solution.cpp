 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> USet_Num;
        return Traversal(root, k, USet_Num);
    }

    bool Traversal(TreeNode* root, int k, unordered_set<int>& USet_Num)
    {
        if (root == nullptr)
            return false;

        int iSub = k - root->val;

        if (USet_Num.count(iSub))
        {
            return true;
        }

        USet_Num.insert(root->val);
        return Traversal(root->left, k, USet_Num) || Traversal(root->right, k , USet_Num);
    }
};
