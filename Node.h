#pragma once
#ifndef H_NODE
#define H_NODE

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

class Node
{
private:
    static vector<Node*> nodeList;
    static queue<int> idPool;

    ///Register a new node and return the id.
    static int registerNode(Node*);

public:
    ///Get the number of nodes.
    static int count();

    ///Get a pointer of node by id.
    static Node* select(const int &);

private:
    int id;
    string text;
    double x, y, z;
    pair<bool, double> input;
    map<string, string> remark;

public:
    ///Default constructor.
    Node();

    ///Constructor with text and coordinates.
    Node(const double &, const double &, const double & = 0);

    ///Destructor.
    ~Node();

    ///Get x-coordinate.
    double getX();

    ///Get y-coordinate.
    double getY();

    ///Get z-coordinate.
    double getZ();

    ///Get xy-coordinates.
    void getCoordinate(double &, double &);

    ///Get xyz-coordinates.
    void getCoordinate(double &, double &, double &);

    ///Get the input voltage.
    ///Return true iff this node has an input.
    bool getInput(double &);

    ///Set x-coordinate.
    void setX(const double &);

    ///Set y-coordinate.
    void setY(const double &);

    ///Set z-coordinate.
    void setZ(const double &);

    ///Set coordinates.
    void setCoordinate(const double & = 0.0, const double & = 0.0, const double & = 0.0);

    ///Set the input voltage.
    void setInput(const double &);

    ///Remove the input.
    void removeInput();

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

