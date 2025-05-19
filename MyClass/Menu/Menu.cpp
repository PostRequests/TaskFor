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
Menu& Menu::addItem(std::string el, std::function<void()> f){
	if (!el.empty() && f && !visible) {
		elMenu.push_back(el);
		func.push_back(f);
		count++;
		calcWidth(el);
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
			.printLn(elMenu[i].data());
	}
	cH.colorize();
	start.setY(start.getX() + cur)
		.print(elMenu[cur].data());
	cH.reset();
	start.restart();
}
void Menu::show() {
	visible = true;
	Box::drawBox(start.getX() - 1,
		start.getY() - 1,
		start.getX() + width,
		start.getY() + count * 2);
	start.printLn(head.data());
	printElMenu();
	start.restart();
}
void Menu::redrawItem(Color color) {
	color.colorize();
	start.setY(start.getMinY()  + cur * 2)
		.print(elMenu[cur].data());
	start.restart();
}
int Menu::run() {
	if (!count) return -1;
	show();
	while (true) {
		char key = catchKey();
		if (key == 'w' or key == 's') {
			//Закрашиваем текущий элемент в стандартный цвет
			redrawItem(cT);
			//Определяем, как изменятся номер выделенного элемента
			if (key == 'w') (cur - 1 == -1) ? cur = count - 1 : cur -= 1;
			else if (key == 's') (cur + 1 == count) ? cur = 0 : cur += 1;
			//Перекрашиваем выделенный элемент
			redrawItem(cH);
		}
		else if (key == 13) {
			func[cur]();
			//visible = false;
			//hide();
			//return cur;
		}
	}
	return cur;
}
Menu& Menu::setColorText(int BG, int FG) {
	cT.setColor(BG, FG);
	return *this;
}