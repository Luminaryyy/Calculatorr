#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_error.h>

void work_function(int argc, char* args[]);

void draw_graph(int argc, char* args[]);
void integral();
void searchRoot();
void searchExtremums();

/// Построение графика \\\

double polynomialFunction(double x, double* coefficient, int n);
void polinomial1();
double degreeFunction(double x, double a0, double b0, double c0);
void degree1();
double exponentialFunction(double x, double a0, double b0, double c0, double d0);
void exponential1();
double logarithmFunction(double x, double a0, double b0, double c0);
void logarithm1();
double sinusoidFunction(double x, double a0, double b0, double c0, double d0);
void sinusoid1();
double cosinusFunction(double x, double a0, double b0, double c0, double d0);
void cosinusoid1();
void function_choice();

/// Поиск корня на отрезке \\\

double func11(double x, double* coefficient, int n, double a0);
void Polinom1();
double func12(double a0, double b0, double c0, double x);
void Degrees1();
double func13(double a0, double b0, double c0, double x, double d0);
void Exponential1();
double func14(double a0, double b0, double c0, double x);
void Logarithm1();
double func15(double a0, double b0, double c0, double d0, double x);
void SineWave1();
double func16(double a0, double b0, double c0, double d0, double x);
void CosineWave1();

/// Поиск экстремума на отрезке \\\

double func21(double x, double* coefficient, int n, double a0);
double findMinExtremumsPolinom2(double a, double b, double* coefficient, int n, double a0);
double findMaxExtremumsPolinom2(double a, double b, double* coefficient, int n, double a0);
void Polinom2();
double func22(double a0, double b0, double c0, double x);
double findMinExtremumsDegrees2(double a, double b, double a0, double b0, double c0);
double findMaxExtremumsDegrees2(double a, double b, double a0, double b0, double c0);
void Degrees2();
double func23(double a0, double b0, double c0, double x, double d0);
double findMinExrtremumsExponential2(double a0, double b0, double c0, double d0, double a, double b);
double findMaxExrtremumsExponential2(double a0, double b0, double c0, double d0, double a, double b);
void Exponential2();
double func24(double a0, double b0, double c0, double x);
double findMinExrtremumsLogarithm2(double a0, double b0, double c0, double a, double b);
double findMaxExrtremumsLogarithm2(double a0, double b0, double c0, double a, double b);
void Logarithm2();
double func25(double a0, double b0, double c0, double d0, double x);
double findMinExrtremumsSineWave2(double a0, double b0, double c0, double d0, double a, double b);
double findMaxExrtremumsSineWave2(double a0, double b0, double c0, double d0, double a, double b);
void SineWave2();
double func26(double a0, double b0, double c0, double d0, double x);
double findMinExrtremumsCosineWave2(double a0, double b0, double c0, double d0, double a, double b);
double findMaxExrtremumsCosineWave2(double a0, double b0, double c0, double d0, double a, double b);
void CosineWave2();

/// Вычисление интеграла \\\

double polinom_cin(double x, double* coefficient, int n);
void polinom(double integration_range1, double integration_range2);
double degree_cin(double x, double a0, double b0, double c0);
void degree(double integration_range1, double integration_range2);
double exponential_cin(double x, double a0, double b0, double c0, double d0);
void exponential(double integration_range1, double integration_range2);
double logarithm_cin(double x, double a0, double b0, double c0);
void logarithm(double integration_range1, double integration_range2);
double sinus_cin(double x, double a0, double b0, double c0, double d0);
void sinus(double integration_range1, double integration_range2);
double cosinus_cin(double x, double a0, double b0, double c0, double d0);
void cosinus(double integration_range1, double integration_range2);
void function(double x, double integration_range1, double integration_range2);
