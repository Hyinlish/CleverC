#include <Tools.h>

// #include <iostream>
// using namespace std;

MatrixXd rot90(MatrixXd m)
{
    int w = m.cols();
    int h = m.rows();
    // 定义返回的矩阵
    // 因为是旋转的，所以列和行颠倒，当然n*n矩阵无所谓
    MatrixXd ret = MatrixXd::Zero(w, h);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            ret(j, h-i-1) = m(i, j);
        }
    }
    return ret;
}

MatrixXd rot180(MatrixXd m)
{
    int w = m.cols();
    int h = m.rows();
    // 定义返回的矩阵
    MatrixXd ret = MatrixXd::Zero(h, w);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            ret(h-i-1, w-j-1) = m(i, j);
        }
    }
    return ret;
}

MatrixXd pad(MatrixXd m)
{
    int w = m.cols();
    int h = m.rows();
    // 定义返回的矩阵
    MatrixXd ret = MatrixXd::Zero(h+2, w+2);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            ret(i+1, j+1) = m(i, j);
        }
    }
    return ret;
}

MatrixXd diag(MatrixXd m)
{
    int w = m.cols();
    MatrixXd ret = MatrixXd::Zero(w, w);
    for(int i=0; i<w; i++)
    {
        ret(i, i) = m(i);
    }
    return ret;
}