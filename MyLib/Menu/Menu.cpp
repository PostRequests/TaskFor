#include "Menu.h"
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
	for (int i = 0; i < count; i++)
	{
		setCursorPosition(posX + 1, posY + 3 + i * 2);
		centerWord(elMenu[i].data(), width - 1);
	}
	setCursorPosition(posX + 1, posY + 3 + cur);
	setColor(cb);
	centerWord(elMenu[cur].data(), width - 1);
	resetColor();
}
void Menu::show() {
	visible = true;
	drawEmptyRectangle2(posX, posY, posX + width, posY + count * 2 + 2);
	setCursorPosition(posX + 1, posY + 1);
	centerWord(head.data(), width - 1);
	setCursorPosition(posX, posX + 2);
	system("chcp 866>null");
	printRowChars(width + 1, Board_LV2, Board_H2, Board_RV2);
	system("chcp 1251>null");
	printElMenu();
}
void Menu::redrawItem(int color) {
	setCursorPosition(posX + 1, posY + 3 + cur * 2);
	setColor(color);
	centerWord(elMenu[cur].data(), width - 1);
	resetColor();
}
int Menu::run() {
	if (!count) return -1;
	show();
	while (true) {
		char key = catchKey();
		if (key == 'w' or key == 's') {
			//Закрашиваем текущий элемент в стандартный цвет
			redrawItem(0);
			//Определяем, как изменятся номер выделенного элемента
			if (key == 'w') (cur - 1 == -1) ? cur = count - 1 : cur -= 1;
			else if (key == 's') (cur + 1 == count) ? cur = 0 : cur += 1;
			//Перекрашиваем выделенный элемент
			redrawItem(cb);
		}
		else if (key == 13) {
			visible = false;
			hide();
			return cur;
		}
	}
	return cur;
}