#ifndef IO_HPP // if not defined 
#define IO_HPP // define

#include<fstream>
#include<string>
#include<iostream>

class IO{
    public:
        IO(const std::string &file_path);
        ~IO(); // destructor declaration
        std::fstream getFileSream();   // getter function of our class

    private:
        std::fstream file_stream;     // setter variable

};

#endif