#include "Task.h"
void Task::run() {
	Menu m;
	Position e;
	e.setConsoleSize();
	//Задание 13.1
	m.addItem("Задание 13.1", 
		[&m] {
			m.clsBox();
			std::vector<int> num ;
			for (int i = 0; i < 10; i++)
				num.push_back(-20 + rand() % 50);
			m.printBox("Вектор : " + toStr(num) + "\n");
			//Лямбда находящая минимум в массиве
			auto Mmin = [&num]() -> int {
				int min = num[0];
				for (int i = 1; i < num.size(); ++i) 
					if (num[i] < min) 
						min = num[i];
				return min;
				};
			int mini = Mmin();
			m.printBox("Наименьшее значение в массиве: " + std::to_string(mini));
		},
		[&m] {
			m.clsBox()
				.printBox("Написать лямбда выражение и продемонстрировать его использование для нахождения наименьшего значения в массиве, массив в лямбда выражение не передавать как параметр.");
		}
	);
	//Задание 13.2
	m.addItem("Задание 13.2",
		[&m] {
			m.clsBox();
			std::vector<int> num;
			for (int i = 0; i < 10; i++)
				num.push_back(rand() % 10);
			m.printBox("Вектор : " + toStr(num) + "\n");
			int summ = 0;
			[&num, &summ]() {
				for (const int n : num)
					summ += n;
				}();
			m.printBox("Сумма значений массива: " + std::to_string(summ));
		},
		[&m] {
			m.clsBox()
				.printBox("Написать лямбда выражение и продемонстрировать его использование для вычисления суммы чисел массива, лямбда выражение недолжно возвращать значение, а должно записать результат в переменную, объявленную в функции, где написано выражение.");
		}
	);
	//Задание 13.3
	m.addItem("Задание 13.3",
		[&m] {
			m.clsBox();
			std::string s1, s2;
			m.printBox("Введите первую строку : \n");
			std::getline(std::cin, s1);
			m.printBox("Введите вторую строку : \n");
			std::getline(std::cin, s2);
			[&s1, &s2, &m]() {
				if(s1 == s2)
					m.printBox("Строки одинаковые");
				else
					m.printBox("строки разные");
				}();
		},
		[&m] {
			m.clsBox()
				.printBox("Написать лямбда выражение и продемонстрировать его использование для проверки на равенство двух строк.");
		}
	);
	//Задание 13.4
	m.addItem("Задание 13.4",
		[&m] {
			m.clsBox();
		},
		[&m] {
			m.clsBox()
				.printBox("Написать класс хранения ряда чисел. В классе реализовать метод поиска среднего значения. В методе поиск среднего значения реализовать через лямбда выражение. В лямбда выражения вектор чисел не передавать как параметр.");
		}
	);
	//Задание 13.5
	m.addItem("Задание 13.5",
		[&m] {
			m.clsBox();
		},
		[&m] {
			m.clsBox()
				.printBox("Написать лямбда выражение и продемонстрировать его использование для заполнения массива случайными числами 1-10, массив в лямбда выражение не передавать как параметр.");
		}
	);
	
	m.addItem("Выход", [] {exit(0); }, [&m] {m.clsBox(); });
	m.setBox(m.getWidth() + 3, 1, e.getX(), e.getY());
	std::cout << m.run();
}
template <typename T>
std::string Task::toStr(std::vector<T>& v) {
	std::string r;
	r += "[";
	for (int i = 0; i < v.size(); i++)
		r += std::to_string(v[i]) + ((i < 9) ? ", " : "");
	r += "]";
	return r;
}