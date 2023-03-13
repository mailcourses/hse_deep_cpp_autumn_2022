#include <vector>
#include <string>
#include <iostream>
#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
        10
       /  \
      5    4
     / \    \
    3   6    9
 
 { "10->5->3", "10->4->9" }
*/

TreeNode* buildTree()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(9);
    
    root->left->right = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->left->right->left = new TreeNode(7);
    
    root->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(9);
    
    return root;
}


void dfs(TreeNode* root, std::vector<std::string>& paths, std::string curStr)
{
    curStr += std::to_string(root->val);
    
    if (root->left == nullptr && root->right == nullptr)
    {
        paths.push_back(curStr);
        return;
    }
    curStr += "->";
    
    if (root->left)
    {
        dfs(root->left, paths, curStr);
    }
    if (root->right)
    {
        dfs(root->right, paths, curStr);
    }
}


// Рекурсивный подход
std::vector<std::string> binaryTreePaths(TreeNode* root)
{
    std::vector<std::string> paths;
    if (root) dfs(root, paths, "");
    
    
    return paths;
}

// Итеративный подход
std::vector<std::string> binaryTreePaths2(TreeNode* root)
{
    std::vector<std::string> paths;
    if (root == nullptr) return {};
    
    std::queue<std::pair<TreeNode*, std::string>> q;
    
    q.push(std::make_pair(root, ""));
    while (!q.empty())
    {
        size_t layerCnt = q.size();
        for (size_t i=0; i < layerCnt; ++i)
        {
            auto [node, prefix] = q.front();
            q.pop();
            
            // is leaf
            if (node->left == nullptr && node->right == nullptr)
            {
                prefix += std::to_string(node->val);
                paths.push_back(prefix);
                continue;
            }
            
            prefix += std::to_string(node->val) + "->";
            if (node->left)
            {
                q.push(std::make_pair(node->left, prefix));
            }
            
            if (node->right)
            {
                q.push(std::make_pair(node->right, prefix));
            }
        }
    }

    
    return paths;
}

int main()
{
    {
        TreeNode *root = buildTree();
        
        
        for (auto el : binaryTreePaths(root))
        {
            std::cout << el << std::endl;
        }
    }
    
    std::cout << "=========" << std::endl;
    
    {
        TreeNode *root = buildTree();
        
        
        for (auto el : binaryTreePaths2(root))
        {
            std::cout << el << std::endl;
        }
    }
    
    return 0;
}
