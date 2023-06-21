/**
 * 补充一些Eigen里似乎没有的函数
 * 适应numpy用户
*/
#ifndef TOOLS_H
#define TOOLS_H

#include "all.h"

using namespace Eigen;

/**
 * Hadamard积
*/
MatrixXd hadamard(MatrixXd m1, MatrixXd m2);
/**
 * 矩阵旋转
*/
MatrixXd rot90(MatrixXd m);
MatrixXd rot180(MatrixXd m);
/**
 * Pad
 * 暂时仅支持周围一圈填0,为卷积服务
*/
MatrixXd pad(MatrixXd m);

#endif