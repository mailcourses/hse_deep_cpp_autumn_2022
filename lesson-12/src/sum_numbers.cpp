#include <cassert>
#include <queue>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
         1
        / \
       2   3
      /
     4
    / \
   5   6
1245 + 1246 + 13 = ???



            1
           / \
          9   0
        /   \
       1     8
      / \   / \
     7   4 9   4
     
     1917+1914+1989+1984 + 10 = 7814
*/

            


TreeNode* buildTree()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    
    root->left->right = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(7);
    
    root->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(9);
    
    return root;
}

int sumNumbers(TreeNode* root)
{
    if (!root) return 0;
    int result = 0;
    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 0));
    while (!q.empty())
    {
        auto [node, num] = q.front();
        q.pop();
        
        if (node->left) q.push(std::make_pair(node->left, num*10 + node->val));
        if (node->right) q.push(std::make_pair(node->right, num*10 + node->val));
        
        if (!node->left && !node->right) result += (num*10 + node->val);
    }
    return result;
}


int main()
{
    auto root = buildTree();
    assert(sumNumbers(root) == 7814);
    
}
