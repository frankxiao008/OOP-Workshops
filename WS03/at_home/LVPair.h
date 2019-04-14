
#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>

namespace sict {
	template<typename L, typename V >
		class LVPair {
		
			L Label;
			V Value;
		
	public:
		LVPair(): Label(), Value(){  }

		LVPair(const L& label, const V& value) {
			Label = label;
			Value = value;
		}
		
		virtual void display(std::ostream& os) const {
			os << Label << " : " << Value << std::endl;
		}

		//get the  Label for the object
		const L& getLabel() const{
			return Label;
		}

		const V& getValue() const { return  Value; }

	};
	
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>{
		static V D_Value;
		static size_t width;

	public:
		//default constructor
		//
		SummableLVPair(){
			
		}
		//overload  the two parameter constructor
		//
		SummableLVPair(const L& label, const V& v):LVPair<L, V>(label, v) {
			if (width < label.size())
				width = label.size();

		}
		// returns the initial value for summation of type L
		//
		const static V& getInitialValue() {
			return D_Value;
		}
	
	
		
		V sum(const L& label, const V& sum) const {
			return ( label ==this->getLabel())? LVPair<L, V>::getValue() + sum : sum;
		}

		
		virtual void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}

		

	};




	template<typename L, typename V>
		size_t SummableLVPair<L, V>::width = 0u;

	template<>
	int SummableLVPair<std::string, int>::D_Value = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::D_Value = "\0";


	template<>
	std::string SummableLVPair<std::string,std::string>::sum(const std::string& label, const std::string& sum) const {
		return (label == this->getLabel()) ? (sum + " " + LVPair<std::string, std::string>::getValue()):sum;
	}



}

#endif // !SICT_LIST_H
