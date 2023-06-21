# MLP
记录一下经典的MLP的公式  

## 前向传播：

来自上一层的输出：
$$
x =
\begin{bmatrix}
x_1 & x_2 & \cdots & x_m
\end{bmatrix}
$$

权重：
$$
w =
\begin{bmatrix}
w_{11} & \cdots & w_{1n} \\
w_{21} & \cdots & w_{2n} \\
\vdots & \ddots & \vdots \\
w_{m1} & \cdots & w_{mn}
\end{bmatrix}
$$

偏置：
$$
b =
\begin{bmatrix}
b_1 & b_2 & \cdots & b_n
\end{bmatrix}
$$
输出结果：
$$
y = wx + b =
\begin{bmatrix}
y_1 & y_2 & ... & y_n
\end{bmatrix}
$$

## 反向传播：
