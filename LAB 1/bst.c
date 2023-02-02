# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *newnode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

struct node *insert(struct node *x,int key){
    if(x == NULL)
        return newnode(key);

    if(key < x -> data)
        x -> left = insert(x -> left,key);

    else if(key > x -> data)
        x -> right = insert(x -> right,key);

    return x;
    
}

void inorder(struct node *x){
    if(x != NULL){
        inorder(x -> left);
        printf("%d ",x -> data);
        inorder(x -> right);
    }
}

void preorder(struct node *x){
    if(x == NULL)
        return;

    preorder(x -> left);
    preorder(x -> right);
    printf("%d ",x -> data);
}

struct node *search(struct node *x,int key){
    if(x == NULL || x -> data == key)
        return x;

    if(x -> data < key)
        return search(x -> right,key);

    return search(x -> left,key);
}

int main(){
    struct node *root = NULL;

    int x,n;
    printf("Enter number of nodes : ");
    scanf("%d",&x);

    for(int i = 1;i <= x;i++){
        int k = 0;
        scanf("%d",&k);
        if(root == NULL)
            root = insert(root,k);
        
        else    
            insert(root,k);
    }
    
    printf("Enter key to be searched : ");
    scanf("%d",&n);

    if(search(root,n) != NULL){
        printf("Key found\n");
        preorder(root);
    }

    else{
        root = insert(root,n);
        inorder(root);
        printf("\n");
    }

}