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

#define INDEX(i, j)             ((i)*(n+1)+(j))

using namespace std;

const double Gauss::eps = 1e-12;

void Gauss::scan(const int &n, double *mat)
{
    Node* ptrV;
    Edge* ptrE;
    for (int i = 0; i < (int)Edge::count(); ++i)
        if ((ptrE = Edge::select(i)) != nullptr)
        {
            mat[INDEX((ptrE -> getEdge()).first, (ptrE -> getEdge()).second)] += 1.0/(ptrE -> getR());
            mat[INDEX((ptrE -> getEdge()).second, (ptrE -> getEdge()).first)] += 1.0/(ptrE -> getR());
        }
    for (int i = 0; i < n; ++i)
        if ((ptrV = Node::select(i)) != nullptr)
        {
            double voltage;
            if (ptrV -> getInput(voltage))
            {
                for (int j = 0; j < n; ++j)
                    mat[INDEX(i, j)] = 0.0;
                mat[INDEX(i, i)] = 1;
                mat[INDEX(i, n)] = voltage;
            }
            else
            {
                double sum = 0;
                for (int j = 0; j < n; ++j)
                    sum += mat[INDEX(i, j)];
                mat[INDEX(i, i)] -= sum;
                mat[INDEX(i, n)] = 0;
            }
        }
}

bool Gauss::gauss(const int &n, const int &m, double* mat, vector<double> &sol)
{
    int i, j, k, l;
    double* tmp = new double[n+1];
    for (i = j = 0; i < m && j < n; ++i, ++j)
    {
        for (k = l = i; k < m; ++k)
            if (fabs(mat[INDEX(k, j)]) > fabs(mat[INDEX(l, j)]))
                l = k;
        memcpy(tmp, mat+(i-1)*(n+1), sizeof(mat[0])*(n+1));
        memcpy(mat+(i-1)*(n+1), mat+(l-1)*(n+1), sizeof(mat[0])*(n+1));
        memcpy(mat+(l-1)*(n+1), tmp, sizeof(mat[0])*(n+1));
        if (fabs(mat[INDEX(i, j)] < eps))
        {
            --i;
            continue;
        }
        for (k = i+1; k < m; ++k)
        {
            double s = mat[INDEX(k, j)]/mat[INDEX(i, j)];
            for (l = j; l <= n; ++l)
                mat[INDEX(k, l)] -= mat[INDEX(i, l)]*s;
        }
    }
    if (i < j)
        return 0;
    delete tmp;
    for (i = n-1; i >= 0; --i)
        for (j = i-1; j >= 0; --j)
        {
            mat[INDEX(j, n)] -= mat[INDEX(i, n)]*mat[INDEX(j, i)]/mat[INDEX(i, i)];
            mat[INDEX(j, i)] = 0;
        }
    sol.clear();
    for (int i = 0; i < n; ++i)
        sol.push_back(mat[INDEX(i, i)]);
    return 1;
}

bool Gauss::solve()
{
    vector<double> sol;
    int n = Node::count();
    int m = n+1;
    double* mat = new double[n*m];
    memset(mat, 0, sizeof(mat[0])*n*(n+1));

    scan(n, mat);
    bool res = gauss(n, m, mat, sol);

    delete [] mat;
    
    if (! res)
        return 0;

    Node* ptrV;
    Edge* ptrE;
    for (int i = 0; i < n; ++i)
        if ((ptrV = Node::select(i)) != nullptr)
            ptrV -> setRemark("voltage", sol[i]);
    for (int i = 0; i < Edge::count(); ++i)
        if ((ptrE = Edge::select(i)) != nullptr)
            ptrE -> setRemark("current", (sol[ptrE->getEdge().first]-sol[ptrE->getEdge().second])/ptrE->getR());
    return 1;
}

