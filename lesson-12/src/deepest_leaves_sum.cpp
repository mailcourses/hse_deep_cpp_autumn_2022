#include <cassert>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


size_t maxDepth = 0;
int accum = 0;

TreeNode* buildTree()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(19);
    
    root->left->right = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(7);
    
    root->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(9);
    
    return root;
}

void dfs(TreeNode* node, size_t depth)
{
    if (depth > maxDepth)
    {
        maxDepth = depth;
        accum = 0;
        accum += node->val;
    }
    else if (depth == maxDepth)
    {
        accum += node->val;
    }
    
    if (node->left == nullptr && node->right == nullptr)
    {
        return;
    }
    
    if (node->left) dfs(node->left, depth+1);
    if (node->right) dfs(node->right, depth+1);
    
}

int deepestLeavesSum(TreeNode* root) {
    maxDepth = 0;
    accum = 0;
    
    if (root == nullptr) return 0;
    
    dfs(root, 1);
    return accum;
}

int main()
{
    TreeNode* root = buildTree();
    
    int actual = deepestLeavesSum(root);
    std::cout << actual << std::endl;
    
    assert(actual == 24);
    
    assert(deepestLeavesSum(new TreeNode(3)) == 3 );
    
    assert(deepestLeavesSum(nullptr) == 0 );
}
