#include <CNN.h>

// #include <iostream>
// using namespace std;

/**
 * CNN
*/
MatrixXd CNN::conv(MatrixXd inp, MatrixXd thek)
{
    int back_h = inp.rows() - thek.rows() + 1;
    int back_w = inp.cols() - thek.cols() + 1;
    // 存储返回值
    MatrixXd back = MatrixXd::Zero(back_h, back_w);
    for(int i=0; i<back_h; i++)
    {
        for(int j=0; j<back_w; j++)
        {
            // cwiseProduct()相当于Hadamard积
            back(i, j) = thek.cwiseProduct(inp.block(i,j,thek.rows(),thek.cols())).sum();
        }
    }
    return back;
}
MatrixXd CNN::forward(MatrixXd inp)
{
    this->pre_inp = inp;
    return conv(inp, this->k);
}
MatrixXd CNN::backward(MatrixXd back)
{
    // 计算反传梯度
    MatrixXd ret = conv(pad(back), rot180(this->k));
    // 计算卷积核导数
    this->dk = conv(pre_inp, back);
    return ret;
}
void CNN::update(double lr)
{
    this->k -= this->dk * lr;
}
/**
 * MaxPooling
*/
MatrixXd MaxPooling::forward(MatrixXd inp)
{
    this->pos = MatrixXd::Zero(inp.rows(), inp.cols());
    // 记录返回值
    MatrixXd ret = MatrixXd::Zero(inp.rows()/step, inp.cols()/step);
    // 最大值坐标
    MatrixXd::Index r, c;
    for(int i=0; i<inp.rows(); i+=step)
    {
        for(int j=0; j<inp.cols(); j+=step)
        {
            double max = inp(seqN(i,this->step), seqN(j,this->step)).maxCoeff(&r, &c);
            // 转换为绝对位置并置1
            this->pos(i+r, j+c) = 1;
            ret(i/step, j/step) = max;
        }
    }
    return ret;
}
MatrixXd MaxPooling::backward(MatrixXd back)
{
    // 分配返回值到pos记录的位置
    for(int i=0; i<back.rows()*step; i+=step)
    {
        for(int j=0; j<back.cols()*step; j+=step)
        {
            this->pos(seqN(i,step), seqN(j,step)) *= back(i/step, j/step);
        }
    }
    return pos;
}
/**
 * MeanPooling
*/