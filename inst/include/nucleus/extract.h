#ifndef NUCLEUS_EXTRACT_H
#define NUCLEUS_EXTRACT_H

namespace nucleus {

    namespace impl {
        
        template <typename InputIterator, typename OutputIterator, typename IndexIterator>
        struct extractor {
            
            extractor( InputIterator data_, OutputIterator out_, IndexIterator index_ ): 
                data(data_), out(out_), index(index_){}
                
            inline void operator()( const tbb::blocked_range<int>& r ) const {
                int start = r.begin(), end = r.end() ;
                for(int i=start; i<end; i++){
                    out[i] = data[index[i] - 1] ;      
                }
            }
                
            InputIterator data; 
            OutputIterator out ;
            IndexIterator index ;
        } ;
        
    }
    
    template <typename InputIterator, typename OutputIterator, typename IndexIterator>
    inline void extract( InputIterator begin, InputIterator end, OutputIterator out, IndexIterator index_begin, IndexIterator index_end ){
        int n = std::distance(index_begin, index_end ) ; 
        typedef typename impl::extractor<InputIterator, OutputIterator, IndexIterator> Extractor ;
        
        Extractor ext( begin, out, index_begin ) ;
        parallel_for( tbb::blocked_range<int>(0, n), ext ) ; 
    }
      
    
    #if defined(HAS_RCPP_IMPL)
    template <typename Vector>
    inline Vector extract( Vector& data, Rcpp::IntegerVector index ){
        NEW_VECTOR(Vector,res,index.size()) ;
        extract( data.begin(), data.end(), res.begin(), index.begin(), index.end() ) ;
        return res ;
    }
    #endif
}

#endif