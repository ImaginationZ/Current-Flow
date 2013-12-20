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

#include "Edge.h"

using namespace std;

vector<Edge*> Edge::edgeList;
queue<int> Edge::idPool;

int Edge::registerEdge(Edge* ptr)
{
    if (! idPool.size())
    {
        idPool.push(edgeList.size());
        edgeList.push_back(nullptr);
    }
    const int id = idPool.back();
    idPool.pop();
    edgeList[id] = ptr;
    return id;
}

int Edge::count()
{
    return edgeList.size();
}

Edge* Edge::select(const int &id)
{
    return edgeList[id];
}

Edge::Edge():u(-1), v(-1), r(0.0)
{
    remark.clear();
    id = registerEdge(this);
}

Edge::Edge(const int &_u, const int &_v, const double &_r):u(_u), v(_v), r(_r)
{
    remark.clear();
    id = registerEdge(this);
}

Edge::~Edge()
{
    edgeList[id] = nullptr;
    idPool.push(id);
}

pair<int, int> Edge::getEdge()
{
    return make_pair(u, v);
}

double Edge::getR()
{
    return r;
}

void Edge::setR(const double &_r)
{
    r = _r;
}

void Edge::setEdge(const int &_u, const int &_v)
{
    u = _u;
    v = _v;
}

void Edge::setRemark(const string &key, const string &value)
{
    remark[key] = value;
}

void Edge::setRemark(const string &key, const int &value)
{
    ostringstream buffer;
    buffer << value;
    remark[key] = buffer.str();
}

void Edge::setRemark(const string &key, const double &value)
{
    ostringstream buffer;
    buffer << setprecision(10) << fixed << value;
    remark[key] = buffer.str();
}

string Edge::getRemark(const string &key)
{
    return remark[key];
}

int Edge::getRemarkInt(const string &key)
{
    return atoi(remark[key].c_str());
}

double Edge::getRemarkDouble(const string &key)
{
    istringstream buffer(remark[key]);
    double value;
    buffer >> value;
    return value;
}
