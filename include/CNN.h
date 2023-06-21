#ifndef CNN_H
#define CNN_H

#include "all.h"
#include "Tools.h"

using namespace Eigen;

/**
 * CNN卷积层
 * 
 * \note 输入输出均为二维矩阵
 * 
 * \param k_size 卷积核大小，暂定都为正方形矩阵
*/
class CNN
{
    private:
        MatrixXd k;
        MatrixXd dk;
        MatrixXd pre_inp;
        int k_size;
    public:
        CNN(int k_size)
        {
            this->k_size = k_size;
            this->k = MatrixXd::Random(k_size, k_size);
            this->dk = MatrixXd::Zero(k_size, k_size);
        }
        // 基本卷积操作
        MatrixXd conv(MatrixXd inp, MatrixXd k);
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
        void update(double lr);
};
/**
 * 最大池化层
 * 
 * \param step 池化步长
*/
class MaxPooling
{
    private:
        int step;
        MatrixXd pos;
    public:
        MaxPooling(int step)
        {
            this->step = step;
        }
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
};
/**
 * 平均池化层
*/
class MeanPooling
{
    public:
        MatrixXd forward(MatrixXd inp);
        MatrixXd backward(MatrixXd back);
};

#endif