#include "Task.h"
#include "MinElement.h"
#include "Factorial.h"
#include "Equal.h"
#include "To866.h"
#include "To1251.h"
void Task::run() {
	Menu m;
	Position e;
	e.setConsoleSize();
	//Задание 11.1
	m.addItem("Задание 11.1", 
		[&m] {
			std::vector<int> a;
			for (int i = 0; i < 10; i++)
				a.push_back(rand()% 100);
			m.clsBox();
			m.printBox("Сгенерирован случайный массив : \n" + toStr(a) + "\n");
			MinElement Imin; //Функтор нахождения минимального элемента
			m.printBox("Минимальный элемент массива : " + std::to_string(Imin(a)) + "\n");
		},
		[&m] {
			m.clsBox()
				.printBox("Написать функтор и продемонстрировать его использование для нахождения наименьшего значения в массиве.");
		}
	);
	//Задание 11.2
	m.addItem("Задание 11.2",
		[&m] {
			int n = rand() % 10;
			Factorial b;//Функтор нахождения факториала числа
			m.clsBox().
				printBox("Факториал числа " + std::to_string(n) + " = " + std::to_string(b(n)));
		},
		[&m] {
			m.clsBox()
				.printBox("Написать функтор и продемонстрировать его использование для вычисления факториала числа.");
		}
	);
	//Задание 11.3
	m.addItem("Задание 11.3",
		[&m] {
			std::string s1, s2;
			Equal e; //Функтор производящий ставнение
			m.clsBox()
				.printBox("Введите две строки для сравнения \n");
			m.printBox("Первая строка : \n");
			std::getline(std::cin, s1);
			m.printBox("\nВторая строка : \n");
			std::getline(std::cin, s2);
			if (e(s1,s2)){
				m.printBox("\nОбе строки одинаковые \n");
			}
			else {
				m.printBox("\nСтроки разные \n");
			}
		},
		[&m] {
			m.clsBox()
				.printBox("Написать предикат и продемонстрировать его использование для проверки на равенство двух строк..");
		}
	);
	//Задание 11.4
	m.addItem("Задание 11.4",
		[&m] {
			m.clsBox();
			system("chcp 1251>nul");
			m.printBox("Текущая кодировка 1251.\nВведите текст\n");
			std::string s;
			To866 l;
			std::getline(std::cin, s);
			system("chcp 866>nul");
			m.printBox(l("Кодировка изменена на 866\n"));
			m.printBox(l("Текст в 1251 кодировке : ") + s + "\n");
			m.printBox(l("Текст в 866 кодировке : ") + l(s));
			system("chcp 1251>nul");
		},
		[&m] {
			m.clsBox()
				.printBox("Написать функтор и продемонстрировать его использование для смены кодировки сроки символов из 1251 в 866.");
		}
	);
	//Задание 11.5
	m.addItem("Задание 11.5",
		[&m] {
			m.clsBox();
			m.printBox("Текущая кодировка 866.\nВведите текст\n");
			system("chcp 866>nul");
			std::string s;
			To1251 l;
			std::getline(std::cin, s);
			system("chcp 1251>nul");
			m.printBox("Кодировка изменена на 1251\n");
			m.printBox("Текст в 866 кодировке : " + s + "\n");
			m.printBox("Текст в 1251 кодировке : " + l(s));
		},
		[&m] {
			m.clsBox()
				.printBox("Написать функтор и продемонстрировать его использование для смены кодировки сроки символов из 866 в 1251.");
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