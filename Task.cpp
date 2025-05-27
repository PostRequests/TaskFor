#include "Task.h"

void Task::run() {
	Menu m;
	Position e;
	m.setColorText(RedBG, GreenFG)
		.setColorBox(GreenBG, RedFG);
	e.setConsoleSize();
	
	//Задание 15.1
	m.addItem("Задание 15.1", 
		[&m] {
			m.clsBox()
				.printBox("Введите полный путь к файлу \n:\n");
			std::string path;//Путь к файлу
			std::getline(std::cin, path);
			m.printBox("Укажите смещение по шифрованию \n:\n");
			std::string shift;
			std::getline(std::cin, shift);
			RusEncryption enc(std::stoi(shift)); //Генерируем шифратор
			std::string newPath;//новый путь к фалу
			size_t p = path.find_last_of(".");
			if (p != std::string::npos)
				newPath = path.substr(0,p) + "_encode.txt";//Обрезаем все последнюю точку
			std::string data = File::loadFile(path);
			std::string eData = enc.encryption(data);
			File::saveFile(newPath, eData);
			m.printBox("Файл успешно сохранен по адресу \n:" + newPath);
			
			

			
		},
		[&m] {
			m.clsBox()
				.printBox("Задание 1: написать программу, которая указанный пользователем файл шифрует алгоритмом Цезаря и сохраняет с новым именем: «старое имя_encode.txt».\nРешить задачу необходимо используя инструменты библиотеки <algorithm>, ямбда выражения, контейнеры(коллекции) из библиотеки std.");
		}
	);
	//Задание 15.2
	m.addItem("Задание 15.2",
		[&m] {
			m.clsBox()
				.printBox("Введите полный путь к файлу \n:\n");
			std::string path;//Путь к файлу
			std::getline(std::cin, path);
			m.printBox("Укажите сдвиг по шифрованию \n:\n");
			std::string shift;
			std::getline(std::cin, shift);
			RusEncryption enc(std::stoi(shift)); //Генерируем шифратор
			std::string newPath;//новый путь к фалу
			size_t p = path.find_last_of("_");
			if (p != std::string::npos)
				newPath = path.substr(0, p) + "_decode.txt";//Обрезаем все последнюю точку
			std::string data = File::loadFile(path);
			std::string eData = enc.decryption(data);
			File::saveFile(newPath, eData);
			m.printBox("Файл успешно сохранен по адресу \n:" + newPath);
		},
		[&m] {
			m.clsBox()
				.printBox("Задание 2: написать программу, которая указанный пользователем файл дешифрует алгоритмом Цезаря и сохраняет с новым именем: «старое имя_decode.txt».\nРешить задачу необходимо используя инструменты библиотеки <algorithm>, ямбда выражения, контейнеры(коллекции) из библиотеки std.");
		}
	);
	//Задание 15.3
	m.addItem("Задание 15.3",
		[&m] {
			m.clsBox()
				.printBox("Введите N:\n");
			std::string N;//Размерность N
			std::getline(std::cin, N);// Считываем размерность
			const std::string path = "1.txt"; //Путь к файлу
			std::string text;
			std::vector<int> num = randVec(1, 4048, std::stoi(N)); //Создаем вектор случайных чисел
			std::for_each(num.begin(), num.end(), //Сохраняем вектор в строку
				[&text](int n){
					text += std::to_string(n);
			}
			);
			File::saveFile(path, text);//Сохраняем строку в файл
			std::map<char, int> chStat = File::loadFileToMap(path); //загружаем файл в map
			m.printBox("Количество символов в файле:\n");
			std::for_each(chStat.begin(), chStat.end(), //Выводим map на экран
				[&m](auto p) {
					m.printBox(std::string(1, p.first) + " = "
						+ std::to_string(p.second) + "\n");
				});
		},
		[&m] {
			m.clsBox()
				.printBox("Задание 3: написать программу, которая запрашивает у пользователя число N. Сохраняет в текстовый файл «1.txt» N случайных чисел в диапазоне [1;4048]. Считывает данные из файла «1.txt» посимвольно и выводит статистику какой символ сколько раз встретился в файле.\nРешить задачу необходимо используя инструменты библиотеки <algorithm>, ямбда выражения, контейнеры(коллекции) из библиотеки std.");
		}
	);
	
	
	m.addItem("Выход", [] {exit(0); }, [&m] {m.clsBox().printBox("Выход"); });
	m.setBox(m.getWidth() + 3, 1, e.getX(), e.getY());
	std::cout << m.run();
}

template <typename T>
std::string Task::toStr(const std::vector<T>& v) {
	std::string r;
	r += "[";
	for (int i = 0; i < v.size(); i++)
		r += std::to_string(v[i]) + ((i < v.size() - 1) ? ", " : "");
	r += "]";
	return r;
}

template <typename T>
std::string Task::toStr(const std::set<T>& v) {
	std::string r = "[";
	for (auto i = v.begin(); i != v.end() ; i++)
		r += std::to_string(*i) + " " +((std::next(i) != v.end()) ? ", " : "");
	r += "]";
	return r;
}



std::vector<int> Task::randVec( int min, int max, int size) {
	std::vector<int> v;
	for (size_t i = 0; i < size; i++)//Заполняем первый массив
		v.push_back(rand() % (max - min + 1) + min);
	v.capacity(); //Очищаем лишнюю память из вектора
	return v;
}