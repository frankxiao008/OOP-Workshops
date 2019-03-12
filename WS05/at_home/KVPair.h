//
//  KVPair.h
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_KVPair_h
#define SICT_KVPair_h
#include <iostream>
#include <iomanip>
extern int fieldWidth;
namespace sict{
    template<typename K,typename V>
    class KVPair{
        K k;
        V v;
    public:
        KVPair():k(),v(){};
        KVPair(const K& kk, const V& vv):k{kk},v{vv}{};
        template<typename F>
        void display(std::ostream&os,F f)const{
            os << std::left << std::setw(fieldWidth) << k <<" : "
            << std::right << std::setw(fieldWidth) << v <<  std::setw(fieldWidth)
            <<f(v)<<std::endl;
        }
            
    };
}

#endif /* SICT_KVPair_h */
