//
// Created by Mindaugas K on 10/1/2019.
//

#ifndef HASH_GEN_TIMER_H
#define HASH_GEN_TIMER_H
#include <chrono>
class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};
#endif //HASH_GEN_TIMER_H
