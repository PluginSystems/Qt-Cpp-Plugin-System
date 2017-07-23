//
// Created by yannick lamprecht on 09.07.17.
//

#include "Stopwatch.h"

void Stopwatch::startTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void Stopwatch::stopTimer() {
    endTime = std::chrono::high_resolution_clock::now();
}

void Stopwatch::reset() {
    startTime = endTime = {};
}

long long int Stopwatch::getMicros() {
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}

long long int Stopwatch::getNanos() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}
