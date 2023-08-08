观察矩阵的本质就是在摆放相机；
而确定一个相机的摆放有三个条件：position + look-at + up-direction
观察矩阵做的就是将Camera变换到标准位置上，origin + look-at -Z + up at Y

***
### 推导流程
t是相机的up方向，g是相机forward方向，g×t是相机的；
1. 先将相机移动到origin位置（e是相机的位置）： $Tview = \begin{matrix}1&0&0&-Xe\\0&1&0&-Ye\\0&0&1&-Ze\\0&0&0&1\end{matrix}$
2. 获取从标准朝向转到相机朝向的旋转矩阵： $R = \begin{matrix}Xg×t&Xt&X-g&0\\Yg×t&Yt&Y-g&0\\Zg×t&Zt&Z-g&0\\0&0&0&1\end{matrix}$ ， （$R × \begin{matrix}1&0&0&0\\0&1&0&0\\0&0&-1&0\\0&0&0&0\end{matrix} = \begin{matrix}Xg×t&Xt&Xg&0\\Yg×t&Yt&Yg&0\\Zg×t&Zt&Zg&0\\0&0&0&0\end{matrix}$  ）

3. 因为旋转矩阵是正交矩阵，将相机朝向转到标准朝向的旋转矩阵，就是R的逆矩阵，也就是R的转置矩阵：

$Rview= \begin{matrix}Xg×t&Yg×t&Zg×t&0\\Xt&Yt&Zt&0\\X-g&Y-g&Z-g&0\\0&0&0&1\end{matrix}$ ；

4. 最终得到观察矩阵： $Mview = Rview Tview = \begin{matrix}Xg×t&Yg×t&Zg×t&-Xg×tXe-Yg×tYe-Zg×tZe\\Xt&Yt&Zt&-XtXe-YtYe-ZtZe\\X-g&Y-g&Z-g&-X-gXe-Y-gYe-Z-gZe\\0&0&0&0\end{matrix}$ ；