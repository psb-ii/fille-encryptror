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


    //serailization
    std:: string toString(){
        std::ostringstream oss;
        oss<<filePath<<","<<(action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        // test.txt ENCRYPT f_stream
        // "test.txt,ENCRYPT"
        return oss.str();
    }


    //deserialization
    static Task fromString(const std::string &taskData){
        std::istringstream iss(taskData);
        std::string filePath;
        std::string actionStr;

        if(std::getline(iss,filePath,',') && std::getline(iss,actionStr)){
            // "test.txt.ENCRYPT"
            // filePath = "test.txt" and actionsStr = "Encrypt"
            Action action = (actionStr == "Encrypt"? Action::ENCRYPT: Action::ENCRYPT);
            IO io(filePath);
            std::fstream f_stream = std::move(io.getFileSream()); // move the ownership and not only the reference
            if(f_stream.is_open()){
                return Task(std::move(f_stream), action, filePath);
            }
            else{
                throw std::runtime_error("Failed to open the file" +filePath);
            }
        }
        else{
            throw std::runtime_error("Invalid task data format not as expected");
        }
    }
};



#endif