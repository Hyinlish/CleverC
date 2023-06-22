# CleverC

一个基于[Eigen](https://eigen.tuxfamily.org)实现的人工智能框架，希望让C++变得更聪明

## 依赖

### Eigen3  
对于Arch用户：  

```shell
sudo pacman -S eigen
```
对于使用离线版本的Eigen的用户，可以修改[all.h](./include/all.h)中的如下行：
```cpp
...
// Eigen标准库路径
#include <eigen3/Eigen/Core>
...
```
将其改为你需要的路径即可

## 进度

*<div>已经完成</div>*
*<div color='yellow'>正在努力</div>*
*<div color='gray'>计划中...</div>*

+ 神经网络（基本单元）
  + MLP
    + Activation Function
      + ReLU
      + Sigmoid 
      + Softmax
    + Loss Function
      + MSELoss
      + CrossEntropyLoss 
  + CNN
    + Conv
    + MaxPooling
    + <div color='yellow'>MeanPooling</div>
  + <div color='gray'>RNN</div>
+ 接口
  + <div color='yellow'>图像接口（基于stb_image)</div>
+ <div color='gray'>图形界面（实现一个简单的图形界面可以方便地搭建网络，包括使用已开发的单元和支持自定义单元）</div>
