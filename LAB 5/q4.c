#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* new_node(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    return 1 + ((left_height > right_height) ? left_height : right_height);
}

int diameter(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    return ((left_height + right_height + 1) > (left_diameter > right_diameter ? left_diameter : right_diameter))
            ? (left_height + right_height + 1)
            : (left_diameter > right_diameter ? left_diameter : right_diameter);
}

int main() {
    struct node* root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    printf("The diameter of the binary tree is %d\n", diameter(root));

    return 0;
}