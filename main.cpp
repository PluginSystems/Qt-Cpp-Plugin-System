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


    unsigned long count = 100;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->setUp();
        testCase->runTestFully(count);
        testCase->tearDown();
        std::cout << "Test run finished" << std::endl;
    }


    std::ofstream resultFileStream;

    std::stringstream  filename;

    filename << "results_"<< count << "_" << std::chrono::system_clock::now().time_since_epoch().count() << ".csv";


    resultFileStream.open(filename.str());

    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(resultFileStream);
    }
    benchmarks.clear();

    resultFileStream.close();

    return 0;
}