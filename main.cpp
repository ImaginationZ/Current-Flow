#include "mainwindow.h"
#include <QApplication>
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
#include "Gauss.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Phy w;
    w.show();

    return a.exec();
}
