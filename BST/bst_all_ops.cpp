#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// insertion
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        struct Node* newNode = new Node();
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// searching
  void search(struct Node* root, int val) {
    if (root == NULL) {
        cout<< "value is not present\n";
    } else if (root->data == val) {
        cout << "value is present in the tree\n";
    } else if (val <= root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}



// deletion
struct Node* deleteNode(struct Node* root, int val) {
    if (root == NULL) {
        return root;
    } else if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node to be deleted has one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node to be deleted has two children
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    int choice, val;

    do {
        cout << "\nBinary Search Tree Operations\n";
        cout << "-----------------------------\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Delete a Node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> val;
                search(root, val);
                
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 7);

    return 0;
}
