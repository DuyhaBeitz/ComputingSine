#include <iostream>
#include <cmath>
#include <vector>

//sine funcs
#include "../Sine_functions/Headers/cordic_fixed_point.h"
#include "../Sine_functions/Headers/cordic.h"
#include "../Sine_functions/Headers/table_sine.h"
#include "../Sine_functions/Headers/taylor_series_sine.h"

#include "Headers/abs_error.h"

int main() {
	std::cout << std::fixed;
	std::cout.precision(20);

	double increment = 1.0, start = 0.0, end = 0.0;

	std::cout << "Введите start x:\n";
	std::cin >> start;

	std::cout << "Введите end x:\n";
	std::cin >> end;

	std::cout << "Введите шаг (меньше шаг = больше точность):\n";
	std::cin >> increment;

	std::cout << "\nДля ряда Тейлора\n";
	std::cout << "максимальная абсолютная погрешность: " << max_abs_sine_error(taylor_series_sine, increment, start, end);
	std::cout << "\nсредняя абсолютная погрешность: "	 << avg_abs_sine_error(taylor_series_sine, increment, start, end);

	
	std::cout << "\n\nДля табличных значений\n";
	std::cout << "максимальная абсолютная погрешность: " << max_abs_sine_error(table_sine, increment, start, end);
	std::cout << "\nсредняя абсолютная погрешность: "	 << avg_abs_sine_error(table_sine, increment, start, end);

	std::cout << "\n\nДля табличных значений с интерполяцией\n";
	std::cout << "максимальная абсолютная погрешность: " << max_abs_sine_error(table_sine_interp, increment, start, end);
	std::cout << "\nсредняя абсолютная погрешность: "	 << avg_abs_sine_error(table_sine_interp, increment, start, end);

	std::cout << "\n\nДля CORDIC (число с плавающей запятой)\n";
	std::cout << "максимальная абсолютная погрешность: " << max_abs_sine_error(cordic_sine, increment, start, end);
	std::cout << "\nсредняя абсолютная погрешность: "	 << avg_abs_sine_error(cordic_sine, increment, start, end);

	std::cout << "\n\nДля CORDIC (число с фиксированной запятой)\n";
	std::cout << "максимальная абсолютная погрешность: " << max_abs_sine_error(cordic_sine_FPN, increment, start, end);
	std::cout << "\nсредняя абсолютная погрешность: "	 << avg_abs_sine_error(cordic_sine_FPN, increment, start, end);

}