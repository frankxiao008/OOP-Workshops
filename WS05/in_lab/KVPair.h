


#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>

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
          if(!Key.empty()){
          os.setf(std::ios::left);
		  os << KVPair<K, V>::Key << ' : ';
		  os.setf(std::ios::right);
		  os << Value << f(Value) <<std::endl;
               
		  }  
        }

    } ;



}

#endif