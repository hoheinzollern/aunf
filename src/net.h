#ifndef NET_H
#define NET_H

#include "common.h"

#include <string>
#include <vector>

using namespace std;

class Place;
class Trans;
class Cond;
class Event;
class Hist;

class Place {
public:
  string name;
  uint id;

  vector<Trans *> pre;
  vector<Trans *> post;
  vector<Trans *> read;

  vector<Cond *> image;
  uchar mark;

  void addPost(Trans *);
  void addPre(Trans *);
  void addRead(Trans *);
};

class Trans {
public:
  string name;
  uint id;

  vector<Place *> pre;
  vector<Place *> post;
  vector<Place *> read;

  void addPost(Place *);
  void addPre(Place *);
  void addRead(Place *);
};

class Cond {
  uint id;
  Place *origin;

  Event *pre;
  vector<Event *> post;
  vector<Event *> read;

  uchar mark;

  vector< pair<Cond *, Hist *> > co_private;
};

class Event {
  uint id;
  Trans *origin;

  vector<Cond *> pre;
  vector<Cond *> post;
  vector<Cond *> read;

  uchar mark;
};

class Hist {
  uint size;

  Event *event;

  vector< pair<Cond *, Hist *> > pred;

  vector< pair<Cond *, Hist *> > co_common;
};

class Net {
  vector<Place *> places;
  vector<Trans *> transitions;

public:
  void createArc(Place *pl, Trans *tr);
  void createArc(Trans *tr, Place *pl);
  void createReadArc(Trans *tr, Place *pl);
};

class Unf {
  vector<Cond *> conditions;
  vector<Event *> events;

  Event *root;
};

#endif
