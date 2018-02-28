#include "solution.h"

void solution::findSumPath(BinaryTreeNode *head, int sum, vector<BinaryTreeNode *> vec) {
    if (head == NULL) {
        return;
    }
    vec.push_back(head);
    if (sum == head->value && head->right == NULL && head->left == NULL) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i]->value << " ";
        }
        cout << endl;
    }
    findSumPath(head->left, sum - head->value, vec);
    findSumPath(head->right, sum - head->value, vec);
    vec.erase(vec.begin() + vec.size() - 1);
}

void solution::findSumPath(BinaryTreeNode *head, int sum) {
    vector<BinaryTreeNode *> vec;
    findSumPath(head, sum, vec);
}
