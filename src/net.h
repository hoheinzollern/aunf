#ifndef NET_H
#define NET_H

#include "common.h"

#include <string>
#include <list>
#include <set>

using namespace std;

template <class T> class Node {
public:
    string name;
    uint id;

    list<T *> pre;
    list<T *> post;
    list<T *> read;
};

class Place;
class Trans;
class Cond;
class Event;
class Hist;

class Place : public Node<Trans> {
public:
    list<Cond *> image;
    uchar mark;
};

class Trans : public Node<Place> {
public:
    list<Event *> image;
};

class Cond : public Node<Event> {
public:
    Place *origin;
};

class Event : public Node<Event> {
public:
    Trans *origin;
};

#define Coset set<EnrichedCond *>
#define Coset_iter set<EnrichedCond *>::iterator

class EnrichedCond {
public:
    Cond *c;
    Hist *h;

    EnrichedCond(Cond *c, Hist *h): c(c), h(h) {}

    Coset *co();
private:
    Coset co_private;
};

class Hist {
public:
    uint size;

    Event *event;

    Coset pred;

    Coset concurrent;
    Coset subsumed;
};

class Net {
public:
    set<Place *> places;
    set<Trans *> transitions;

    void createArc(Place *, Trans *);
    void createArc(Trans *, Place *);
    void createReadArc(Trans *, Place *);
};

class Unf {
public:
    set<Cond *> conditions;
    set<Event *> events;

    Event *root;
};

#endif
