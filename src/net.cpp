#include "net.h"

Coset *EnrichedCond::co() {
    Coset *co_result = new Coset();
    co_result->insert(this->co_private.begin(), this->co_private.end());
    for (Coset_iter it = h->concurrent.begin(); it != h->concurrent.end(); it++) {
        if (*it != this)
            co_result->insert(*it);
    }
    return co_result;
}

void Net::createArc(Place *p, Trans *t) {
    p->post.push_back(t);
    t->pre.push_back(p);
}

void Net::createArc(Trans *t, Place *p) {
    t->post.push_back(p);
    p->pre.push_back(t);
}

void Net::createReadArc(Trans *t, Place *p) {
    t->read.push_back(p);
    p->read.push_back(t);
}
