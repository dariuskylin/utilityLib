/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg1_Command-pattern.cpp
 *    Description:  使用Command模式实现磁带录音机
 *        Version:  1.0
 *        Created:  11/16/2012 11:50:50 PM
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

class play_command : public command_base {
    public:
        play_command(tape_recorder* p) : p_(p)  {}

        bool enabled() const {
            return true;
        }

        void excute() {
            p_->play();
        }
    private:
        tape_recorder* p_;
};

class stop_command : public command_base {
    public:
        stop_command(tape_recorder* p) : p_(p) {}

        bool enabled() const {
            return true;
        }

        void excute() {
            p_->stop();
        }
    private:
        tape_recorder* p_;
};

int main() {
    tape_recorder tr;

    //Using the command pattern
    command_base* pPlay = new play_command(&tr);
    command_base* pStop = new stop_command(&tr);

    //Invoked when pressing a button
    pPlay->excute();
    pStop->excute();

    delete pPlay;
    delete pStop;
    return 0;
}
