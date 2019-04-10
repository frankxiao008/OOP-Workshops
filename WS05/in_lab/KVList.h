
#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
namespace sict {
<<<<<<< HEAD
  template<typename T>
=======
  template<class T>
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
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
<<<<<<< HEAD
			Arr = nullptr;
			currentNum = 0u;
			maxNum = 0u;
        }
=======
		/*	Arr = nullptr;
			currentNum = 0u;
			maxNum = 0u;*/
			KVList();
		
		}
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
      }

      KVList(KVList&& list){
        Arr = list.Arr;
        currentNum = list.currentNum;
        maxNum = list.maxNum;
<<<<<<< HEAD
=======
		list.Arr = nullptr;
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
		list.currentNum = 0;
		list.maxNum = 0;
      }

      ~KVList(){
        delete [] Arr;
<<<<<<< HEAD
=======
		Arr = nullptr;
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
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
<<<<<<< HEAD
        if(currentNum <maxNum){

       
		  Arr[currentNum++] = t;
		 // currentNum++;
        }
      }
  };

=======
        if(currentNum+1 <= maxNum){
    
		  Arr[currentNum] = t;
		  ++currentNum;
        }

		
      }
	   KVList& operator=(const KVList&) = delete;
	   KVList& operator=(KVList&&) = delete;
	   KVList(KVList&) = delete;

  };

 
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
}

#endif