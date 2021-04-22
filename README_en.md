# KMP algorithm implementation STRSTR interface

KMP algorithm to achieve the STRSTR implementation, based on pure C implementation, easy to use.
* * *

## usage

The external interface is provided in "kmp.h".

- If you simply replace the `strstr` function  
Then use the `kmp_strstr` interface directly to replace.
- If the field to be searched is fixed in the program  
You can use the `kmp_strstr_dp` interface for better performance.  
PS: This method requires you to call the `dp_construct` and `dp_destroy` interfaces to maintain the memory of dp array.

* * *

## how to test

~~~shell
# cd test/
# make
gcc main.c ../src/KMP.c -g -o runKMP
#. / runKMP
kmp result1 = abcabcbbccc
strstr result1 = abcabcbbccc
kmp result2 = ccc
strstr result2 = ccc
~~~

* * *

## reference

The specific implementation of the algorithm refers to the detailed introduction of the algorithm of Zhihu boss, detailed description can see the original paste:  
[zhihu portal](https://zhuanlan.zhihu.com/p/83334559)
