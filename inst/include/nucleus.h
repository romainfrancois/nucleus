#ifndef NUCLEUS_H
#define NUCLEUS_H

#if defined(Rcpp_hpp)
    #define HAS_RCPP_IMPL
    
    // version for Rcpp
    #define NEW_VECTOR(_Vector_,_name_,_n_) _Vector_ _name_ = Rcpp::no_init(_n_)  
#endif

#if defined(Rcpp11_h) or defined(Rcpp14_h)
    #define HAS_RCPP_IMPL
    #define NEW_VECTOR(_Vector_,_name_,_n_) _Vector_ _name_(_n_)
#endif    
    
#include <RcppParallel.h>
#include <nucleus/nucleus.h>

#endif