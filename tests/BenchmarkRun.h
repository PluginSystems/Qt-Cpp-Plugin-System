//
// Created by yannick lamprecht on 10.07.17.
//

#ifndef QTPLUGINTEST_BENCHMARKRUN_H
#define QTPLUGINTEST_BENCHMARKRUN_H


#include <unordered_map>
#include <string>
#include <list>
#include <ostream>
#include <map>

class BenchmarkRun {

private:

    std::map<std::string,long> _stats;

public:

    void defineBenchmarkPoint(std::string benchmarkPointName, long microsElapsed);

    void defineBenchmarkPoint(std::string benchmarkPointName, int run, long microsElapsed);

    std::list<std::string> getStatsCommaSeparatedList();

    void printStats(std::ostream& outputStream);






};


#endif //QTPLUGINTEST_BENCHMARKRUN_H
