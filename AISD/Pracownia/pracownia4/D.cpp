#include <iostream>
#include <stdio.h>
using namespace std;

class Tree {
    public:
    Tree(long x)  {
        sum = x;
    }
    Tree *lp = nullptr;
    Tree *rp = nullptr;
    int lpnum = 0;
    int rpnum = 0;
    long sum = 0;
};

void delrec(Tree *node, int i, int v) {
    if (i <= node->lpnum) {
        if (node->lpnum == 1) {
            delete node->lp;
            node->lp = nullptr;
            Tree *r = node->rp;
            node->sum = r->sum;
            node->lp = r->lp;
            node->rp = r->rp;
            node->lpnum = r->lpnum;
            node->rpnum = r->rpnum;
            delete r;
            return;
        }
        node->lpnum= node->lpnum -1;
        node->sum = node->sum - v;;
        delrec(node->lp, i, v);
        return;
    }
    if (i > node->lpnum) {
        if (node->rpnum == 1) {
            delete node->rp;
            node->rp = nullptr;
            Tree *l = node->lp;
            node->sum = l->sum;
            node->lp = l->lp;
            node->rp = l->rp;
            node->lpnum = l->lpnum;
            node->rpnum = l->rpnum;
            delete l;
            return;
        }
        node->rpnum = node->rpnum -1;
        node->sum = node->sum - v;
        delrec(node->rp, i - node->lpnum, v);
        return;
    }
}

int findval(Tree *node, int i) {
    if (node->lpnum == 0 && node->rpnum == 0)
        return node->sum;
    if (i <= node->lpnum)
        return findval(node->lp, i);
    else
        return findval(node->rp, i - node->lpnum);
}

long sumrec(Tree *node, int i1, int i2, int l, int r) {
    if (node == nullptr )
        return 0;
    if (l >= i1 && r <= i2)
        return node->sum;
    if (l > i2 || r < i1) 
        return 0;
    return sumrec(node->rp, i1, i2, l + node->lpnum, r) + sumrec(node->lp, i1, i2, l, r - node->rpnum);
}

void insertion(Tree *node, int i, int v) {
    if (node->lp == nullptr && node->rp == nullptr) {
        if (i != 0) {
            node->lp = new Tree(node->sum);
            node->rp = new Tree(v);
            node->sum = node->lp->sum + v;
        } else {
            node->rp = new Tree(node->sum);
            node->lp = new Tree(v);
            node->sum = node->rp->sum + v;
        }
        node->lpnum = 1;
        node->rpnum = 1;
        return;
    }else{
        if (i <= node->lpnum) {
            node->lpnum = node->lpnum + 1;
            node->sum = node->sum + v;
            insertion(node->lp, i, v);
            return;
        }else{
            node->rpnum = node->rpnum + 1;
            node->sum = node->sum + v;
            insertion(node->rp, i - node->lpnum, v);
            return;
        }
    }
}


int main() {
    Tree *r = nullptr;
    int n, i1, i2;
    char c;
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'I')
        {
        cin >>i1 >> i2;
        if (r == nullptr) {
            r = new Tree(i2);
        } else {
            insertion(r, i1, i2);
        }
        }
        if (c == 'D')
        {
            cin >>i1;
            if (r->lpnum + r->rpnum == 0) {
                delete r;
                r = nullptr;
                continue;
            }
            int delsum = findval(r, i1);
            delrec(r, i1, delsum);
        }
        if (c == 'S')
        {
            cin >>i1 >> i2;
            printf("%ld\n",sumrec(r, i1, i2, 1, r->lpnum + r->rpnum));
        }
    }
}