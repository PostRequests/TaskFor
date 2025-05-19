#include "Color.h"
Color& Color::setFG(int FG){
	if (this->FG == FG) return *this;
	if (FG < BlackFG || FG > WhiteFG) return *this;
	this->FG = FG;
	return *this;
}
Color& Color::setBG(int BG) {
	if (this->BG == BG) return *this;
	if (BG < BlackBG || BG > WhiteBG) return *this;
	this->BG = BG;
	return *this;
}
Color& Color::setColor(int BG, int FG) {
	setBG(BG);
	return setFG(FG);
}
Color& Color::setColor(const Color& c) {
	if (this->BG == c.BG && this->FG == c.FG) return *this;
	this->BG = c.BG;
	this->FG = c.FG;
	return* this;
}
Color& Color::colorize() {
	std::cout << "\x1b[" << BG << ';' << FG << 'm';
	return *this;
}
Color& Color::reset() {
	std::cout << "\x1b[" << 0 << 'm';
	return *this;
}