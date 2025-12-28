#include<iostream>
#include<filesystem>
#include "./src/app/processes/ProcessManagement.hpp"
#include "./src/app/processes/Task.hpp"

namespace fs = std::filesystem;

int main(int argc,char* argv[]){

    std::string directory;
    std::string action;

    std::cout<<"Enter the directory path :"<<std::endl;
    std::getline(std::cin, directory);

    std::cout<<"Enter the action? ENCRYPT OR DECRYPT :"<<std::endl;
    std::getline(std::cin, action);

    try{
        if(fs::exists(directory) && fs::is_directory(directory)){
            ProcessManagement processManagement;
            for(const auto &entry: fs::recursive_directory_iterator(directory)){
                if(entry.is_regular_file()){
                    std::string filePath = entry.path().string();
                    IO io(filePath);
                    std::fstream f_stream = std::move(io.getFileSream());
                    if(f_stream.is_open()){
                        Action taskAction = action=="ENCRYPT"? Action::ENCRYPT: Action::DECRYPT;
                        auto task = std::make_unique<Task>(std::move(f_stream), taskAction, filePath);
                        processManagement.submitToQueue(std::move(task)); // move the ownership to submitToQueue stack space
                    }
                    else{
                        std::cout<<"Unable to open the file with the path :" << filePath<<std::endl;
                    }
                }
            }
            processManagement.executeTasks();
        }
        else{
            std::cout<<"Invalid Directory Path given :"<<directory << std::endl;
        }
    }
    catch(const fs::filesystem_error &ex){
        std::cout << "[ERROR]: Filesystem ERROR" <<ex.what()<< std::endl;
    }
}