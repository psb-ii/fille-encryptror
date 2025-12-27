#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include<queue>
#include "Task.hpp"
#include<memory>

class ProcessManagement{

    public:
        ProcessManagement();  // constructor to initialize the queue
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private:
        std::queue<std::unique_ptr<Task>> taskQueue;  // we want the full control over this taskQueue and do not want anyone from outside to change it
        

};



#endif