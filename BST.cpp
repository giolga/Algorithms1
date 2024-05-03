#include <bits/stdc++.h>
using namespace std;

struct node { int key;  struct node *left, *right;};

struct node* newNode(int item){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node* root){
    if (root != NULL) {
        preorder(root->left);
        cout<<root->key<<" ";
        preorder(root->right);
    }
}

void inorder(struct node* root){
    if (root != NULL) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void postorder(struct node* root){
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" "; 
    }
}

struct node* insert(struct node* node, int key){
    if (node == NULL) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);

    return node;
}

int findMin(node* root) {
    if (root->left == NULL) return(root->key);
    else  findMin (root->left);

    return root->key;//by me!!!
}
int findMax(node* root) {
    if (root->right == NULL) return(root->key);
    else  findMax (root->right);

    return root->key;//by me!!!
}


int main() {
struct node* root = NULL;
    root = insert(root, 100); insert(root, 50); insert(root, 150);
    insert(root, 25); insert(root, 75); insert(root, 125);  insert(root, 175);
    inorder(root);
    cout << endl;
    cout << findMin(root);//?????
}
