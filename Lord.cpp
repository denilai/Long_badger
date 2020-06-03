#include "Lord.h"
#include <iostream>
#include <list>
#include <iomanip>
using namespace Lord_;
Lord::Lord(Lord* master, const std::string Name) : master(master) {
	this->Name = new char[Name.length()+1];
	for (int i = 0; i < Name.length(); i++) {
		this->Name[i] = Name[i];
	}
	this->Name[Name.length()] = '\0';
}
Lord::Lord(Lord* master) :master(master){}
const char* Lord::get_name() {
	return Name;
}
void Lord::set_name(const std::string Name) {
	this->Name = new char[Name.length()+1];
	for (int i = 0; i < Name.length(); i++) {
		this->Name[i] = Name[i];
	}
	this->Name[Name.length()] = '\0';
}
void Lord::add_slave(Lord*slave) {
	slaves.push_back(slave);
}
Lord* Lord::get_master()
{
	return master;
}
std::list<Lord*> Lord::get_list() {
	return slaves;
}
void Lord::show_list(std::list<Lord*> members) {
	for (std::list<Lord*>::iterator p = members.begin(); p != members.end();p++) {
		std::cout << std::setw(15) << *p;
	}
	std::cout << std::endl;
}
Lord::~Lord() {
	delete[]Name;
}