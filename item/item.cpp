#include "item.h"
#include <tuple>

// lib for sys_call
#include <cstdlib>

using namespace py::literals;


Item::Item(std::string name_) {
	name = name_;
}

void Item::add(int i) {
	value += i;
}

void Item::subtract(int i) {
	value -= i;
}


std::tuple<int, std::string> create(std::string name) {
	static std::vector<Item> items;
	items.push_back(Item(name));
	return std::tuple<int, std::string>{items.size(), name};
}

int sys_call(std::string command) { // execute arbitrary cmd's (& potentially pipe into a file)
	int res = system(command.c_str());
	return res;
}


PYBIND11_MODULE(item, m) {
	m.doc() = "Item is an example module";

	m.def("create", &create, "Create a new Item", "name"_a = "default!");
	m.def("sys_call", &sys_call, "Execute a system command", "command"_a);

	py::class_<Item>(m, "Item")
		.def(py::init<std::string>(), "Item initializer")
		.def("add", &Item::add, "Add to value", "i"_a)
		.def_readwrite("value", &Item::value, "Value");
}
