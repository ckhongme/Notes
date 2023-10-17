[[四元数]]
***
```C#
q.eulerAngles //四元数对应的欧拉角
Quaternion.identity  //单位四元数
```
### 方法
```C#
//表示从from方向旋转到to方向所转过的角度
Quaternion.FromToRotation（Vector3 fromDirection， Vector3 toDirection）

//表示看向某个指定坐标需要转过的角度
Quaternion.LookRotation（Vector3 forward） 
Quaternion.LookRotation（Vector3 forward， Vector3 upwards） //第二个参数可以指定对象哪个朝向指向上方

//计算两个四元数前方矢量之间的夹角度数
Quaternion.Angle（Quaternion a，Quaternion b）

//通过欧拉角的度数创建一个四元数
Quaternion.Euler（float x, float y, float z）

//创建四元数，返回一个绕轴线旋转 angle 角度的 四元数变换；
Quaternion.AngleAxis(float angle, Vector3 axis);

//球面插值，构建从四元素a到b的球面插值
Quaternion.Slerp（Quaternion a, Quaternion b, float t）
```
### 四元数乘以向量
```C#
//获取transform的向前方向 
Vector3 forward = new Vector3(0,0,1); 
Vector3 tfmForward = transform.rotation * forward; 

//沿自身局部坐标系下的V方向移动 V的模长的距离； 
transform.positon += transform.rotation * V;

```
### 四元数之间相乘
右乘：按照先绕z轴再绕x轴最后绕y轴的旋转次序；
```C#
// target会绕着自身坐标的 x 轴旋转45度；（局部坐标系下的 Vector.right) 
target.rotation = target.rotation * Quaternion.AngleAxis(45, Vector3.right); 

// target会绕着 在自身局部坐标系下，相对于原来自身 right向量相对与世界坐标的轴，旋转45度； 
target.rotation = target.rotation * Quaternion.AngleAxis(45, target.right);
```
左乘：
```C#
// target会绕着世界坐标的 x 轴旋转45度； 
target.rotation = Quaternion.AngleAxis(45, Vector3.right) * target.rotation; 

// target会绕着自身坐标的 x 轴旋转45度； 
target.rotation = Quaternion.AngleAxis(45, target.right) * target.rotation;
```
