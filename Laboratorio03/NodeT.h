#ifndef NODET_H
#define NODET_H

#include <iostream>
using namespace std;
//BST NodeT

template <typename D>
class NodeT {
public:

    NodeT* l;
    NodeT* r;
    NodeT* f;
    D* d;

    NodeT() {
    }

    NodeT(NodeT* l, NodeT* r, D* d, NodeT* f) {
        this->l = l;
        this->d = d;
        this->r = r;
        this->f = f;
    }

    NodeT(const NodeT& orig) { // hacerlo
    }

    virtual ~NodeT() {
        cout << "deleting NodeT " << this << endl;
        if (*(this->f->d) > *(this->d)) {
            this->f->l = nullptr;
        } else {
            this->f->r = nullptr;
        }


        delete d;

    }

};

#endif /* NODET_H */
