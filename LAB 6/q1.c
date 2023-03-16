# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node *new_node(int val){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;
}

int count_nodes(Node *root){
    if(root == NULL)
        return 0;

    else{
        return 1 + count_nodes(root -> left) + count_nodes(root -> right);
    }
}

int main(){
    Node *n = new_node(7);
    n -> left = new_node(8);
    n -> right = new_node(3);
    n -> left -> left = new_node(5);
    n -> left -> right = new_node(4);
    n -> right -> left = new_node(1);
    n -> right -> right = new_node(6);

    int c = count_nodes(n);
    printf("%d is the number of nodes and also the opcount\n", c);
}