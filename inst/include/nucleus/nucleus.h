#ifndef NUCLEUS_NUCLEUS_H
#define NUCLEUS_NUCLEUS_H

#include <nucleus/extract.h>

#if defined(Rcpp_hpp) 
#define NUCLEUS_HAS_RCPP_IMPL
#endif

#if defined(Rcpp11_h) or defined(Rcpp14_h)
#define NUCLEUS_HAS_RCPP_IMPL
#endif

#endif