#include <MLP.h>
#include <CNN.h>
#include <iostream>

using namespace std;

// 是时候搭建一个来玩玩了
Sigmoid S1;
MLP Net1 = MLP(2, 4);
ReLU R1;
MLP Net2 = MLP(4, 4);
ReLU R2;
MLP Net3 = MLP(4, 1);

// MatrixXd NetForward(MatrixXd inp)
// {
//     MatrixXd out = Net1.forward(inp);
//     out = R1.forward(out);
//     out = Net2.forward(out);
//     out = R2.forward(out);
//     out = Net3.forward(out);
//     out = S1.forward(out);
//     return out;
// }
// void NetBackward(MatrixXd loss)
// {
//     MatrixXd back = S1.backward(loss);
//     back = Net3.backward(loss);
//     back = R2.backward(back);
//     back = Net2.backward(back);
//     back = R1.backward(back);
//     back = Net1.backward(back);
//     Net3.update(0.1);
//     Net2.update(0.1);
//     Net1.update(0.1);
// }

int main()
{
    cout << "Hello" << endl;
    // Matrix<double, 1, 2> testlis[4];
    // testlis[0] << 1, 2;
    // testlis[1] << 3, 6;
    // testlis[2] << 2, 1;
    // testlis[3] << 4, 2;
    // int anslis[4];
    // anslis[0] = 1;
    // anslis[1] = 1;
    // anslis[2] = 0;
    // anslis[3] = 0;
    // cout << "Training...";
    // for(int j=0; j<5; j++)
    // {
    //     for(int i=0; i<4; i++)
    //     {
    //         MatrixXd out = NetForward(testlis[i]);
    //         MatrixXd los(1, 1);
    //         los << -pow(out(0, 0) - anslis[i], 2);
    //         NetBackward(los);
    //     }
    // }
    // cout << "Done" << endl;
    // MatrixXd test(1, 2);
    // test << 5, 1;
    // cout << NetForward(test) << endl;
    // //
    // Matrix<double,5,5> test2;
    // test2 << 1,1,1,1,1,
    //          2,1,2,1,1,
    //          3,1,3,1,1,
    //          1,2,3,4,5,
    //          5,3,4,3,1;
    // Matrix<double,2,2> test3;
    // test3 << 1,1,
    //          1,1;
    // CNN C1 = CNN(2);
    // MaxPooling M1 = MaxPooling(2);
    // // 前传
    // cout << test2 << endl;
    // cout << "CNN" << endl;
    // cout << C1.forward(test2) << endl;
    // cout << "MaxPooling" << endl;
    // cout << M1.forward(C1.forward(test2)) << endl;
    // // 反传
    // cout << "反传" << endl;
    // cout << M1.backward(test3) << endl;
    // cout << C1.backward(M1.backward(test3)) << endl;
    // C1.update(0.1);
    MatrixXd test = MatrixXd::Zero(1,5);
    MatrixXd back = MatrixXd::Zero(1,5);
    test << 1,2,3,4,5;
    back << 1,2,1,2,1;
    cout << test << endl;
    Softmax S;
    CrossEntropyLoss C;
    cout << S.forward(test) << endl;
    cout << S.backward(C.get_loss(S.forward(test),2)) << endl;
    return 0;
}