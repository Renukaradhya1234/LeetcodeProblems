// learning about dynamic array (vector)
#include "iostream"
#include "vector"
#include "string"

int main(){

	//declaring the vector like array
    std::vector<std::string> myVector;
    while (true){
    	std::string input;
        std::cout << "Enter the input: " << std::endl;
        //std::getline(std::cin, input);
        std::cin >> input;
        
        if(input == "exit"){
        	break;
        }
        myVector.push_back(input);
    }
    
    std::cout << "Entered values are: " << std::endl;
    
    for(int i = 0; i < myVector.size(); i++){
    	std::cout << myVector[i] << std::endl;
    }
    
}
