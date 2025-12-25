#include<iostream>
#include "IO.hpp"
using namespace std;

IO:: IO(const std:: string &file_path){  // define the constructor of IO class
    file_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);    // to read and write in binary
    if(!file_stream.is_open()){
        std:: cout << "Unable to open the file with path: "<<file_path<<" "<<endl;
    }
}

fstream IO:: getFileSream(){
    return std::move(file_stream);   
}

IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}