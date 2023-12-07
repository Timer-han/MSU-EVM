#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    ~TreeNode() {};
};

struct ListNode {
    int value;
    ListNode *next;

    ~ListNode() {};
};

bool Process(ListNode *head, TreeNode *root) {
    if (head == nullptr) {
        return false;
    }
    if (head->value == root->value) {
        if (root->left == root->right and root->left == nullptr and head->next == nullptr) {
            return true;
        }
        if (head->next == nullptr) {
            return false;
        }
        if (root->left != nullptr) {
            if (Process(head->next, root->left)) {
                return true;
            };
        }
        if (root->right != nullptr) {
            if (Process(head->next, root->right)) {
                return true;
            };
        }

    } else {
        return false;
    }
};


int TreeReading(TreeNode *vertex, int *n) {
    string str = "";
    int buf;
    if (*n <= 0) {
        return 0;
    }
    cout << "Please, write the value of left branch.\n"
            "If you don't want to give the value, write \"-\" \n"
            "without quotes." << endl;
    cin >> str;
    if (str != "-") {
        try {
            buf = stoi(str);
        } catch (invalid_argument const &a) {
            cout << "Bad input data" << endl;
            return -1;
        } catch (out_of_range const &a) {
            cout << "Integer overflow" << endl;
            return -1;
        }
        vertex->left = new TreeNode({buf, nullptr, nullptr});
        if (TreeReading(vertex->left, &(--*n)) < 0) {
            return -1;
        }
    }

    if (*n <= 0) {
        return 0;
    }
    cout << "Please, write the value of right branch.\n"
            "If you don't want to give the value, write \"-\" \n"
            "without quotes." << endl;
    cin >> str;
    if (str == "-") {
        return 0;
    }
    try {
        buf = stoi(str);
    } catch (invalid_argument const &a) {
        cout << "Bad input data" << endl;
        return -1;
    } catch (out_of_range const &a) {
        cout << "Integer overflow" << endl;
        return -1;
    }
    vertex->right = new TreeNode({buf, nullptr, nullptr});
    if (TreeReading(vertex->right, &(--*n)) < 0) {
        return -1;
    }
    return 0;
}

//void deleteList(ListNode* &head)
//{
//    ListNode* prev = head;
//
//    while (head)
//    {
//        head = head->next;
//        delete(prev);
//        prev = head;
//    }
//}


int main() {
    int n, l, buf; // number of vertices, length of list, buffer
    string str;
    cin >> n >> l;
    cout << "Please, write the quantity in root of your tree" << endl;
    cin >> str;
    try {
        buf = stoi(str);
    } catch (invalid_argument const &a) {
        cout << "Bad input data" << endl;
        return -1;
    } catch (out_of_range const &a) {
        cout << "Integer overflow" << endl;
        return -2;
    }

    TreeNode *tree = new TreeNode({buf, nullptr, nullptr});
    buf = n - 1;
    if (TreeReading(tree, &buf) < 0 or buf > 0) {
        cout << "Bad input data" << endl;
        return -1;
    }

    cout << "Please, give me array for " << l << " integer numbers" << endl;

    ListNode *list = new ListNode, *b = list;
    for (int i = 0; i < l; i++) {

        cin >> str;
        try {
            buf = stoi(str);
        } catch (invalid_argument const &a) {
            cout << "Bad input data" << endl;
            return -1;
        } catch (out_of_range const &a) {
            cout << "Integer overflow" << endl;
            return -1;
        }
        if (i) {
            b->next = new ListNode;
            b = b->next;
        }
        b->value = buf;
    }
    b->next = nullptr;

    if (Process(list, tree)) {
        cout << "Yes, tree has branch, which match the list" << endl;
    } else {
        cout << "No, tree hasn't branch, which match the list" << endl;
    }
    return 0;
}