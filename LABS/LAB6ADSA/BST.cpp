#include <iostream>
using namespace std;

class BST_Node
{
private:
    int data;
    BST_Node *left;
    BST_Node *right;

public:
    BST_Node();
    BST_Node(int value);
    bool IsEmpty(BST_Node *root);
    BST_Node *Search(BST_Node *root, int value);
    BST_Node *InsertWithoutDuplication(BST_Node *root, int value);
    void InOrder(BST_Node *root);
    void PreOrder(BST_Node *root);
    void PostOrder(BST_Node *root);
    int printSmallest(BST_Node *root);
    int printLargest(BST_Node *root);
    void printLeaves(BST_Node *root);
    int CountInternalNodes(BST_Node *root);
    int height(BST_Node *root);
    int depth(BST_Node* root);
};

// constructor
BST_Node::BST_Node()
{
    data = 0;
    left = NULL;
    right = NULL;
}

BST_Node::BST_Node(int value)
{
    data = value;
    left = right = NULL;
}

bool BST_Node::IsEmpty(BST_Node *root)
{
    return root == NULL;
}

// returns the node in which value is found
BST_Node *BST_Node::Search(BST_Node *root, int value)
{
    // base case
    if (root == NULL) // If the subtree is empty or the value is not found
    {
        return NULL;
    }

    // base case
    if (root->data == value)
    {
        return root; // Value found in the current node
    }

    else if (value < root->data)
    {
        return Search(root->left, value);
    }

    else
    {
        return Search(root->right, value);
    }
}

// inserts sorted
BST_Node *BST_Node::InsertWithoutDuplication(BST_Node *root, int value)
{
    // Base case for recursion
    if (root == NULL)
    {
        return new BST_Node(value); // Create a new node with the given value
    }

    if (value < root->data)
    {
        root->left = InsertWithoutDuplication(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = InsertWithoutDuplication(root->right, value);
    }

    else
    {
        cout << "Node already exists! Duplication not allowed." << endl;
    }
    return root;
}

void BST_Node::InOrder(BST_Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data;
    cout << " ";
    InOrder(root->right);
}

void BST_Node::PreOrder(BST_Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data;
    cout << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void BST_Node::PostOrder(BST_Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;
    cout << " ";
}

int BST_Node::printSmallest(BST_Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->left != NULL)
    {
        return printSmallest(root->left);
    }

    // while (root->left != NULL)
    // {
    //     root = root->left;
    // }

    return root->data;
}

int BST_Node::printLargest(BST_Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->right != NULL)
    {
        return printLargest(root->right);
    }

    // while (root->right != NULL)
    // {
    //     root = root->right;
    // }

    return root->data;
}

// traverses a tree and prints only its leaf nodes
void BST_Node::printLeaves(BST_Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // base case
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    // else traverse the subtrees
    printLeaves(root->left);
    printLeaves(root->right);
}

// counts and returns the number of internal nodes in a binary tree
int BST_Node::CountInternalNodes(BST_Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    // Initialize count to 0
    int count = 0;

    // If the node has either left or right children, increment the count
    if (root->left != NULL || root->right != NULL)
    {
        count++;
    }

    // Recursively count internal nodes in left and right subtrees
    count += CountInternalNodes(root->left);
    count += CountInternalNodes(root->right);

    return count;
}

int BST_Node::height(BST_Node* root)
{
    // base case: empty tree has a height of 0
    if (root == nullptr) {
        return 0;
    }
 
    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}

int BST_Node::depth(BST_Node* root)
{
    if (root == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = depth(root->left);
        int rDepth = depth(root->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
 

int main()
{
    BST_Node *root = NULL; // Initialize root to NULL
    BST_Node BST;
    root = BST.InsertWithoutDuplication(root, 12);
    root = BST.InsertWithoutDuplication(root, 11);
    root = BST.InsertWithoutDuplication(root, 13);
    root = BST.InsertWithoutDuplication(root, 14);
    root = BST.InsertWithoutDuplication(root, 10);
    root = BST.InsertWithoutDuplication(root, 9);
    cout << endl;
    cout << "InOrder traversal: ";
    BST.InOrder(root);
    cout << endl;
    cout << "PreOrder traversal: ";
    BST.PreOrder(root);
    cout << endl;
    cout << "PostOrder traversal: ";
    BST.PostOrder(root);
    cout << endl;

    // cout << BST.Search(root, 15);
    cout << "Smallest element: " << BST.printSmallest(root) << endl;
    cout << "Largest element: " << BST.printLargest(root) << endl;
    cout << "Leaf Nodes: ";
    BST.printLeaves(root);
    cout << endl;
    cout << "Number of Internal Nodes: " << BST.CountInternalNodes(root) << endl;
    cout << "Height: " << BST.height(root) << endl;
    cout << "Depth: " << BST.depth(root) << endl;

    return 0;
}
