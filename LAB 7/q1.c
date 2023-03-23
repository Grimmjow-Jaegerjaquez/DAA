# include <stdio.h>
# include <stdlib.h>

typedef struct node{

    int data;
    struct node *left;
    struct node *right;

}Node;

Node *new_node(int val){
    
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;

}

int height(Node *root){
    
    if(root == NULL)
        return 0;

    else{
        int lheight = height(root -> left);
        int rheight = height(root -> right);

        if(lheight > rheight)
            return lheight + 1;

        else
            return rheight + 1;
    }
}

int balanceFactor(Node *root){
    
    if(root == NULL)
        return 0;

    else{
        int lheight = height(root -> left);
        int rheight = height(root -> right);

        return lheight - rheight;
    }
}

Node *insert(Node *root, int val){

    if(root == NULL)
        return new_node(val);

    if(val < root -> data)
        root -> left = insert(root -> left, val);

    else if(val > root -> data)
        root -> right = insert(root -> right, val);

    return root;
}

void printBalanceFactors(Node *root){
    if(root == NULL)
        return;

    printf("Node %d : balance factor = %d\n", root -> data, balanceFactor(root));

    printBalanceFactors(root -> left);
    printBalanceFactors(root -> right);
}

int main(){
    Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    printBalanceFactors(root);

    return 0;

}