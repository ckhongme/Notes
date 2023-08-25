Gamma Correction，在最终的颜色输出上应用显示器Gamma的倒数；
例如将 Gamma0.45叠加到Gamma2.2的CRT显示设备上，就可以对偏暗的显示效果做到矫正；
##### 为什么需要Gamma校正？
在渲染图象时，需要将显示器压缩过的图像恢复到原来的线性；
核心思路：通过一个采样的反函数把非线性的采样还原成线性；（绿色线表示0.45，红色线表示2.2）
![[Gamma矫正3.png]]
显示器在得到经过Gamma校正的颜色后会做Gamma压缩，相互抵消后得到线性Gamma（Gamma值为1）；
##### Gamma校正公式
```glsl
outputColor = pow(inputColor, 1/gamma);
```
![[gamma_correction_gamma_curves.png]]
Gamma校正会把线性色彩空间转变为非线性空间，所以需要在将颜色传给显示器的最后一步再做Gamma校正；（在发送到帧缓冲前，将颜色校正）
```glsl
fragColor = pow(color, vec3(1.0/2.2));
```