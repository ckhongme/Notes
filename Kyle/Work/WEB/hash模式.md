产生的目录结构会多个 # 号；（[[路由(前端)]]可以实现不刷新页面跳转）
[[URL]]的 hash 也就是锚点(#)，本质上是改变 window.location 的 href 属性，可以通过直接赋值 location.hash 来改变 href，但是页面不发生刷新；