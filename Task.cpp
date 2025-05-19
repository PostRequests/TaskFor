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
	//������� 11.1
	m.addItem("������� 11.1", 
		[&m] {
			std::vector<int> a;
			for (int i = 0; i < 10; i++)
				a.push_back(rand()% 100);
			m.clsBox();
			m.printBox("������������ ��������� ������ : \n" + toStr(a) + "\n");
			MinElement Imin; //������� ���������� ������������ ��������
			m.printBox("����������� ������� ������� : " + std::to_string(Imin(a)) + "\n");
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������� � ������������������ ��� ������������� ��� ���������� ����������� �������� � �������.");
		}
	);
	//������� 11.2
	m.addItem("������� 11.2",
		[&m] {
			int n = rand() % 10;
			Factorial b;//������� ���������� ���������� �����
			m.clsBox().
				printBox("��������� ����� " + std::to_string(n) + " = " + std::to_string(b(n)));
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������� � ������������������ ��� ������������� ��� ���������� ���������� �����.");
		}
	);
	//������� 11.3
	m.addItem("������� 11.3",
		[&m] {
			std::string s1, s2;
			Equal e; //������� ������������ ���������
			m.clsBox()
				.printBox("������� ��� ������ ��� ��������� \n");
			m.printBox("������ ������ : \n");
			std::getline(std::cin, s1);
			m.printBox("\n������ ������ : \n");
			std::getline(std::cin, s2);
			if (e(s1,s2)){
				m.printBox("\n��� ������ ���������� \n");
			}
			else {
				m.printBox("\n������ ������ \n");
			}
		},
		[&m] {
			m.clsBox()
				.printBox("�������� �������� � ������������������ ��� ������������� ��� �������� �� ��������� ���� �����..");
		}
	);
	//������� 11.4
	m.addItem("������� 11.4",
		[&m] {
			m.clsBox();
			system("chcp 1251>nul");
			m.printBox("������� ��������� 1251.\n������� �����\n");
			std::string s;
			To866 l;
			std::getline(std::cin, s);
			system("chcp 866>nul");
			m.printBox(l("��������� �������� �� 866\n"));
			m.printBox(l("����� � 1251 ��������� : ") + s + "\n");
			m.printBox(l("����� � 866 ��������� : ") + l(s));
			system("chcp 1251>nul");
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������� � ������������������ ��� ������������� ��� ����� ��������� ����� �������� �� 1251 � 866.");
		}
	);
	//������� 11.5
	m.addItem("������� 11.5",
		[&m] {
			m.clsBox();
			m.printBox("������� ��������� 866.\n������� �����\n");
			system("chcp 866>nul");
			std::string s;
			To1251 l;
			std::getline(std::cin, s);
			system("chcp 1251>nul");
			m.printBox("��������� �������� �� 1251\n");
			m.printBox("����� � 866 ��������� : " + s + "\n");
			m.printBox("����� � 1251 ��������� : " + l(s));
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������� � ������������������ ��� ������������� ��� ����� ��������� ����� �������� �� 866 � 1251.");
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