
#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
namespace sict {
  template<class T>
  class KVList{
      T* Arr=nullptr;
      size_t currentNum=0;
      size_t maxNum=0;
      public:
		  KVList() :Arr{ nullptr }, currentNum{ 0u }, maxNum{0u} {}
      KVList(int n){
        if(n>0){
           Arr = new T[n]; 
		   maxNum = n;
			currentNum = 0u;
        }else{
		/*	Arr = nullptr;
			currentNum = 0u;
			maxNum = 0u;*/
			KVList();
		
		}
      }

      KVList(KVList&& list){
        Arr = list.Arr;
        currentNum = list.currentNum;
        maxNum = list.maxNum;
		list.Arr = nullptr;
		list.currentNum = 0;
		list.maxNum = 0;
      }

      ~KVList(){
        delete [] Arr;
		Arr = nullptr;
      }

      const T& operator[](size_t i)const{
          return Arr[i];
      }

      template<typename F>
      void display(std::ostream& os, F f)const{
          for(size_t i=0; i<currentNum; i++){
                 Arr[i].display(os, f);
          }
      }



       void push_back(const T& t){
        if(currentNum+1 <= maxNum){
    
		  Arr[currentNum] = t;
		  ++currentNum;
        }

		
      }
	   KVList& operator=(const KVList&) = delete;
	   KVList& operator=(KVList&&) = delete;
	   KVList(KVList&) = delete;

  };

 
}

#endif