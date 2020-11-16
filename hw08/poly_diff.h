#ifndef __POLY_DIFF_H__
#define __POLY_DIFF_H__

#include <vector>
#include <iostream>
using namespace std;

class Splited {
public:
    Splited(string data);
    void Differentiate();
    int sumValue(int x);
private:
    int times_;
    int constant_;
};

class Differ {
public:
    int sumValue(int x);
    void Spliting(string data);
    
private:
    std::vector<Splited> splited_;
};

#endif
