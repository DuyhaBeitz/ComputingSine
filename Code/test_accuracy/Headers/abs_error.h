#pragma once

double avg_abs_sine_error(double(*func)(double), double increment, double start, double end);
double avg_abs_sine_error(unsigned n, double(*func)(double, unsigned), double increment, double start, double end);

double max_abs_sine_error(double(*func)(double), double increment, double start, double end);
double max_abs_sine_error(unsigned n, double(*func)(double, unsigned), double increment, double start, double end);