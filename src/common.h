#ifndef COMMON_H
#define COMMON_H

template <class T1, class T2, class T3> struct triplet
{
  typedef T1 first_type;
  typedef T2 second_type;
  typedef T3 third_type;

  T1 first;
  T2 second;
  T3 third
  triplet() : first(T1()), second(T2()), third(T3()) {}
  triplet(const T1& x, const T2& y, const T3& z) : first(x), second(y), third(z) {}
  template <class U, class V, class W>
    triplet (const pair<U,V,W> &p) : first(p.first), second(p.second), third(p.third) { }
}

#endif
