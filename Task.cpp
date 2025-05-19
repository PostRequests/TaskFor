#include "Task.h"
void Task::run() {
	Menu m;
	Position e;
	e.setConsoleSize();
	//������� 13.1
	m.addItem("������� 13.1", 
		[&m] {
			m.clsBox();
			std::vector<int> num ;
			for (int i = 0; i < 10; i++)
				num.push_back(-20 + rand() % 50);
			m.printBox("������ : " + toStr(num) + "\n");
			//������ ��������� ������� � �������
			auto Mmin = [&num]() -> int {
				int min = num[0];
				for (int i = 1; i < num.size(); ++i) 
					if (num[i] < min) 
						min = num[i];
				return min;
				};
			int mini = Mmin();
			m.printBox("���������� �������� � �������: " + std::to_string(mini));
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������ ��������� � ������������������ ��� ������������� ��� ���������� ����������� �������� � �������, ������ � ������ ��������� �� ���������� ��� ��������.");
		}
	);
	//������� 13.2
	m.addItem("������� 13.2",
		[&m] {
			m.clsBox();
			std::vector<int> num;
			for (int i = 0; i < 10; i++)
				num.push_back(rand() % 10);
			m.printBox("������ : " + toStr(num) + "\n");
			int summ = 0;
			[&num, &summ]() {
				for (const int n : num)
					summ += n;
				}();
			m.printBox("����� �������� �������: " + std::to_string(summ));
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������ ��������� � ������������������ ��� ������������� ��� ���������� ����� ����� �������, ������ ��������� �������� ���������� ��������, � ������ �������� ��������� � ����������, ����������� � �������, ��� �������� ���������.");
		}
	);
	//������� 13.3
	m.addItem("������� 13.3",
		[&m] {
			m.clsBox();
			std::string s1, s2;
			m.printBox("������� ������ ������ : \n");
			std::getline(std::cin, s1);
			m.printBox("������� ������ ������ : \n");
			std::getline(std::cin, s2);
			[&s1, &s2, &m]() {
				if(s1 == s2)
					m.printBox("������ ����������");
				else
					m.printBox("������ ������");
				}();
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������ ��������� � ������������������ ��� ������������� ��� �������� �� ��������� ���� �����.");
		}
	);
	//������� 13.4
	m.addItem("������� 13.4",
		[&m] {
			m.clsBox();
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ����� �������� ���� �����. � ������ ����������� ����� ������ �������� ��������. � ������ ����� �������� �������� ����������� ����� ������ ���������. � ������ ��������� ������ ����� �� ���������� ��� ��������.");
		}
	);
	//������� 13.5
	m.addItem("������� 13.5",
		[&m] {
			m.clsBox();
		},
		[&m] {
			m.clsBox()
				.printBox("�������� ������ ��������� � ������������������ ��� ������������� ��� ���������� ������� ���������� ������� 1-10, ������ � ������ ��������� �� ���������� ��� ��������.");
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