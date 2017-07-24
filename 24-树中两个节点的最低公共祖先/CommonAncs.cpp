/* 只用一次遍历解决LCA */
#include <iostream>
using namespace std;
struct Node
{
    struct Node *left, *right;
    int key;
};
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// 返回n1和n2的 LCA的指针
// 假设n1和n2都出现在树中
struct Node *findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL) return NULL;

    // 只要n1 或 n2 的任一个匹配即可
    //  (注意：如果 一个节点是另一个祖先，则返回的是祖先节点。因为递归是要返回到祖先的 )
    if (root->key == n1 || root->key == n2)
        return root;
    // 分别在左右子树查找
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
    // 如果都返回非空指针 Non-NULL, 则说明两个节点分别出现了在两个子树中，则当前节点肯定为LCA
    if (left_lca && right_lca)  return root;
    // 如果一个为空，在说明LCA在另一个子树
    return (left_lca != NULL)? left_lca: right_lca;
}

//测试
int main()
{
    // 构造上面图中的树
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key;
    return 0;
}