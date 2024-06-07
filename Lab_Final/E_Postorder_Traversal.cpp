#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
private:
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorder_map,
                              int inorder_start, int inorder_end, int &preorder_index)
    {
        if (preorder_index >= preorder.size() || inorder_start > inorder_end)

            return nullptr;

        int root_value = preorder[preorder_index++];
        TreeNode *root = new TreeNode(root_value);

        int inorder_root_index = inorder_map[root_value];

        root->left = buildTreeHelper(preorder, inorder, inorder_map, inorder_start, inorder_root_index - 1, preorder_index);
        root->right = buildTreeHelper(preorder, inorder, inorder_map, inorder_root_index + 1, inorder_end, preorder_index);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i;
        }

        int preorder_index = 0;
        return buildTreeHelper(preorder, inorder, inorder_map, 0, inorder.size() - 1, preorder_index);
    }
};

void inorderTraversal(TreeNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

void postTraversal(TreeNode *root)
{
    if (root)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    int n, x;
    vector<int> preorder;
    vector<int> inorder;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        preorder.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        inorder.push_back(x);
    }

    Tree tree;
    TreeNode *root = tree.buildTree(preorder, inorder);

    postTraversal(root);

    return 0;
}
