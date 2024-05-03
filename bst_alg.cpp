#include <iostream>
using namespace std;

struct node {
    int key;
    node* left,* right;
};

struct node* newNode(int item) {
    node* temp = new struct node;

    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
};

struct node* insert(struct node* node, int key) {
    if(node == NULL) return newNode(key);

    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);

    return node;
};

struct node* search(struct node* root, int key) {
    if(root->key == key) return root;

    if(root->key > key) return search(root->left, key);
    return search(root->right, key);

};

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void preorder(struct node* root) {
    if(root != NULL) {
        cout << root->key << " ";
        postorder(root->left);
        postorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 100); insert(root, 50); insert(root, 150);
    insert(root, 25); insert(root, 75); insert(root, 125);  insert(root, 175);

    // insert(root, 11);
    // insert(root, 16);
    // insert(root, 19);
    // insert(root, 30);
    // insert(root, 47);
    // insert(root, 9);
    // insert(root, 17);
    // insert(root, 27);
    // insert(root, 38);
    // insert(root, 11);
    // insert(root, 14);
    // insert(root, 32);

    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Postorder: ";postorder(root); cout << endl;

    int key = 100;// if key equals to NULL, it means there is no such an element in BST therefor we have to output "Not found"
    if(search(root, key) != NULL) cout << "Key Found: " << key << search(root, 1);
        else printf("No such element exists");
}