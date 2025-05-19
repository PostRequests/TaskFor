#pragma once
#include "MenuItem.h"
class ItemM : public MenuItem
{
private:
protected:
	//Наследование от MenuItem
	/*std::string name;
	* std::string other;
	* std::function<void()> enter;
	* std::function<void()> move;
	* Box& x;*/
public:
	//Наследование от MenuItem
	/*virtual void onEnter() = 0;
	virtual void onMove() = 0;*/
	ItemM(const std::string& n, const std::string& o, Box& x,
		const std::function<void()>& e, const std::function<void()>& m)
		: name(n), other(o), x(x), enter(e), move(m) {}

	void inline onEnter() { enter(); }
	void inline onMove() { move(); }
};

