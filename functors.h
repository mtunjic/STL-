//
//  ALGORITHMS.H
//
//
//  Created by Marko Tunjic on 05/05/16.
//  Copyright © 2016 Marko Tunjic. All rights reserved.
//

#include "concepts.h"

template <Integer I>
struct modulo_multiply {
    I modulus;
    modulo_multiply(const I& i) : modulus(i) {}
      
    I operator() (const I& n, const I& m) const {
        return (n * m) % modulus;
    }
};

template <Integer I>
I identity_element(const modulo_multiply<I>&) {
  return I(1);
}

template <Number I>
inline bool is_zero(const I& x) {
  return x == I(0);
}

template <Number I>
inline bool is_positive (const I& x) {
  return x > I(0);
}

template <Number I>
inline void halve_non_negative ( I& x) {
  assert(is_positive(x));
  x >>= 1;
}

template <Number I>
inline void double_non_negative ( I& x) {
  assert(is_positive(x));
  x <<= 1;
}

template <Number I>
inline bool is_odd ( const I& x) {
  return x & I(1);
}

template <Number I>
inline bool is_even ( const I& x) {
  return !(x & I(1));
}

bool vowel(char c) {
  return std::strchr("aeiouAEIOU", c) != 0;
}

 class digit : public std::unary_function<char, bool> {
  public:
    bool operator() (char c) const { return ::isdigit(c) != 0; }
};

template <typename N>
struct plus
{
  N operator() (const N& x, const N& y) { return  x + y; }
};

template <typename N>
struct multiplies
{
  N operator() (const N& x, const N& y) { return x * y; }
};

template <Number N>
struct divides
{
  N operator() (const N& x, const N& y) {
    if (y == N(0)) return x;
    return x / y;
  }
};

template <Number N>
struct fplus
{
  N operator() (const N& x, const N& y) __attribute__((noinline));
};

template <Number N>
N fplus<N>::operator() (const N& x, const N& y) {
  return x + y;
}
template <TotallyOrdered T>
struct minimum
{
  T operator()(const T& x, const T& y) {
    if (y < x) return y;
    return x;
  }
};

template <TotallyOrdered T>
struct norm
{
  T operator()(const T& x, const T& y) {
    return x * x + y * y;
  }
};

template <Number T>
struct conversion
{
  T operator()(const T& x, const T& y) { return T(double(x) + double(y)); }
};

template <Number N>
struct square_root
{
  N operator()(N x, N y) {
    return N(sqrt(abs(x + y)));
  }
};

template <Number N>
struct cube_root_pow
{
  N operator()(N x, N y) {
    return N(pow(abs(x + y), 1.0/3.0));
  }
};

template <typename T>
struct less_than {
    T x;
    bool operator()(const T& y) { return y < x; }
};

template <typename T>
struct greater_than {
    T x;
    bool operator()(const T& y) { return y > x; }
};

template <typename N>
struct root
{
  N operator()(const N& x) { return std::sqrt(x); };
};

template <typename N>
struct volume
{
  N operator()(N x, N y, N z) {return x*y*z; }
};