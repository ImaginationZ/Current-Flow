#pragma once
#ifndef H_GAUSS
#define H_GAUSS

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#include "Node.h"
#include "Edge.h"

using namespace std;

class Gauss
{
private:
    static const double eps;
private:
    static void scan(const int &, double *);
    static bool gauss(const int &, const int &, double*, vector<double> &);

public:
    ///Calculate the voltage of every node.
    ///The solution will be saved as the remark "voltage" of Node.
    ///And the current will be saved as the remark "current" of Edge.
    static bool solve();
};

#endif

