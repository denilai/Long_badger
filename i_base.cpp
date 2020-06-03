#include"lord.h"
#include <iostream>
#include <algorithm>
constexpr auto SPACE_COUNTER = 4;

void IBase::signal_template(std::string& message) {}

void IBase::slot_template(std::string& message) {
	std::cout << message;
}

void IBase::set_connection(sig_ptr_t signal, IBase* handler, slt_ptr_t slot,const int sig_num ) {
	for (auto it = connections.begin(); it != connections.end(); it++)
		if (it->second->sig_num == sig_num)
			return;
	sig_info_t* din_struct = new sig_info_t;
	din_struct->handler = handler;
	din_struct->slot = slot;
	din_struct->sig_num = sig_num;
	connections.push_back(make_pair(signal, din_struct));
	return;
}

void IBase::delete_connection(const int sig_num) {
	for (auto it = connections.begin(); it != connections.end(); it++)
		if (it->second->sig_num == sig_num) {
			connections.erase(it);
			return;
		}
}

void IBase::emit_signal(sig_ptr_t signal, std::string& message) {
	(this->*signal)(message);
	for (auto const& connection : connections) {
		if (connection.first == signal) {
			std::cout <<std::endl<< "Signal to " << connection.second->handler->get_name();
			std::cout << " Text: " << this->get_name() << "-> ";
			(connection.second->handler->*connection.second->slot)(message);			
		}
	}
}

IBase* IBase::vertical_ordered_search(std::string name) {
	if (!this)
		return nullptr;
	if (this->get_name() == name)
		return this;
	for (auto const &slave : this->get_list())
		if (IBase* answer = slave->vertical_ordered_search(name))
			return answer;
	return nullptr;
}

std::vector<std::string>IBase::get_vertical_ordered_hierarchy() {
	std::vector<std::string> hierarchy, iteration;
	if (this != nullptr) {
		hierarchy.push_back(this->get_name());
		for (auto const &slave: this->get_list()) {
			iteration = slave->get_vertical_ordered_hierarchy();
			std::copy(iteration.begin(), iteration.end(), std::back_inserter(hierarchy));
		}
	}
	return hierarchy;
}

void IBase::show_vertical_ordered_tree(unsigned space_num, bool &first) {
	if (!this)
		return;
	if (!first) 
		std::cout << std::endl;
	first = false;
	[](unsigned num)->void {
		for (unsigned a = 0; a < num; a++)
			std::cout << " ";
	}(space_num);
	std::cout << this->get_name();
	space_num += SPACE_COUNTER;
	for(auto const &slave: this->get_list())
		slave->show_vertical_ordered_tree(space_num, first);
}

void IBase::show_horizontal_ordered_tree() {
	if (!this)
		return;
	std::queue <IBase*> members;
	members.push(this);
	std::cout << members.front()->get_name();
	while (!members.empty()) {
		if (!members.front()->get_list().empty())
			std::cout << std::endl << members.front()->get_name();
		for (auto const &slave : members.front()->get_list()) {
			members.push(slave);
			std::cout << "  " << slave->get_name();
		}
		members.pop();
	}
}

IBase* IBase::path_parser(std::string &path){
	auto double_slash = [](std::string path,IBase* master)->IBase* {
		if (path.substr(0, 2) != "//")
			return nullptr;
		std::string member = path.substr(2);
		if (!master->get_forerunner()->IsUniqueNames(member))
			return (nullptr);
		return master->get_forerunner()->vertical_ordered_search(member);
	};
	if (path == ""|| path[0] != '/')
		return nullptr;
	if (path.find("//") != std::string::npos)
		return double_slash(path,this);
	std::string master_name;
	if (path.find("/", 1) != std::string::npos) // проверка на то, что в адресе может быть указан всего один элемент
		master_name = path.substr(1, path.find("/", 1) - 1);
	else
		master_name = path.substr(1, path.length() - 1);
	path.erase(0, master_name.length() + 1);
	if (master_name != this->get_name())
		return nullptr;
	if (path == "")
		return this;
	std::string slave_name = path.substr(1, path.find("/", 1) - 1);
	for (auto const& slave : this->get_list()) {
		if (slave->get_name() == slave_name)
			return slave->path_parser(path);
	}
	return nullptr;
}

bool IBase::IsUniqueNames(std::string member){				//  проверка на уникальность имен
	std::vector<std::string> hierarchy = this->get_vertical_ordered_hierarchy();
	const int member_pos = [](std::vector<std::string> array, std::string pattern)->const int {
		reverse(array.begin(),array.end());
		for (auto it =array.begin(); it !=array.end(); it++)
			if (*it == pattern)
				return (array.size()-(it-array.begin())-1);
		return -1;
	}(hierarchy,member);
	std::vector<bool> mask=[&hierarchy]()->std::vector<bool> {
		std::vector<bool>_mask;
		for (auto current = hierarchy.begin(), first = hierarchy.begin(); current != hierarchy.end();current++)
			_mask.push_back([](auto first, auto current)->bool {
				for (; first != current; first++)
					if (*first == *current)
						return false;
				return true;
			}(first,current));
		return _mask;
	}();
	try {
		if(member_pos!=-1)
			return mask[member_pos];
		throw - 1;
	}
	catch (int) {
		return true;
	}
	//return !std::count_if(mask.begin(), mask.end(),[](bool x)->int {return !x;});
}

IBase* IBase::get_forerunner() {
	try {
		if (!this->get_master())
			return this;
		return this->get_master()->get_forerunner();
		throw -1;
	}
	catch (int) {
		std::cout << "ERROR FORERRUNER" << std::endl;
		return nullptr;
	}
}



// ----------------------- Курсовая ----------------------------//


