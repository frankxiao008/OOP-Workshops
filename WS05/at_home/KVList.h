//
//  KVList.h
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_KVList_h
#define SICT_KVList_h
namespace sict{
    template <typename T>
    class KVList{
        T* arr{nullptr};
        size_t num=0u;
        size_t max=0u;
    public:
        KVList():arr{nullptr},
        num{0u},
        max{0u}{};
        KVList(int n){
            if(n>0)
            {
                arr=new T[n];
                max=n;
                num=0;
            }
            else {
//                KVList();
                arr=nullptr;
                num=0;max=0;
                throw "Error, Number of elements is negtive!";
            }
        }

        KVList(KVList&& rhs){
//            if(this!=&rhs){
//                delete [] arr;
                arr=rhs.arr;  rhs.arr=nullptr;
                num=rhs.num;  rhs.num=0;
                max=rhs.max;  rhs.max=0;
            //}
        }
        ~KVList(){
            delete [] arr;
            arr = nullptr;
        }
        const T& operator[](size_t i)const{
          if(i<0 || i>num)
              throw "Index out of bounds!";
          else
            return arr[i];
        }
    template<typename F>
        void display(std::ostream&os,F f)const{
           
               for(size_t i=0;i<num;i++)
                   arr[i].display(os,f);
        }
      void push_back(const T& t){
            if(num<max)
                arr[num++]=t;
        }
    KVList(const KVList&)=delete;
    KVList& operator=(KVList&& )=delete;
    KVList& operator=(const KVList&)=delete;
    };
   
}

#endif /* SICT_KVList_h */
