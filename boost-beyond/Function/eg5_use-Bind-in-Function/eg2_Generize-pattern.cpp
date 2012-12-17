/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg2_Generize-pattern.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/2012 12:49:28 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */

#include<iostream>
#include<string>

class tape_recorder {
    public:
        void play() {
            std::cout<< "Since my baby left me..." <<std::endl;
        }

        void stop() {
            std::cout<< "OK, taking a break" <<std::endl;
        }

        void forward() {
            std::cout<< "whizzz" <<std::endl; 
        }

        void rewind() {
            std::cout<< "zzzihw" <<std::endl;
        }

        void record(const std::string& sound) {
            std::cout<< "Recorded: " << sound <<std::endl;
        }
};

class command_base {
    public:
        virtual bool enabled() const = 0;
        virtual void excute() = 0;

        virtual ~command_base() {}
};

class tape_recorder_command : public command_base {
    public:
        tape_recorder_command(
                tape_recorder* p,
                void (tape_recorder::*func)()) : p_(p), func_(func) {}

        bool enabled() const {
            return true;
        }

        void excute() {
            (p_->*func_)();
        }
    private:
        void (tape_recorder::*func_)();
        tape_recorder* p_;
};

int main() {
    tape_recorder tr;

    //Using the improved command
    command_base* pPlay =
        new tape_recorder_command(&tr, &tape_recorder::play);
    command_base* pStop =
        new tape_recorder_command(&tr, &tape_recorder::stop);

    //Invoked from a GUI, or a scripting client
    pPlay->excute();
    pStop->excute();

    delete pPlay;
    delete pStop;
    return 0;
}
