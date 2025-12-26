#ifndef TASK_HPP
#define TASK_HPP

#include<string>
#include<iostream>
#include<sstream>
#include "../fileHandling/IO.hpp"

enum class Action {
    ENCRYPT,
    DECRYPT
};

//stores custom data type of type Task

struct Task{
    std:: string filePath;
    std:: fstream f_stream;
    Action action;

    // && means it is volatile a it is only used for assignment here
    Task(std::fstream &&stream, Action act, std::string filePath): f_stream(std::move(stream)), action(act), filePath(filePath) {}

    std:: string toString(){
        std::ostringstream oss;
        oss<<filePath<<","<<(action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        // test.txt ENCRYPT f_stream
        // "test.txt,ENCRYPT"
        return oss.str();
    }

};



#endif