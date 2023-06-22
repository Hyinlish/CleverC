#ifndef MLP_H
#define MLP_H

#include "all.h"
#include "Tools.h"

using namespace Eigen;

/**
 * MLP全连接层
 * 
 * \note 输入输出均为一维行矩阵
 * 
 * \param size_in  输入形状
 * \param size_out 输出形状 
*/
class MLP
{
    private:
        MatrixXd w, b;
        MatrixXd dw, db;
        MatrixXd pre_inp;   
    public:
        MLP(int size_in, int size_out)
        {
            this->w = MatrixXd::Random(size_in, size_out);
            this->b = MatrixXd::Random(1, size_out);
        }
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
        void update(double lr);
};
// 激活函数=========================================================
/**
 * ReLU激活函数
*/
class ReLU
{
    public:
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);    
};
/**
 * Sigmoid激活函数
*/
class Sigmoid
{
    public:
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
};
/**
 * Softmax激活函数
*/
class Softmax
{
    private:
        MatrixXd pre;
    public:
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
};
// 损失函数===============================================================
class MSELoss
{
    public:
        MatrixXd get_loss(MatrixXd out, double num);
};
class CrossEntropyLoss
{
    public:
        MatrixXd get_loss(MatrixXd out, double num);
};

#endif