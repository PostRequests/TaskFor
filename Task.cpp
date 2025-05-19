#include "Task.h"
#include "IntVector.h"
void Task::run() {
	Menu m;
	Position e;
	e.setConsoleSize();
	//������� 11.1
	m.addItem("������� 12.1", 
		[&m] {
			std::string a, b;
			m.clsBox()
				.printBox("������� ������� ����� : ");
			std::getline(std::cin, a);
			m.printBox("\n������� �������� : ");
			std::getline(std::cin, b);
			try {
				int result = std::stoi(a) % std::stoi(b);
				m.printBox("\n������� �� �������: " + std::to_string(result));
			}
			catch (...) {
				m.printBox("\n������: ������� ������� �� ����!");
			}
		},
		[&m] {
			m.clsBox()
				.printBox("��������� ������ �� ��������� ���������� � SEH ������������ (/EHa). �������� ���������, ������� ����������� � ������������ ��� ����� � ��������� �������� ���������� ������� �� �������. � ������� ����������� try-catch �������� ������ ��� ���������� ������ �������� ��� ���������� ������� �� ������� �� 0.");
		}
	);
	//������� 11.2
	m.addItem("������� 12.2",
		[&m] {
			IntVector v;
			for (int i = 0; i < 10; i++)
				v.addNumber(rand() % 20);
			v.addNumber(30);
			m.clsBox().printBox("����� � ������� :" + v.toStrig() + "\n");
			try {
				int findNum = 30;
				int i = v.findNumber(findNum);
				m.printBox("����� " + std::to_string(findNum) + " ������� �� ������� " + std::to_string(i) + "\n");
				findNum = 12;
				i = v.findNumber(findNum);
				m.printBox("����� " + std::to_string(findNum) + " ������� �� ������� " + std::to_string(i) + "\n");
			}
			catch(MyError& er){
				m.printBox("������!!! :" + er.what());
			}
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ����� ��� ��������� �������������� �������� ���������� �� �������� ������ std::exception. �������� ����� ��� �������� ���� ����� �����. ����������� � ������ ����� ������ ����� � ����. ���� ����� ����������� �������� ������ �������������� ����������. � ������� main ����������������� ������ ������ � ����������� �������� ������ �����, �������� ��� � ���� �����.");
		}
	);
	
	m.addItem("�����", [] {exit(0); }, [&m] {m.clsBox(); });
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