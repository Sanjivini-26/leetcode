/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int smallest;
        auto rec = [&](this auto&& s, TreeNode const* r)
        {
            if(!r) return;
            s(r->left);
            if(--k == 0)
            {
                smallest = r->val;
                throw std::runtime_error("");
            }
            s(r->right);

        };
        try
        {
            rec(root);
        }
        catch(...){}
        return smallest;
    }
};