#include "Headers/abs_error.h"
#include <cmath>
#include <vector>
#include <iostream>

double avg_abs_sine_error(double(*func)(double), double increment, double start, double end)
{
	double avg_abs_err = 0.0;
	std::vector<double> abs_errors = {};

	//Вычислить и сохранить погрешности
	if (start < end) {
		for (double i = start; i <= end; i += increment) {
			double abs_error = std::abs(func(i) - std::sin(i));
			abs_errors.push_back(abs_error);
		}
        //Вычислить среднюю погрешность
        double sum = 0.0;
        for (double i : abs_errors) {
            sum += i;
        }
        avg_abs_err = sum / abs_errors.size();

        return avg_abs_err;
	}
	else {
		std::cout << "Start должен быть меньше end!";
        return -1.0;
	}
}

double avg_abs_sine_error(unsigned n, double(*func)(double, unsigned), double increment, double start, double end)
{
	double avg_abs_err = 0.0;
	std::vector<double> abs_errors = {};

	//Вычислить и сохранить погрешности
	if (start < end) {
		for (double i = start; i <= end; i += increment) {
			double abs_error = std::abs(func(i, n) - std::sin(i));
			abs_errors.push_back(abs_error);
		}
        //Вычислить среднюю погрешность
        double sum = 0.0;
        for (double i : abs_errors) {
            sum += i;
        }
        avg_abs_err = sum / abs_errors.size();

        return avg_abs_err;
	}
	else {
		std::cout << "Start должен быть меньше end!";
        return -1.0;
	}
}

double max_abs_sine_error(double(*func)(double), double increment, double start, double end)
{
	double max_abs_err = 0.0;

	if (start < end) {
		for (double i = start; i <= end; i += increment) {
			double abs_error = std::abs(func(i) - std::sin(i));
			max_abs_err = std::max(abs_error, max_abs_err);
		}
        return max_abs_err;
	}
	else {
		std::cout << "Start должен быть меньше end!";
        return -1.0;
	}
}

double max_abs_sine_error(unsigned n, double(*func)(double, unsigned), double increment, double start, double end)
{
	double max_abs_err = 0.0;

	if (start < end) {
		for (double i = start; i <= end; i += increment) {
			double abs_error = std::abs(func(i, n) - std::sin(i));
			max_abs_err = std::max(abs_error, max_abs_err);
		}
        return max_abs_err;
	}
	else {
		std::cout << "Start должен быть меньше end!";
        return -1.0;
	}
}