#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node {
    int value;

    Node* left, *right;
};


Node* init_tree(int data)
{

    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* create_node(int data) {

    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {

    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

int tree_height(Node* root) {

    if (!root)
        return 0;
    else {

        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(Node* root, int level_no) {

    if (!root)
        return;
    if (level_no == 0) {

        printf("%d -> ", root->value);
    }
    else {

        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(Node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

int main() {

    Node* root = init_tree(9);


    root->left = create_node(20);
    root->right = create_node(1);
    root->left->left = create_node(60);
    root->left->right = create_node(30);


    print_tree_level_order(root);


    free_tree(root);
    return 0;
}
