//
// Created by yannick lamprecht on 09.07.17.
//

#ifndef QTPLUGINTEST_STOPWATCH_H
#define QTPLUGINTEST_STOPWATCH_H


#include <chrono>

class Stopwatch {


private:

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;


public:

    void startTimer();


    void stopTimer();

    void reset();

    long long int getMicros();

    long long int getNanos();
};


#endif //QTPLUGINTEST_STOPWATCH_H
