


#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>
#include<iomanip>
extern int fieldWidth;

namespace sict {
    template<typename K, typename V>
    class KVPair{
          K Key;
          V Value;
      public:
        KVPair():Key{}, Value{} {     }

         KVPair(const K& k, const V& v){
          Key = k;
          Value =v;
        }

        template<typename F>
        void display(std::ostream& os, F f) const{
        
         
		  os << std::left << std::setw(fieldWidth);
		  os << Key << " : ";
		  os << std::right << std::setw(fieldWidth);
		  os << Value <<std::setw(fieldWidth)<< f(Value) <<std::endl;
               
		  }  
        

    } ;



}

#endif