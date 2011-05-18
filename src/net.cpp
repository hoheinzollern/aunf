#include "net.h"

void Place::addPost(Trans *t)
{
  this->post.push_back(t);
}

void Place::addPre(Trans *t)
{
  this->pre.push_back(t);
}

void Place::addRead(Trans *t)
{
  this->read.push_back(t);
}

void Trans::addPost(Place *p)
{
  this->post.push_back(p);
}

void Trans::addPre(Place *p)
{
  this->pre.push_back(p);
}

void Trans::addRead(Place *p)
{
  this->read.push_back(p);
}

void Net::createArc(Place *pl, Trans *tr)
{
  pl->addPost(tr);
  tr->addPre(pl);
}

void Net::createArc(Trans *tr, Place *pl)
{
  tr->addPost(pl);
  pl->addPre(tr);
}

void Net::createReadArc(Trans *tr, Place *pl)
{
  tr->addRead(pl);
  pl->addRead(tr);
}
