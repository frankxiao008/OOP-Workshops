


#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>
<<<<<<< HEAD
=======
#include<iomanip>
extern int fieldWidth;
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c

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
<<<<<<< HEAD
          if(!Key.empty()){
          os.setf(std::ios::left);
		  os << KVPair<K, V>::Key << ' : ';
		  os.setf(std::ios::right);
		  os << Value << f(Value) <<std::endl;
               
		  }  
        }
=======
        
         
		  os << std::left << std::setw(fieldWidth);
		  os << Key << " : ";
		  os << std::right << std::setw(fieldWidth);
		  os << Value <<std::setw(fieldWidth)<< f(Value) <<std::endl;
               
		  }  
        
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c

    } ;



}

#endif