### 哈希集合 Hash Set
基于HashMap实现的无序集合数据结构；
存储的数据是元素值（value），每个元素值本身就是一个键；

##### 应用：去重
不允许集合中有重复元素；
HashSet在存储对象之前，需要确保重写对象的hashCode()方法和equals()方法，从而比较对象的值是否相等，确保集合中没有
储存相同的对象；

HashMap | HashSet
--|--
实现Map接口|实现Set接口
存储键值对|仅存储对象
使用Key计算hashCode|使用成员对象来计算hashcode

***

### Tree Set




