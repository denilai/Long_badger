#include "childs.h"
#include <iostream>
#include <algorithm>

Lord::Lord(Lord* master, const std::string Name) : Name(Name), master(master), current_unit({-1,-1}) {}

void Lord::set_name(const std::string Name) { this->Name = Name; }

const std::string Lord::get_name() const{ return Name; }

Lord* Lord::get_master()const{return master;}	

std::vector<IBase*> Lord::get_list()const {return slaves;}

ClassID Lord::get_ID()const {return ClassID:: ROOT;}

void Lord::add_slave(IBase*slave) {slaves.push_back(slave);}

void Lord::inform_condition()const {
	std::cout << "The object " << this->Name << " is ready";
}



Lord::~Lord() {}
// вирутальный деструктор обеспечивает уничтожение всех наследников
// класса Lord (класс 2,3,4,5,6 или 7) вместе с Lord


//-------------------------------методы, добавленные для выполнения задания курсовой работы------------------//

Lord::Lord(int dim) :current_unit({ -1,-1 }),master(nullptr) {
	field.resize(dim);
}

Lord::Lord(const Lord* old) : current_unit(old->current_unit), master(nullptr),field(old->field) {}


void Lord::find_first_unit() {
	int first, last;
	std::vector<char> null_col;
	for (auto& line : field)
		null_col.push_back(line[0]);
	if (find(null_col.begin(), null_col.end(), '1') == null_col.end())
		return;
	for (auto& elem : null_col)
		if (elem == '1') {
			first = &elem - &null_col.front();
			break;
		}
	reverse(null_col.begin(), null_col.end());
	for (auto& elem : null_col)
		if (elem == '1') {
			last = &null_col.back() - &elem;
			break;
		}
	if (last == first) {
		current_unit = { last,0 };
		return;
	}
	neighbors f = take_neighbors({ first, 0 });
	neighbors l = take_neighbors({ last, 0 });
	if (!f.right)
		current_unit = { first,0 };
	if (!l.right)
		current_unit = { last,0 };
}

position Lord::get_curr_unit()
{
	this->find_first_unit();
	return current_unit;
}

void Lord::create_field(std::istream& stream) {
	std::string line;
	for (int i = 0; i < field.size(); i++) {
		stream >> line;
		field[i] = line;
	}
}

void Lord::show_matrix() const {
	for (auto& vec : field) {
		if (&vec != &field.front())
			std::cout << std::endl;
		for (auto el : vec)
			std::cout << el;
	}
}



neighbors Lord::loop_survey()
{
	try {
		return take_neighbors(current_unit);
	}
	catch (int) {
		return { false,false,false,false };
	}
}

bool Lord::step(std::string message) {
	if (current_unit.col < 0 || current_unit.row < 0) {
		return false;
	}
	if (message[message.length() - 1] == '2')
		return 0;
	try {
		this% current_unit = 'F';
	}
	catch (...) {};
	switch (message[0])
	{
	case't':
		current_unit.row--;
		break;
	case'r':
		current_unit.col++;
		break;
	case'b':
		current_unit.row++;
		break;
	case'l':
		current_unit.col--;
		break;
	default:
		return 0;
	}
	return 1;
}



neighbors Lord::take_neighbors(position elem)const {
	neighbors symb;
	Lord temp = (this);
	size_t const dim = field.size();
	position left = { elem.row,elem.col - 1 },
		right = { elem.row,elem.col + 1 },
		top = { elem.row - 1 ,elem.col },
		bot = { elem.row + 1,elem.col };
	if (elem.row < 0 || elem.col < 0)
		throw 1;
	if (elem.row >= dim || elem.col >= dim)
		throw 2;
	try { symb.top = temp[top] == '1' ? true : false; }
	catch (char) {}
	try { symb.bot = temp[bot] == '1' ? true : false; }
	catch (char) {}
	try { symb.left = temp[left] == '1' ? true : false; }
	catch (char) {}
	try { symb.right = temp[right] == '1' ? true : false; }
	catch (char) {}
	return symb;
}

char& Lord::operator[](position pos) {
	if (pos.col < 0 || pos.row < 0)
		throw 'a';
	if (pos.col >= field.size() || pos.row >= field.size())
		throw 'b';
	return this->field[pos.row][pos.col];
}



void Lord::set_connection(looper signal, pack handlers, snoopers slots, const int sig_num) {
	if (connections_course.second.sig_num == sig_num)
		return;
	to_snp_info_t  din_struct;
	din_struct.handlers = handlers;
	din_struct.slots = slots;
	din_struct.sig_num = sig_num;
	connections_course = (std::make_pair(signal, din_struct));
	return;
}

bool Lord::emit_signal(looper signal) {
	bool flag = false;
	std::vector<bool> flags;
	if (connections_course.first != signal)
		return 0;
	neighbors neighbors = (dynamic_cast<Lord*>(this)->*signal)();
	if (neighbors.top) {
		flags.push_back((connections_course.second.handlers.top->*connections_course.second.slots.tsnp)(neighbors));
		neighbors = (dynamic_cast<Lord*>(this)->*signal)();
	}
	else if (neighbors.right) {
		flags.push_back((connections_course.second.handlers.right->*connections_course.second.slots.rsnp)(neighbors));
		neighbors = (dynamic_cast<Lord*>(this)->*signal)();
	}
	else {
		flags.push_back((connections_course.second.handlers.bot->*connections_course.second.slots.bsnp)(neighbors));
		neighbors = (dynamic_cast<Lord*>(this)->*signal)();
	}
	for (auto const& flag : flags)
		if (flag)
			return 1;
	try {
		this% current_unit = 'F';
	}
	catch (...) {};
	return 0;
}


void Lord::delete_connection(const int sig_num) {
	connections_course.first = nullptr;
	connections_course = { nullptr ,{0,0} };
};