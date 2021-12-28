#include <iostream>
#include <stdint.h>
using namespace std;

struct BinaryTree {
    BinaryTree(int64_t x, int32_t l, int32_t r) : val(x), leftChild(l), rightChild(r) {}
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    int32_t leftChild = 0;
    int32_t rightChild = 0;
    int64_t val = 0;
};

class SegmentTree {
  private:
    BinaryTree *root = nullptr;
    int64_t sumHelper(BinaryTree *node, int32_t idx1, int32_t idx2, int32_t l, int32_t r);
    void delHelper(BinaryTree *node, int32_t idx, int32_t val);
    void insHelper(BinaryTree *node, int32_t idx, int32_t val);
    int delValHelper(BinaryTree *node, int32_t idx);

  public:
    void insert(int32_t idx, int32_t val);
    void del(int32_t idx);
    int64_t sum(int32_t idx1, int32_t idx2);
};

void SegmentTree::insHelper(BinaryTree *node, int32_t idx, int32_t v) {
    if (node->left == nullptr && node->right == nullptr) {
        if (idx == 0) {
            node->right = new BinaryTree(node->val, 0, 0);
            node->left = new BinaryTree(v, 0, 0);
            node->val = node->right->val + v;
        } else {
            node->left = new BinaryTree(node->val, 0, 0);
            node->right = new BinaryTree(v, 0, 0);
            node->val = node->left->val + v;
        }

        node->leftChild = 1;
        node->rightChild = 1;
        return;
    }
    if (idx <= node->leftChild) {
        node->leftChild++;
        node->val += v;
        insHelper(node->left, idx, v);
        return;
    }
    if (idx > node->leftChild) {
        node->rightChild++;
        node->val += v;
        insHelper(node->right, idx - node->leftChild, v);
        return;
    }
}

void SegmentTree::insert(int32_t idx, int32_t v) {
    if (root == nullptr) {
        root = new BinaryTree(v, 0, 0);
    } else {
        insHelper(root, idx, v);
    }
}

int SegmentTree::delValHelper(BinaryTree *node, int32_t idx) {
    if (node->leftChild == 0 && node->rightChild == 0)
        return node->val;
    if (idx <= node->leftChild) {
        return delValHelper(node->left, idx);
    }
    if (idx > node->leftChild) {
        return delValHelper(node->right, idx - node->leftChild);
    }
    return -1;
}

void SegmentTree::delHelper(BinaryTree *node, int32_t idx, int32_t v) {
    if (idx <= node->leftChild) {
        if (node->leftChild == 1) {
            delete node->left;
            node->left = nullptr;
            BinaryTree *l = node->right->left;
            BinaryTree *r = node->right->right;
            int newVal = node->right->val;
            int lc = node->right->leftChild;
            int rc = node->right->rightChild;
            delete node->right;
            node->val = newVal;
            node->left = l;
            node->right = r;
            node->leftChild = lc;
            node->rightChild = rc;
            return;
        }
        node->leftChild--;
        node->val -= v;
        delHelper(node->left, idx, v);
        return;
    }
    if (idx > node->leftChild) {
        if (node->rightChild == 1) {
            delete node->right;
            node->right = nullptr;
            BinaryTree *l = node->left->left;
            BinaryTree *r = node->left->right;
            int newVal = node->left->val;
            int lc = node->left->leftChild;
            int rc = node->left->rightChild;
            delete node->left;
            node->val = newVal;
            node->left = l;
            node->right = r;
            node->leftChild = lc;
            node->rightChild = rc;
            return;
        }
        node->rightChild--;
        node->val -= v;
        delHelper(node->right, idx - node->leftChild, v);
        return;
    }
}

void SegmentTree::del(int32_t idx) {
    int delVal = delValHelper(root, idx);
    if (root->leftChild + root->rightChild == 0) {
        delete root;
        root = nullptr;
        return;
    }
    delHelper(root, idx, delVal);
}

int64_t SegmentTree::sumHelper(BinaryTree *node, int32_t idx1, int32_t idx2, int32_t l, int32_t r) {
    if (node == nullptr)
        return 0;
    if (l >= idx1 && r <= idx2) {
        return node->val;
    }
    if (l > idx2 || r < idx1) {
        return 0;
    }
    int rightTreeL = l + node->leftChild;
    int rightTreeR = r;

    int leftTreeL = l;
    int leftTreeR = r - node->rightChild;

    return sumHelper(node->left, idx1, idx2, leftTreeL, leftTreeR) + sumHelper(node->right, idx1, idx2, rightTreeL, rightTreeR);
}

int64_t SegmentTree::sum(int32_t idx1, int32_t idx2) {
    return sumHelper(root, idx1, idx2, 1, root->leftChild + root->rightChild);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SegmentTree *st = new SegmentTree();
    int n, inp1, inp2;
    char c;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        switch (c) {
        case 'I':
            cin >> inp1;
            cin >> inp2;
            st->insert(inp1, inp2);
            break;
        case 'S':
            cin >> inp1;
            cin >> inp2;
            cout << st->sum(inp1, inp2) << endl;
            break;

        case 'D':
            cin >> inp1;
            st->del(inp1);
            break;
        default:
            exit(1);
        }
    }
}