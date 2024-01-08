/**
 * @file: /BasicCMakeProject/components/Function1/Function1.c
 * @author: Wangxiang
 * @brief:
 * @version: V0.1
 * @date: 2024-01-08 15:07:17
 * 江苏大学-王翔
 */
#include "Function1.h"

void function1_test(int n)
{
    printf("\r\nthis is %s in file %s, input param: %d\r\n", __FUNCTION__, __FILE__, n);
}
