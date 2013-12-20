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

using namespace std;

vector<Node*> Node::nodeList;
queue<int> Node::idPool;

int Node::registerNode(Node* ptr)
{
    if (! idPool.size())
    {
        idPool.push(nodeList.size());
        nodeList.push_back(nullptr);
    }
    const int id = idPool.back();
    idPool.pop();
    nodeList[id] = ptr;
    return id;
}

int Node::count()
{
    return nodeList.size();
}

Node* Node::select(const int &id)
{
    return nodeList[id];
}

Node::Node():x(0.0), y(0.0), z(0.0)
{
    input.first = 0;
    input.second = 0.0;
    remark.clear();
    id = registerNode(this);
}

Node::Node(const double &_x, const double &_y, const double &_z):x(_x), y(_y), z(_z)
{
    input.first = 0;
    input.second = 0.0;
    remark.clear();
    id = registerNode(this);
}

Node::~Node()
{
    nodeList[id] = nullptr;
    idPool.push(id);
}

double Node::getX()
{
    return x;
}

double Node::getY()
{
    return y;
}

double Node::getZ()
{
    return z;
}

void Node::getCoordinate(double &_x, double &_y)
{
    _x = x;
    _y = y;
}

void Node::getCoordinate(double &_x, double &_y, double &_z)
{
    _x = x;
    _y = y;
    _z = z;
}

bool Node::getInput(double &voltage)
{
    if (! input.first)
        return 0;
    voltage = input.second;
    return 1;
}

void Node::setX(const double &_x)
{
    x = _x;
}

void Node::setY(const double &_y)
{
    y = _y;
}

void Node::setZ(const double &_z)
{
    z = _z;
}

void Node::setCoordinate(const double &_x, const double &_y, const double &_z)
{
    x = _x;
    y = _y;
    z = _z;
}

void Node::setInput(const double &voltage)
{
    input.first = 1;
    input.second = voltage;
}

void Node::removeInput()
{
    input.first = 0;
    input.second = 0.0;
}

void Node::setRemark(const string &key, const string &value)
{
    remark[key] = value;
}

void Node::setRemark(const string &key, const int &value)
{
    ostringstream buffer;
    buffer << value;
    remark[key] = buffer.str();
}

void Node::setRemark(const string &key, const double &value)
{
    ostringstream buffer;
    buffer << setprecision(10) << fixed << value;
    remark[key] = buffer.str();
}

string Node::getRemark(const string &key)
{
    return remark[key];
}

int Node::getRemarkInt(const string &key)
{
    return atoi(remark[key].c_str());
}

double Node::getRemarkDouble(const string &key)
{
    istringstream buffer(remark[key]);
    double value;
    buffer >> value;
    return value;
}

