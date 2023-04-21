#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#ifdef _WIN32
#else
#include <locale.h>
#endif

using namespace std;

struct TreeNode_07_p1 {
    double data;
    TreeNode_07_p1 *left;
    TreeNode_07_p1 *right;
};

struct TreeNode_07_p2 {
    string name;
    int age{};
    TreeNode_07_p2 *left{};
    TreeNode_07_p2 *right{};
};

static string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-",
            ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";

//1
void display_07_p1(TreeNode_07_p1 const * tree, string const & prefix = "", bool root = true, bool last = true) {
    cout << prefix << (root ? "" : (last ? ch_udia_hor : ch_ver_hor)) << (tree ? to_string(tree->data) : "") << endl;
    if (!tree || (!tree->left && !tree->right))
        return;
    vector<TreeNode_07_p1*> v{tree->left, tree->right};
    for (size_t i = 0; i < v.size(); ++i)
        display_07_p1(v[i], prefix + (root ? "" : (last ? "  " : ch_ver_spa)), false, i + 1 >= v.size());
}

void find_07_p1(TreeNode_07_p1 const * tree, double data, string const & prefix = "", bool root = true, bool last = true) {
    cout << prefix << (root ? "" : (last ? ch_udia_hor : ch_ver_hor));
    if(tree) {
        cout << to_string(tree->data);
        if (tree->data == data) cout << "!";
    }
    else cout << "";
    cout << endl;
    if (!tree || (!tree->left && !tree->right))
        return;
    vector<TreeNode_07_p1*> v{tree->left, tree->right};
    for (size_t i = 0; i < v.size(); ++i)
        find_07_p1(v[i], data, prefix + (root ? "" : (last ? "  " : ch_ver_spa)), false, i + 1 >= v.size());
}

struct TreeNode_07_p1* newNode_07_p1(double item);
struct TreeNode_07_p1* insert_07_p1(struct TreeNode_07_p1 *node, double data);
struct TreeNode_07_p1* minValueNode_07_p1(struct TreeNode_07_p1 *node);
struct TreeNode_07_p1* maxValueNode_07_p1(struct TreeNode_07_p1 *node);
struct TreeNode_07_p1* deleteNode_07_p1(struct TreeNode_07_p1 *root, double data);

//2
struct TreeNode_07_p2* newNode_07_p2(string name, int age);
struct TreeNode_07_p2* insert_07_p2(struct TreeNode_07_p2 *node, const string& name, int age);
void inorder_07_p2(struct TreeNode_07_p2 *root);

int main(){

    cout << "Lab_07 var_4" << endl;

    cout << "What is part of lab_07 (1-2)?\n";
    int partOfLab;
    cin >> partOfLab;
    switch (partOfLab) {
        case 1: {
            TreeNode_07_p1 *ancestor, *currentNode, *lastNode;
            currentNode = nullptr;
            lastNode = currentNode;
            int input01 = 1;
            while (input01 != 0) {
                cout << "You want...\n" <<
                     "1 - add an element to the tree.\n" <<
                     "2 - find an element of the tree.\n" <<
                     "3 - delete element of the tree.\n" <<
                     "4 - display all elements of the tree.\n" <<
                     "(0 - find the extremum and end the program.)\n";
                cin >> input01;
                switch (input01) {
                    case 1: {
                        currentNode = lastNode;
                        cout << "Enter the value of the new element:\n";
                        double data;
                        cin >> data;
                        if (currentNode == nullptr){
                            currentNode = newNode_07_p1(data);
                            ancestor = currentNode;
                        }
                        else currentNode = insert_07_p1(currentNode, data);
                        lastNode = currentNode;
                        break;
                    }
                    case 2: {
                        cout << "Enter element you want to find:\n";
                        double data;
                        cin >> data;
                        cout << "The element you are looking for is marked with an exclamation point (!):\n";
                        find_07_p1(ancestor, data);
                        cout << "\n";
                        break;
                    }
                    case 3: {
                        cout << "Enter element you want to delete:\n";
                        double data;
                        cin >> data;
                        currentNode = deleteNode_07_p1(currentNode, data);
                        cout << "The element has been deleted.\n";
                        break;
                    }
                    case 4: {
                        display_07_p1(ancestor);
                    }
                    case 0: {
                        int input02;
                        cout << "Do you want to find...\n" <<
                             "1 - maximum.\n" <<
                             "2 - minimum.\n" <<
                             "3 - maximum and minimum\n";
                        cin >> input02;
                        switch (input02) {
                            case 1: {
                                cout << "Maximum: \n" << maxValueNode_07_p1(ancestor) << endl;
                                break;
                            }
                            case 2: {
                                cout << "Minimum: \n" << minValueNode_07_p1(ancestor) << endl;
                                break;
                            }
                            case 3: {
                                cout << "Maximum: \n" << maxValueNode_07_p1(ancestor) << endl;
                                cout << "Minimum: \n" << minValueNode_07_p1(ancestor) << endl;
                                break;
                            }
                            default: {
                                cout << "Invalid input is regarded as a desire to find both the maximum and the minimum.\n";
                                cout << "Maximum: \n" << maxValueNode_07_p1(ancestor) << endl;
                                cout << "Minimum: \n" << minValueNode_07_p1(ancestor) << endl;
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        cout << "Incorrect input.\n";
                    }
                }
            }
            break;
        }
        case 2: {
            TreeNode_07_p2 *ancestor, *currentNode, *lastNode;
            currentNode = nullptr;
            lastNode = currentNode;
            string name = "0";
            int counter = 0;
            while (name != "."){
                cout << counter+1 << ":\n";
                cout << "Enter the person's name or \".\" to complete input:\n";
                cin >> name;
                if (name != "."){
                    counter++;
                    cout << "Enter the person's age:\n";
                    int age;
                    cin >> age;
                    currentNode = lastNode;
                    if (currentNode == nullptr){
                        currentNode = newNode_07_p2(name, age);
                        ancestor = currentNode;
                    }
                    else currentNode = insert_07_p2(currentNode, name, age);
                    lastNode = currentNode;
                }
            }
            inorder_07_p2(ancestor);
            break;
        }
        default:{
            cout << "Incorrect input.\n";
            break;
        }
    }

    return 0;
}


//1
struct TreeNode_07_p1* newNode_07_p1(double item){
    auto *temp = (struct TreeNode_07_p1 *)malloc(sizeof(struct TreeNode_07_p1));
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

struct TreeNode_07_p1* insert_07_p1(struct TreeNode_07_p1 *node, double data) {
    if (node == nullptr) return newNode_07_p1(data);

    if (data < node->data)
        node->left = insert_07_p1(node->left, data);
    else if (data == node->data) {
        cout << "The node has already been added.\n";
        return node;
    }
    else
        node->right = insert_07_p1(node->right, data);

    return node;
}

struct TreeNode_07_p1* minValueNode_07_p1(struct TreeNode_07_p1 *node) {
    struct TreeNode_07_p1 *current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

struct TreeNode_07_p1* maxValueNode_07_p1(struct TreeNode_07_p1 *node) {
    struct TreeNode_07_p1 *current = node;

    while (current && current->right != nullptr)
        current = current->right;

    return current;
}

struct TreeNode_07_p1* deleteNode_07_p1(struct TreeNode_07_p1 *root, double data) {
    if (root == nullptr) return root;

    if (data < root->data)
        root->left = deleteNode_07_p1(root->left, data);
    else if (data > root->data)
        root->right = deleteNode_07_p1(root->right, data);
    else {
        if (root->left == nullptr) {
            struct TreeNode_07_p1 *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == nullptr) {
            struct TreeNode_07_p1 *temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode_07_p1 *temp = minValueNode_07_p1(root->right);

        root->data = temp->data;

        root->right = deleteNode_07_p1(root->right, temp->data);
    }
    return root;
}


//2
struct TreeNode_07_p2* newNode_07_p2(string name, int age){
    TreeNode_07_p2 *temp = new TreeNode_07_p2;
    temp->name = std::move(name);
    temp->age = age;
    temp->left = temp->right = nullptr;
    return temp;
}

struct TreeNode_07_p2* insert_07_p2(struct TreeNode_07_p2 *node, const string& name, int age){
    if (node == nullptr) return newNode_07_p2(name, age);

    if (age >= node->age)
        node->left = insert_07_p2(node->left, name, age);
    else
        node->right = insert_07_p2(node->right, name, age);

    return node;
}

void inorder_07_p2(struct TreeNode_07_p2 *root) {
    if (root != nullptr) {
        inorder_07_p2(root->left);

        cout << root->name << " (" << root->age << ")" << endl;
        inorder_07_p2(root->right);
    }
}