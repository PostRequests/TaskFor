#include "Task.h"
#include "IntVector.h"
void Task::run() {
	Menu m;
	Position e;
	e.setConsoleSize();
	//Задание 11.1
	m.addItem("Задание 12.1", 
		[&m] {
			std::string a, b;
			m.clsBox()
				.printBox("Введите делимое число : ");
			std::getline(std::cin, a);
			m.printBox("\nВведите делитель : ");
			std::getline(std::cin, b);
			try {
				int result = std::stoi(a) % std::stoi(b);
				m.printBox("\nОстаток от деления: " + std::to_string(result));
			}
			catch (...) {
				m.printBox("\nОшибка: попытка деления на ноль!");
			}
		},
		[&m] {
			m.clsBox()
				.printBox("Настроить проект на обработку исключений с SEH исключениями (/EHa). Написать программу, которая запрашивает у пользователя два числа и выполняет операцию нахождения остатка от деления. С помощью конструкции try-catch отловить ошибку при выполнении данной операции для нахождения остатка от деления на 0.");
		}
	);
	//Задание 11.2
	m.addItem("Задание 12.2",
		[&m] {
			IntVector v;
			for (int i = 0; i < 10; i++)
				v.addNumber(rand() % 20);
			v.addNumber(30);
			m.clsBox().printBox("Числа в векторе :" + v.toStrig() + "\n");
			try {
				int findNum = 30;
				int i = v.findNumber(findNum);
				m.printBox("Число " + std::to_string(findNum) + " найдено на позиции " + std::to_string(i) + "\n");
				findNum = 12;
				i = v.findNumber(findNum);
				m.printBox("Число " + std::to_string(findNum) + " найдено на позиции " + std::to_string(i) + "\n");
			}
			catch(MyError& er){
				m.printBox("Ошибка!!! :" + er.what());
			}
		},
		[&m] {
			m.clsBox()
				.printBox("Написать класс для обработки исключительных ситуаций наследуясь от базового класса std::exception. Написать класс для хранения ряда целых числе. Реализовать в классе метод поиска числа в ряду. Если поиск завершается неудачей должно генерироваться исключение. В функции main продемонстрируйте работу класса и обработайте ситуацию поиска числа, которого нет в ряде чисел.");
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