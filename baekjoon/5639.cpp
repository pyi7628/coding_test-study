#include <iostream>
#include <stdlib.h>
using namespace std;
// int tree[1000001];
struct NODE
{
    NODE *parent;
    NODE *left;
    NODE *right;
    int num;
};
NODE *root;
int n, prev_n = 1000001;

NODE *find_lower_bound(NODE *node, int num)
{
    NODE *max_node;
    NODE *cur = node;
    while (cur->parent)
    {
        cur = cur->parent;
        if (cur->num > max_node->num)
            max_node = cur;
        if (num < cur->num)
        {
            printf("find1: %d %d\n", num, cur->left->num);
            return cur->left;
        }
    }
    printf("find2: %d %d\n", num, max_node->num);
    return max_node;
}

void postorder(NODE *node)
{

    if (node->left)
        postorder(node->left);
    if (node->right)
        postorder(node->right);
    printf("ans: %d\n", node->num);
}
int main()
{
    int cur_idx = 0;
    cin >> n;
    root = (NODE *)malloc(sizeof(NODE));
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
    root->num = n;
    NODE *cur_node = root;
    for (int i = 1; i < 9; i++)
    // while (true)
    {
        NODE *new_node = (NODE *)malloc(sizeof(NODE));
        cin >> n;
        if (cin.eof() == true)
            break;
        if (prev_n < n)
        {
            cur_node = find_lower_bound(cur_node, n);
            new_node->num = n;
            new_node->parent = cur_node;
            new_node->left = NULL;
            new_node->right = NULL;
            cur_node->right = new_node;
            cur_node = new_node;
        }
        else
        {
            new_node->num = n;
            new_node->parent = cur_node;
            new_node->left = NULL;
            new_node->right = NULL;
            cur_node->left = new_node;
            cur_node = new_node;
        }
        prev_n = n;
    }
    postorder(root);
    return 0;
}