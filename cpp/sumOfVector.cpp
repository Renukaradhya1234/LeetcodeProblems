// learning about dynamic array (vector)
#include "iostream"
#include "vector"
#include "string"

namespace myNamespace{
    // calling template to make dynamic datatype...
    template <typename T>
    
	class GenericDatatype{

        public: 
        T myMethod(){
        	int size;
            std::cout << "Enter the size: ";
            std::cin >> size;
            
            std::vector<T> myVector;
            
            for(int i = 0; i < size; i++){
            	T value;
            	std::cout << "Enter the value for " << i << " index  ";
                std::cin >> value;
                
                myVector.push_back(value);
            }
            
            T sum = 0;
            for(T value : myVector){
            	sum += value;
            }
            
            return sum;
        }
    };
}

int main(){
	
    std::string choice;
    std::cout << "choice float or int" << std::endl;
    std::cin >> choice;
    
    if (choice == "int") {
        myNamespace::GenericDatatype<int> gdt;
        auto result = gdt.myMethod();
        std::cout << "Sum of the numbers: " << result << std::endl;
    } else if (choice == "float") {
        myNamespace::GenericDatatype<float> gdt;
        auto result = gdt.myMethod();
        std::cout << "Sum of the numbers: " << result << std::endl;
    }
    
    return 0;
}
