// program to find the prime number in given range
#include "iostream"

namespace myNamespace{
    
    class CheckNumber{
        public:
            bool isPrime(int num){
                for(int i = 2; i<num; i++){
                    if (!(num%2)){
                        return false;
                    }
                }
                return true;
            }
            
        public: 
            void rangeIsPrime(int start, int end){
                for(int i = start; i <= end; i++){
                   if(isPrime(i)){
                       std::cout<< i << " is prime number" << std::endl;
                   } else{
                       std::cout<< i << " is not prime number" << std::endl;
                   }
                }
            }
    };
}

int main(){
    myNamespace::CheckNumber cn; // creating the object for checknumber class
    
    int start;
    int end;
    
    std::cout<< "Enter the starting number: ";
    std::cin >> start;
    
    std::cout << "Enter the ending number: ";
    std::cin >> end;
    
    cn.rangeIsPrime(start, end);
    return 0;
}
