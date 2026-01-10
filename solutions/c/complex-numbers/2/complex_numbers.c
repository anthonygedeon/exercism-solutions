#include "complex_numbers.h"
#include <complex.h>
#include <math.h>

complex_t c_add(complex_t a, complex_t b) {
    complex_t result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex_t c_sub(complex_t a, complex_t b) {
    complex_t result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

complex_t c_mul(complex_t a, complex_t b) {
    complex_t result;
    result.real = a.real * b.real - (a.imag * b.imag);
    result.imag = a.real * b.imag + b.real * a.imag;

    return result;
}

complex_t c_div(complex_t a, complex_t b) {
    complex_t result;
    complex_t num = c_mul(a, c_conjugate(b));
    complex_t den = c_mul(b, c_conjugate(b));
    result.real = num.real / den.real;
    result.imag = num.imag / den.real;
    return result;
}

double c_abs(complex_t x) { return sqrt(x.real * x.real + x.imag * x.imag); }

complex_t c_conjugate(complex_t x) {
    complex_t result;
    result.real = x.real;
    result.imag = (-1) * x.imag;
    return result;
}

double c_real(complex_t x) { return x.real; }

double c_imag(complex_t x) { return x.imag; }

complex_t c_exp(complex_t x) {
    complex_t result;
    result.real = exp(x.real) * cos(x.imag);
    result.imag = exp(x.real) * sin(x.imag);
    return result;
}
