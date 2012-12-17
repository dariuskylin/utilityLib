/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  eg3_bind-command.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/2012 01:15:32 AM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<boost/function.hpp>
#include<boost/bind.hpp>

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

class command {
    public:
        command() {}
        command(boost::function<void()> f) : f_(f) {}

        void excute() {
            if(f_) {
                f_();
            }
        }

        template <typename Func>
        void set_function(Func f) {
            f_ = f;
        }          
        bool enabled() const {
            return f_;
        }  
    private:
        boost::function<void()> f_;
};

int main() {
    tape_recorder tr;

    command play(boost::bind(&tape_recorder::play,&tr));
    command stop(boost::bind(&tape_recorder::stop,&tr));
    command forward(boost::bind(&tape_recorder::forward,&tr));
    command rewind(boost::bind(&tape_recorder::rewind,&tr));
    command record;

    //Invoke from some GUI control
    if(play.enabled()) {
        play.excute();
    }

    //Invoke from some scripting client...
    stop.excute();

    //some inspired songwriter has passed some lyrics
    std::string s = "What a beautiful morning ...";
    record.set_function(boost::bind(&tape_recorder::record,&tr,s));
    record.excute();
    return 0;
}
