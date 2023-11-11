// write a program to print the sum of the number present in array
#include "iostream"
#include "string"

namespace myNamespace{
    
    class ArrayMethods{
        public :
            int myInt(){
                    int size;
                    std::cout << "Enter the size: ";
                    std::cin >> size;
    
                int myArray[size];
                for(int i = 0; i < size; i++){
                    std::cout << "Enter the value for index: " << i << " ";
                    std::cin >> myArray[i];
                }
                
                int sum = 0;
                for(int i=0; i<size; i++){
                    sum += myArray[i];
                }
                return sum;
            }
            
        public :
            float myFloat(){
                    int size;
                    std::cout << "Enter the size: ";
                    std::cin >> size;
    
                float myArray[size];
                for(int i = 0; i < size; i++){
                    std::cout << "Enter the value for index: " << i << " ";
                    std::cin >> myArray[i];
                }
                
                float sum = 0;
                for(int i = 0; i<size; i++){
                    sum += myArray[i];
                }
                return sum;
            }
    };
}

int main(){
    std::string choice;
    std::cout << "Type float or int ";
    std::cin >> choice;

    myNamespace::ArrayMethods am;
    
    if(choice == "int"){
        int result = am.myInt();
        std::cout << "Sum of entered value: " << result;
    } else if (choice == "float"){
        float result = am.myFloat();
        std::cout << "Sum of entered value: " << result;
    }
    return 0;
}
