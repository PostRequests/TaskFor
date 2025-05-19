#include "Menu.h"
char convertKey(char key) {
	tolower(key);
	switch (key) {
	case 'w': case 72: case -106: case -26:	return 'w';
	case 'a': case 75: case -108: case -28:	return 'a';
	case 's': case 80: case -101: case -21:	return 's';
	case 'd': case 77: case -126: case -94:	return 'd';
	case 'q': case -87: case -119: return'q';
	case 't': case -97: case -123: return 't';
	case 'r': case -86: case -118: return 'r';
	case 'f': case -64: case -32: return 'f';
	case 13: return 13; //Enter
	default: return 0;
	}
}

char catchKey() {
	while (true)
	{
		int input = _getch();
		if (input != 0 and input != 0xE0) {
			char key = input;
			return convertKey(key);
		}
	}
}
Menu& Menu::setBox(int x, int y, int x2, int y2) { 
	xBox.setCoordinate(x, y, x2, y2); 
	return *this;
}
Menu& Menu::setBox(Position& s, Position& e) { 
	xBox.setCoordinate(s.getX(), s.getY(), e.getX(), e.getY()); 
	return *this;
}
Menu& Menu::printBox(const std::string& text) {
	xBox.print(text);
	return *this;
}
Menu& Menu::clsBox() {
	xBox.cls();
	return *this;
}
Menu& Menu::addItem(const std::string& head, const std::function<void()>& f){
	if (!head.empty() && f && !visible) {
		elem.push_back(MenuItem (head, f));
		count++;
		calcWidth(head);
	}
	return*this;
}
Menu& Menu::addItem(const std::string& head, const std::function<void()>& fEnter, const std::function<void()>& fMove) {
	if (!head.empty() && !visible) {
		elem.push_back(MenuItem(head, fEnter, fMove));
		count++;
		calcWidth(head);
	}
	return*this;
}
Menu& Menu::setHead(std::string h) {
	if (!h.empty() && !visible) {
		head = h;
		calcWidth(h);
	}
	return*this;
}
void Menu::printElMenu() {
	for (int i = 0; i < count; i++) {
		start.setY(start.getX()  + i * 2)
			.printLn(elem[i].getHead());
	}
	cH.colorize();
	start.setY(start.getX() + cur)
		.print(elem[cur].getHead());
	cH.reset();
	start.restart();
}
void Menu::show() {
	visible = true;
	Box::drawBox(start.getX() - 1,
		start.getY() - 1,
		start.getX() + width,
		start.getY() + count * 2);
	//start.printLn(head.data());
	printElMenu();
	start.restart();
	xBox.drawBox();
	elem[cur].onMove();
}
void Menu::redrawItem(Color color) {
	color.colorize();
	start.setY(start.getMinY()  + cur * 2)
		.print(elem[cur].getHead());
	start.restart();
}
int Menu::run() {
	if (!count)
		throw std::exception("���� �� �������� �� ������ ��������");
	show();
	while (true) {
		char key = catchKey();
		if (key == 'w' or key == 's') {
			//����������� ������� ������� � ����������� ����
			redrawItem(cT);
			//����������, ��� ��������� ����� ����������� ��������
			if (key == 'w') (cur - 1 == -1) ? cur = count - 1 : cur -= 1;
			else if (key == 's') (cur + 1 == count) ? cur = 0 : cur += 1;
			elem[cur].onMove();
			//������������� ���������� �������
			redrawItem(cH);
		}
		else if (key == 13) {
			elem[cur].onEnter();
			//return cur;
		}
	}
	return cur;
}
Menu& Menu::setColorText(int BG, int FG) {
	cT.setColor(BG, FG);
	return *this;
}