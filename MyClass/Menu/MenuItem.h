#pragma once
#include <string>
#include <functional>
#include "../Box/Box.h"
class MenuItem {
protected:
    std::string name;
    std::string other;
    std::function<void()> enter;
    std::function<void()> move;
    Box& x;

public:
    void setName(const std::string& n) { name = n; }
    void setOther(const std::string& o) { other = o; }

    virtual void onEnter() = 0;
    virtual void onMove() = 0; 
};

