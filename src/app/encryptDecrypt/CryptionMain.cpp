#include <iostream>
#include "Cryption.hpp"

int main(int argc, char* argv[]){
    if(argc!=2){
        std:: cerr<< "Usage: ./cryption <task_data>"<<std::endl;
        return 0;
    }
    else   
        executeCryption(argv[1]);
        return 1;

    // How to run this file "./cryption example.txt,ENCRYPT"
    

}