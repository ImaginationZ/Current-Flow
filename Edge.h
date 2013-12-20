#pragma once
#ifndef H_EDGE
#define H_EDGE

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

using namespace std;

class Edge
{
private:
    static vector<Edge*> edgeList;
    static queue<int> idPool;

    ///Register a new node and return the id.
    static int registerEdge(Edge*);

public:
    ///Get the number of edges.
    static int count();

    ///Get a pointer of node by id.
    static Edge* select(const int &);

private:
    int id;
    int u, v;
    double r;

public:
    map<string, string> remark;

public:
    ///Default constructor.
    Edge();

    ///Constructor with text and coordinates.
    Edge(const int &, const int &, const double & = 0.0);

    ///Destructor.
    ~Edge();

    ///Get the end vertices of edge.
    pair<int, int> getEdge();

    ///Get the resistance.
    double getR();

    ///Set the resistance.
    void setR(const double &);

    ///Set the end vertices of the edge.
    void setEdge(const int &, const int &);

    ///Set remark.
    void setRemark(const string &, const string &);
    void setRemark(const string &, const int &);
    void setRemark(const string &, const double &);

    ///Get the remark.
    string getRemark(const string &);

    ///Get the remark as int.
    int getRemarkInt(const string &);

    ///Get the remark as double.
    double getRemarkDouble(const string &);
};

#endif

