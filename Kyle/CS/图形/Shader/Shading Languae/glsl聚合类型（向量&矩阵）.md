## 向量
***
##### float类型的向量 vecn
vecn包含1到4个**float**分量，数量由它的后缀数字n决定；（例如vec3表示3维向量）
其中vec.x，vec.y，vec.z表示空间位置，vec.w用在透视除法上；
##### 其他类型的向量
分量的类型默认是float，也可以是其他类型；
-   bvecn - 包含n个**bool**分量的向量
-   ivecn - 包含n个**int**分量的向量
-   uvecn - 包含n个**unsigned int**分量的向量
-   dvecn - 包含n个**double**分量的向量
***
##### 向量重组
```glsl
vec2 someVec;
vec4 differentVec = someVec.xyxx;
vec3 anotherVec = differentVec.zyw;
vec4 otherVec = someVec.xxxx + anotherVec.yxzy;
```
可以把一个向量作为一个参数传给不同的向量构造函数
```glsl
vec2 vect = vec2(0.5, 0.7);
vec4 result = vec4(vect, 0.0, 0.0);
vec4 otherResult = vec4(result.xyz, 1.0);
```
***
### 矩阵
N代表列数，M代表函数，NxM表示3列4行的矩阵；
初始矩阵为对角矩阵；
##### 长度
矩阵的lengthf方法返回包含的列数，列的长度返回行的个数；
```glsl

mat3x3 mat;
int columeNum = mat.length;
int rowNum = mat[0].length;

```

float类型的矩阵 matN 或者 matNxM
double类型的矩阵 dmatN 或者 dmatNxM


