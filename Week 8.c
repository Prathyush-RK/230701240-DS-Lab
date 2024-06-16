#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
 

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct TreeNode* buildTree() {
    int data;
    struct TreeNode *root = NULL;
    
    printf("Enter data (Enter -1 to stop): ");
    scanf("%d", &data);
    
    if (data == -1) return NULL; 
    root = createNode(data);
    
    printf("Enter left child of %d:\n", data);
    root->left = buildTree();
    
    printf("Enter right child of %d:\n", data);
    root->right = buildTree();
    
    return root;
}

int main() {
    printf("Enter the binary tree (Enter -1 to stop):\n");
    struct TreeNode* root = buildTree();

    printf("\nIn-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
