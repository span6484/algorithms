#include <stdio.h>
#include <stdlib.h>
/*
二级指针传入参数规则

1. 当二级指针作为函数形参时，能作为函数实参的是二级指针，指针数组，一级指针的地址

2. 当指针数组作为函数形参时，能作为函数实参的是二级指针,指针数组,一级指针的地址

3. 当数组指针作为函数形参时，能作为函数实参的是二维数组，数组指针

4. 当二维数组作为函数形参时，能作为函数实参的是二维数组，数组指针

总结：1，2相同，3，4相同
*/
void two_ptr(int **pp)  // 二级指针
{ 
    printf("two_ptr\n");
}

void ptr_arr(int *p_a[5])  //指针数组
{
    printf("ptr_arr\n");
}

void arr_ptr(int(*a_p)[5])  //数组指针
{
    printf("arr_ptr\n");
}
void two_arr(int t_d_a[][5])  //二维数组
{
    printf("two_arr\n");
}

int main()
{
    int *p_a[5];          //指针数组
    int **pp = NULL;      //二级指针
    int *p = NULL;        //一级指针
    int t_a[5][5];      //二维数组
    int a[5];             //一维数组
    int(*a_p)[5] = &a;    //数组指针

    //规则1:当二级指针作为函数形参时
    //能作为函数实参的是
    //二级指针，指针数组，一级指针的地址
    two_ptr(pp);
    two_ptr(p_a);
    two_ptr(&p);
    //two_ptr(t_a);  //二维数组不可
    //two_ptr(a_p);  //数组指针不可
    printf("\n");

    //2. 当指针数组作为函数形参时，能作为函数实参的是
    //二级指针,指针数组,一级指针的地址
    ptr_arr(pp);
    ptr_arr(p_a);
    ptr_arr(&p);
    //ptr_arr(t_a); //二维数组不可
    //ptr_arr(a_p); //数组指针不可
    printf("\n");

    //3. 当数组指针作为函数形参时
    //能作为函数实参的是
    //二维数组，数组指针

    //arr_ptr(p_a);  //指针数组不可
    //arr_ptr(pp);   //二级指针不可
    //arr_ptr(&p);   //一级指针不可
    arr_ptr(t_a);
    arr_ptr(a_p);
    printf("\n");

    //4. 当二维数组作为函数形参时
    //能作为函数实参的是
    //二维数组，数组指针

    //two_arr(p_a);  //指针数组不可
    //two_arr(pp);   //二级指针不可
    //two_arr(&p);   //一级指针不可
    two_arr(t_a);
    two_arr(a_p);
    printf("\n");



    return 0;
}
