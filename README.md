# KMP算法实现的strstr接口

用KMP算法实现的strstr实现，基于纯C实现，方便使用。
***

## usage

对外接口在"KMP.h"中提供  

- 如果只是简单的替换`strstr`函数  
那么直接使用`kmp_strstr`接口替换即可
- 如果需要被搜索的字段在程序中是固定的  
可以使用`kmp_strstr_dp`接口来获得更好的性能  
PS:  该使用方式需要自己调用`dp_construct`、`dp_destroy`接口维护dp数组的内存  

***

## how to test

~~~shell
# cd test/

# make
gcc main.c ../src/KMP.c -g -o runKMP

# ./runKMP  
kmp result1 = abcabcbbccc
strstr result1 = abcabcbbccc
kmp result2 = ccc
strstr result2 = ccc
~~~

***

## reference

算法的具体实现参考了知乎大佬的算法详细介绍，详细说明可以看原贴:  
[知乎传送门](https://zhuanlan.zhihu.com/p/83334559)
