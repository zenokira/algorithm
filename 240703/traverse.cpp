nclude <iostream>
#include <algorithm>
#include <vector>

#define int int64_t

using namespace std;

struct tree
{
    char value;
    tree* left;
    tree* right;
};

char preorder[1000];
char inorder[1000];
tree* srcTree;

int get_inorder_index(int begin, int end, char target)
{
    for (int i = begin; i <= end; i++)
    {
        if (inorder[i] == target) return i;
    }
    return -1;
}

tree* tree_restore(int begin, int end)
{
    static int preIdx = 0;
    tree* newNode = NULL;
    if (begin <= end && preorder[preIdx] != '\0') {
        newNode = new tree;
        newNode->value = preorder[preIdx++];
        int idx = get_inorder_index(begin, end, newNode->value);

        newNode->left = tree_restore(begin, idx - 1);
        newNode->right = tree_restore(idx + 1, end);
    }
    return newNode;
}

void post(tree* t)
{
    if (t == NULL) return;
    post(t->left);
    post(t->right);
    cout << t->value;
}

int32_t main()
{
    cin >> inorder >> preorder;

    string str(inorder);
    int N = str.length();

    srcTree = tree_restore(0, N);
    post(srcTree);
}
