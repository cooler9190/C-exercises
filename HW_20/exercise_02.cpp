#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <chrono>
#include <cstdio>

using namespace std::chrono_literals;

class Timer {
    public:
    using CallbackType = std::function<void()>;
    using Timestamp = std::chrono::system_clock::time_point;
    using Duration = std::chrono::system_clock::duration;

    void startTimer(std::shared_ptr<CallbackType> callback, Duration countdownTime) {
        elapsed_ = false;
        callback_ = callback;
        countdownEndTimestamp_ = std::chrono::system_clock::now() + countdownTime; 
    }

    bool update() {
        if(elapsed_) {
            return false;
        }

        if(std::chrono::system_clock::now() > countdownEndTimestamp_) {
            (*callback_.get())();
            callback_.reset();
            elapsed_ = true;
            return true;
        }

        return false;
    }


    private:
    bool elapsed_;
    std::shared_ptr<CallbackType> callback_;
    Timestamp countdownEndTimestamp_;
};

int main() {
    auto callback = std::make_shared<Timer::CallbackType>([] {std::cout << "hi" << std::endl; });

    Timer timer;
    timer.startTimer(callback, 5s);

    while(!timer.update());

    std::cout << "Done" << std::endl;

    return 0;
}