#include <iostream>
#include <sstream>
#include <fstream>
#include "PluginLoader.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"


int main(int argc, char **argv) {

    std::list<std::shared_ptr<TestCase>> benchmarks;


    PluginLoader loader("plugin");


    benchmarks.push_back(std::make_shared<LoadAndUnloadBenchmark>(LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::make_shared<EnableAndDisableBenchmark>(EnableAndDisableBenchmark(loader)));


    // 10 50 70 100 250

    std::list<unsigned long> rounds = {10,50,70,100,250};


    for (auto count : rounds) {

        for (std::shared_ptr<TestCase> testCase: benchmarks) {
            testCase->setUp();
            testCase->runTestFully(count);
            testCase->tearDown();
            std::cout << "Test run finished" << std::endl;
        }


        for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {

            std::ofstream resultFileStream;

            std::stringstream filename;

            filename << "results_" << count << "_" << finishedBenchmark->getName() << "_nanoseconds_"
                     << std::chrono::system_clock::now().time_since_epoch().count() << ".csv";


            resultFileStream.open(filename.str());

            finishedBenchmark->printStats(resultFileStream);

            resultFileStream.close();
        }
    }
    benchmarks.clear();


    return 0;
}