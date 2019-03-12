
#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H
namespace sict {
	
    class Taxable{
		const float taxRate;
      public:
		  Taxable(float a) : taxRate{ a } {
        
      }

      float operator()(float price){
          return price * (1+taxRate);
      }

	};
}

#endif