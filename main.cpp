#include <iostream>
#include "matrica.h"

int main(){
		Matrica<int> mass(5,5);
		mass.randomFill();
		std::cout<<mass<<std::endl;
		Matrica<int> mass1(std::move(mass));
		std::cout<<mass1<<std::endl;
		Matrica<int> massCopy(mass1);
		std::cout << massCopy.countNull() << std::endl;
		if(massCopy==mass1){
			std::cout<<"true"<<std::endl;
		}
		else{
			std::cout<<"false"<<std::endl;
		}
		class student{
			public:
		int ro;
			} v;
			v.ro=10;
		return 0;
	}
