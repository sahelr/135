/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E7.1
The program takes 2 integer points and sorts them in order.
*/
#include <iostream>
void sort2(double* p, double* q) {
    if(*p > *q) {
        *p = *p + *q;
        *q = *p - *q;
        *p = *p - *q;
    }
}