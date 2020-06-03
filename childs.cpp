#include "childs.h"
#include <iostream>

//----------------------------------------------Class Two--------------------------------------------------//
Two::Two(Lord* master, const std::string Anonimus,int condition):Lord(master),condition(condition) {
	this->set_name(Anonimus);
}
ClassID Two::get_ID()const { return ClassID::TWO; }
void Two::inform_condition()const {
	std::cout << "The object " << this->Name << " is ";
	condition>0?std::cout << "ready":std::cout << "not ready";
}

//----------------------------------------------Class Three-------------------------------------------------//

Three::Three(Lord* master, const std::string Anonimus, int condition) : Lord(master), condition(condition) {
	this->set_name(Anonimus);
}
ClassID Three::get_ID()const { return ClassID::THREE; }
void Three::inform_condition()const {
	std::cout << "The object " << this->Name << " is ";
	condition > 0 ? std::cout << "ready" : std::cout << "not ready";
}

//-----------------------------------------------Class Four--------------------------------------------------//

Four::Four(Lord* master, const std::string Anonimus, int condition) : Lord(master), condition(condition) {
	this->set_name(Anonimus);
}
ClassID Four::get_ID()const { return ClassID::FOUR; }
void Four::inform_condition()const {
	std::cout << "The object " << this->Name << " is ";
	condition > 0 ? std::cout << "ready" : std::cout << "not ready";
}

//-----------------------------------------------Class Five--------------------------------------------------//

Five::Five(Lord* master, const std::string Anonimus, int condition) : Lord(master), condition(condition) {
	this->set_name(Anonimus);
}
ClassID Five::get_ID()const { return ClassID::FIVE; }
void Five::inform_condition()const {
	std::cout << "The object " << this->Name << " is ";
	condition > 0 ? std::cout << "ready" : std::cout << "not ready";
}

//-----------------------------------------------Class Six---------------------------------------------------//

Six::Six(Lord* master, const std::string Anonimus, int condition) : Lord(master), condition(condition) {
	this->set_name(Anonimus);
}
ClassID Six::get_ID()const { return ClassID::SIX; }
void Six::inform_condition()const {
	std::cout << "The object " << this->Name << " is ";
	condition > 0 ? std::cout << "ready" : std::cout << "not ready";
}