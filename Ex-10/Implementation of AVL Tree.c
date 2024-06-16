#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node { 
    int data; 
    struct Node *left; 
    struct Node *right; 
    int height; 
} Node; 
 
int height(Node *node) { 
    if (node == NULL) 
        return 0; 
    return node->height; 
} 

int balance_factor(Node *node) { 
    if (node == NULL) 
        return 0; 
    return height(node->left) - height(node->right); 
} 
 
Node* newNode(int data) { 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->height = 1; 
    return node; 
} 
 
Node* rotate_right(Node *y) { 
    Node *x = y->left; 
    Node *T2 = x->right; 
    x->right = y; 
    y->left = T2; 
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right)); 
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right)); 
    return x; 
} 
 
Node* rotate_left(Node *x) { 
    Node *y = x->right; 
    Node *T2 = y->left; 
    y->left = x; 
    x->right = T2; 
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right)); 
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right)); 
    return y; 
} 
 
Node* insert(Node *node, int data) { 
    if (node == NULL) 
        return newNode(data); 
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
    else 
        return node; 
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right)); 
    int balance = balance_factor(node); 
    if (balance > 1 && data < node->left->data) 
        return rotate_right(node); 
    if (balance < -1 && data > node->right->data) 
        return rotate_left(node); 
    if (balance > 1 && data > node->left->data) { 
        node->left = rotate_left(node->left); 
        return rotate_right(node); 
    } 
    if (balance < -1 && data < node->right->data) { 
        node->right = rotate_right(node->right); 
        return rotate_left(node); 
    } 
    return node; 
} 
 
Node* minValueNode(Node *node) { 
    Node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 
 
Node* deleteNode(Node *root, int data) { 
    if (root == NULL) 
        return root; 
    if (data < root->data) 
        root->left = deleteNode(root->left, data); 
    else if (data > root->data) 
        root->right = deleteNode(root->right, data); 
    else { 
        if (root->left == NULL || root->right == NULL) { 
            Node *temp = root->left ? root->left : root->right; 
            if (temp == NULL) { 
                temp = root; 
                root = NULL; 
            } else 
                *root = *temp; 
            free(temp); 
        } else { 
            Node *temp = minValueNode(root->right); 
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data); 
        } 
    } 
    if (root == NULL) 
        return root; 
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right)); 
    int balance = balance_factor(root); 
    if (balance > 1 && balance_factor(root->left) >= 0) 
        return rotate_right(root); 
    if (balance > 1 && balance_factor(root->left) < 0) { 
        root->left = rotate_left(root->left); 
        return rotate_right(root); 
    } 
    if (balance < -1 && balance_factor(root->right) <= 0) 
        return rotate_left(root); 
    if (balance < -1 && balance_factor(root->right) > 0) { 
        root->right = rotate_right(root->right); 
        return rotate_left(root); 
    } 
    return root; 
} 
 
void inorder(Node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 
 
int main() { 
    Node *root = NULL; 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    printf("Inorder traversal of the constructed AVL tree: "); 
    inorder(root); 
    printf("\n"); 
    printf("Delete node 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal after deletion: "); 
    inorder(root); 
    printf("\n"); 
    return 0; 
}
