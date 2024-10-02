#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

void display(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
}

int getHeight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t3 = y->left;

    y->left = x;
    x->right = t3;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node *righRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t3 = x->right;

    x->right = y;
    y->left = t3;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return (createNode(data));
    }
    
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = getBalanceFactor(node);

    // left left case
    if (bf > 1 && data < node->left->data)
    {
        return righRotate(node);
    }

    // right right case
    if (bf < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }

    // left right case
    if (bf > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return righRotate(node);
    }

    // right left case
    if (bf < -1 && data < node->right->data)
    {
        node->right = righRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    display(root);
    return 0;
}