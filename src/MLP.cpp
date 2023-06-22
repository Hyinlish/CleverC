#include <MLP.h>

/**
 * MPL
*/
MatrixXd MLP::forward(MatrixXd inp)
{
    this->pre_inp = inp;
    return inp * w + b;
}
MatrixXd MLP::backward(MatrixXd back)
{
    this->dw = this->pre_inp.transpose() * back;
    this->db = back;
    return back * this->w.transpose();
}
void MLP::update(double lr)
{
    this->w -= this->dw * lr;
    this->b -= this->db * lr;
}
/**
 * ReLU
*/
MatrixXd ReLU::forward(MatrixXd inp)
{
    // 可用cwiseMax优化，到时候再说
    int height = inp.rows();
    int width  = inp.cols();
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            inp(i, j) = inp(i, j) < 0 ? 0 : inp(i, j);
        }
    }
    return inp;
}
MatrixXd ReLU::backward(MatrixXd back)
{
    int height = back.rows();
    int width  = back.cols();
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            back(i, j) = back(i, j) < 0 ? 0 : 1;
        }
    }
    return back;
}
/**
 * Sigmoid
*/
MatrixXd Sigmoid::forward(MatrixXd inp)
{
    int height = inp.rows();
    int width  = inp.cols();
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            inp(i, j) = 1 / (1 + exp(-inp(i, j)));
        }
    }
    return inp;
}
MatrixXd Sigmoid::backward(MatrixXd back)
{
    int height = back.rows();
    int width  = back.cols();
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            double x = back(i, j);
            back(i, j) = exp(-x) / pow((1 + exp(-x)) , 2);
        }
    }
    return back;
}
/**
 * Softmax
*/
MatrixXd Softmax::forward(MatrixXd inp)
{
    // 防止溢出
    inp.array() -= inp.maxCoeff();
    this->pre = inp.array().exp() / inp.array().exp().sum();
    return this->pre;
}
MatrixXd Softmax::backward(MatrixXd back)
{
    // cout << diag(back) << endl;
    // return diag(back) -= back.transpose() * back;
    return this->pre - back;
}
/**
 * MSELoss
*/
MatrixXd MSELoss::get_loss(MatrixXd out, double num)
{
    return -pow(out.array() -= num, 2);
}
/**
 * CrossEntropyLoss
*/
MatrixXd CrossEntropyLoss::get_loss(MatrixXd out, double num)
{
    return -out.array().log10() * num;
}
