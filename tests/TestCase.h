//
// Created by yannick lamprecht on 09.07.17.
//

#ifndef QTPLUGINTEST_TESTCASE_H
#define QTPLUGINTEST_TESTCASE_H


#include <string>
#include <ostream>
#include <list>
#include <vector>
#include "BenchmarkRun.h"
#include "util/Stopwatch.h"

class TestCase {

private:

    Stopwatch stopwatch = Stopwatch();

    std::vector<BenchmarkRun> benchmarkRuns;

    long long getElapsedMicros() {
        return stopwatch.getMicros();
    }


protected:


    PluginLoader& loader;

    virtual void runTest(unsigned long cycle)=0;

    virtual std::string getName()=0;





    void startTimer() {
        stopwatch.startTimer();
    }

    void stopTimer() {
        stopwatch.stopTimer();
    }

    void resetTimer() {
        stopwatch.reset();
    }

    void defineBenchmarkPoint(unsigned long cycle, std::string benchmarkPointName) {
        benchmarkRuns.at(cycle).defineBenchmarkPoint(benchmarkPointName, getElapsedMicros());
    }

    void defineBenchmarkPoint(unsigned long cycle, std::string benchmarkPointName, int run) {
        benchmarkRuns.at(cycle).defineBenchmarkPoint(benchmarkPointName, run, getElapsedMicros());
    }


public:

    TestCase(PluginLoader& pluginLoader): loader(pluginLoader){
    }

    virtual void setUp(){}
    virtual void tearDown(){}


    void runTestFully(unsigned long cycles) {
        benchmarkRuns = std::vector<BenchmarkRun>(cycles);

        for (unsigned long i = 0; i < cycles; i++) {
            benchmarkRuns.push_back(BenchmarkRun());
            std::cout << "Test in run " << (i+1) << " started" << std::endl;
            runTest(i);
        }
    }

    void printStats(std::ostream &outputStream) {
        outputStream << "Benchmark " << getName() << ";microseconds/op" << std::endl;

        for (auto benchmark : benchmarkRuns) {
            benchmark.printStats(outputStream);
        }
    }
};


#endif //QTPLUGINTEST_TESTCASE_H
