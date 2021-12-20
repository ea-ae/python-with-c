#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;


class Item {
public:
	int value = 0;
private:
	std::string name;
public:
	Item(std::string name_);
	void add(int i);
	void subtract(int i);
};
