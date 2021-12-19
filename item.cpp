#include "item.h"


Item::Item(std::string name_) {
	name = name_;
}

void Item::add(int i) {
	value += i;
}


int create(std::string name) {
	static std::vector<Item> items;
	items.push_back(Item(name));
	return items.size();
}


PYBIND11_MODULE(item, m) {
	m.doc() = "Item is an example module.";
	m.def("create", &create, "Create a new Item");
}
