#include "Task.h"

void Task::run() {
	Menu m;
	Position e;
	m.setColorText(RedBG, GreenFG)
		.setColorBox(GreenBG, RedFG);
	e.setConsoleSize();
	
	//������� 15.1
	m.addItem("������� 15.1", 
		[&m] {
			m.clsBox()
				.printBox("������� ������ ���� � ����� \n:\n");
			std::string path;//���� � �����
			std::getline(std::cin, path);
			m.printBox("������� �������� �� ���������� \n:\n");
			std::string shift;
			std::getline(std::cin, shift);
			RusEncryption enc(std::stoi(shift)); //���������� ��������
			std::string newPath;//����� ���� � ����
			size_t p = path.find_last_of(".");
			if (p != std::string::npos)
				newPath = path.substr(0,p) + "_encode.txt";//�������� ��� ��������� �����
			std::string data = File::loadFile(path);
			std::string eData = enc.encryption(data);
			File::saveFile(newPath, eData);
			m.printBox("���� ������� �������� �� ������ \n:" + newPath);
			
			

			
		},
		[&m] {
			m.clsBox()
				.printBox("������� 1: �������� ���������, ������� ��������� ������������� ���� ������� ���������� ������ � ��������� � ����� ������: ������� ���_encode.txt�.\n������ ������ ���������� ��������� ����������� ���������� <algorithm>, ����� ���������, ����������(���������) �� ���������� std.");
		}
	);
	//������� 15.2
	m.addItem("������� 15.2",
		[&m] {
			m.clsBox()
				.printBox("������� ������ ���� � ����� \n:\n");
			std::string path;//���� � �����
			std::getline(std::cin, path);
			m.printBox("������� ����� �� ���������� \n:\n");
			std::string shift;
			std::getline(std::cin, shift);
			RusEncryption enc(std::stoi(shift)); //���������� ��������
			std::string newPath;//����� ���� � ����
			size_t p = path.find_last_of("_");
			if (p != std::string::npos)
				newPath = path.substr(0, p) + "_decode.txt";//�������� ��� ��������� �����
			std::string data = File::loadFile(path);
			std::string eData = enc.decryption(data);
			File::saveFile(newPath, eData);
			m.printBox("���� ������� �������� �� ������ \n:" + newPath);
		},
		[&m] {
			m.clsBox()
				.printBox("������� 2: �������� ���������, ������� ��������� ������������� ���� ��������� ���������� ������ � ��������� � ����� ������: ������� ���_decode.txt�.\n������ ������ ���������� ��������� ����������� ���������� <algorithm>, ����� ���������, ����������(���������) �� ���������� std.");
		}
	);
	//������� 15.3
	m.addItem("������� 15.3",
		[&m] {
			m.clsBox()
				.printBox("������� N:\n");
			std::string N;//����������� N
			std::getline(std::cin, N);// ��������� �����������
			const std::string path = "1.txt"; //���� � �����
			std::string text;
			std::vector<int> num = randVec(1, 4048, std::stoi(N)); //������� ������ ��������� �����
			std::for_each(num.begin(), num.end(), //��������� ������ � ������
				[&text](int n){
					text += std::to_string(n);
			}
			);
			File::saveFile(path, text);//��������� ������ � ����
			std::map<char, int> chStat = File::loadFileToMap(path); //��������� ���� � map
			m.printBox("���������� �������� � �����:\n");
			std::for_each(chStat.begin(), chStat.end(), //������� map �� �����
				[&m](auto p) {
					m.printBox(std::string(1, p.first) + " = "
						+ std::to_string(p.second) + "\n");
				});
		},
		[&m] {
			m.clsBox()
				.printBox("������� 3: �������� ���������, ������� ����������� � ������������ ����� N. ��������� � ��������� ���� �1.txt� N ��������� ����� � ��������� [1;4048]. ��������� ������ �� ����� �1.txt� ����������� � ������� ���������� ����� ������ ������� ��� ���������� � �����.\n������ ������ ���������� ��������� ����������� ���������� <algorithm>, ����� ���������, ����������(���������) �� ���������� std.");
		}
	);
	
	
	m.addItem("�����", [] {exit(0); }, [&m] {m.clsBox().printBox("�����"); });
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
	for (size_t i = 0; i < size; i++)//��������� ������ ������
		v.push_back(rand() % (max - min + 1) + min);
	v.capacity(); //������� ������ ������ �� �������
	return v;
}