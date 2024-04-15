#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cmath>
const int MAX_DEG = 500;

void print_poly(int* p);
void get_poly(int* p1);
void poly_clear(int* p);
void poly_addition(int* p1, int* p2, int* pr);
void poly_subtraction(int* p1, int* p2, int* pr);
void poly_multiplication(int* p1, int* p2, int* pr);
void poly_mulbynum(int* p1, int p2, int* pr);
void poly_deriv(int* p, int* pr);
void poly_div(int* p1, int* p2, int* pr, int* po);


void work_polinom();