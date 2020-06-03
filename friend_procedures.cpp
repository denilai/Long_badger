#include "lord.h"
#include "structures.h"
#include <iostream>
#include "childs.h"
#include "snoopes.h"


link_queue_t set_interfaces(std::istream& stream, IBase* root) {
	link_queue_t relationships;
	if (!stream.good())
		exit(EXIT_FAILURE);
	int sig_num = 0;
	std::string transmitter, handler;
	for (;;) {
		stream >> sig_num;
		if (sig_num == 0)
			break;
		stream >> transmitter >> handler;
		Lord* sig_obj = dynamic_cast<Lord*>(root->vertical_ordered_search(transmitter));
		Lord* slt_obj = dynamic_cast<Lord*>(root->vertical_ordered_search(handler));
		sig_ptr_t signal = &Lord::signal_template;
		slt_ptr_t slot = &Lord::slot_template;
		sig_obj->IBase::set_connection(signal, slt_obj, slot, sig_num);
		relationships.push(input_form_t{ sig_num,sig_obj,slt_obj,signal });
	}
	return relationships;
}

unique_callers_vec_t set_commands(std::istream& stream, link_queue_t relationships) {
	unique_callers_vec_t callers;
	while (!relationships.empty()) {
		std::string queue_name = "Test";//dynamic_cast<Lord*>(relationships.front().transmitter)->get_name();
		if ([](unique_callers_vec_t const& callers, std::string const& queue_name)->bool {
			for (auto& const caller : callers) {
				std::string vector_name = dynamic_cast<Lord*>(caller.transmitter)->get_name();
					if (queue_name == vector_name)
						return 0;
			}
			return 1;
			}(callers, queue_name))
			callers.push_back(emit_struct_t{ relationships.front().transmitter,relationships.front().signal });
			relationships.pop();
	}
	std::string command, transmitter;
	std::cout << std::endl << "Emit signals";
	for (;;) {
		stream >> transmitter;
		if (transmitter == "endsignals")
			break;
		stream >> command;
		for (auto& caller : callers) {
			if (dynamic_cast<Lord*>(caller.transmitter)->get_name() == transmitter)
				dynamic_cast<Lord*>(caller.transmitter)->IBase::emit_signal(caller.signal, command);
		}
	}
	return callers;
}

bool process(IBase* root, std::vector<std::string>& path_list, std::istream& stream, link_queue_t& relationships, unique_callers_vec_t& callers) {
	if (!stream.good())
		exit(EXIT_FAILURE);
	Lord* master = nullptr, * ptr = nullptr;
	std::string Name1, Anonimus, path;
	int class_num = 0, condition = 0;
	bool first = true;
	unsigned row = 0;

	for (;;) {
		stream >> Name1;
		if (Name1 == "endtree")
			break;
		if (Name1 == "exit") {
			std::cout << "Exit to main func?" << std::endl;
			std::cout << "No - return to input process\n" << "Any other word - Exit\n";
			std::string answer;
			std::cin >> answer;
			if (answer != "No")
				return 0;
		}
		stream >> Anonimus;
		stream >> class_num;
		stream >> condition;
		master = dynamic_cast<Lord*>(root->IBase::path_parser(Name1));
		//master = dynamic_cast<Lord*>(root->vertical_ordered_search(Name1));
		switch (class_num) {
		case(2):
			ptr = new Two(master, Anonimus, condition);
			break;
		case(3):
			ptr = new Three(master, Anonimus, condition);
			break;
		case(4):
			ptr = new Four(master, Anonimus, condition);
			break;
		case(5):
			ptr = new Five(master, Anonimus, condition);
			break;
		case(6):
			ptr = new Six(master, Anonimus, condition);
			break;
		}
		if (ptr)
			master->add_slave(ptr);
	}
	while (!stream.eof()) {
		stream >> path;
		if (path == "//")
			break;
		path_list.push_back(path);
	}


	std::cout << std::endl << "---Object three (vertical)---" << std::endl;
	root->show_vertical_ordered_tree(row, first);
	std::cout << std::endl;

	relationships = set_interfaces(stream, root);
	[](link_queue_t queue)->void {
		std::cout << "Set connects";
		while (!queue.empty()) {
			std::cout << std::endl;
			std::cout << queue.front().sig_num << " ";
			std::cout << dynamic_cast<Lord*>(queue.front().transmitter)->get_name() << " ";
			std::cout << dynamic_cast<Lord*>(queue.front().handler)->get_name();
			queue.pop();
		}
	}(relationships);
	callers = set_commands(stream, relationships);
	return 1;
}


//-------------------------  ”–—Œ¬¿ﬂ –¿¡Œ“¿  ----------------------------//


char& operator%(Lord* matrix, position pos) {
	if (pos.col < 0 || pos.row < 0)
		throw 'a';
	if (pos.col >= matrix->field.size() || pos.row >= matrix->field.size())
		throw 'b';
	return matrix->field[pos.row][pos.col];
}

void process_course(Lord* matrix) {
	if (matrix->get_curr_unit().row == -1) {
		matrix->show_matrix();
		return;
	}
	TopSnoopy Top;
	RightSnoopy Right;
	BotSnoopy Bot;
	LeftSnoopy Left;
	pack headers = { &Top,&Right,&Bot,&Left };

	tsnooper top = &TopSnoopy::emit_signal;
	rsnooper right = &RightSnoopy::emit_signal;
	bsnooper bot = &BotSnoopy::emit_signal;
	lsnooper left = &LeftSnoopy::emit_signal;
	snoopers slots = { top,right,bot,left };

	looper loop = &Lord::loop_survey;
	stepper step = &Lord::step;
	neighbors a{ 1,1,1,1 };

	matrix->set_connection(loop, headers, slots, 1);
	Top.set_connection(matrix, step);
	Right.set_connection(matrix, step);
	Bot.set_connection(matrix, step);
	Left.set_connection(matrix, step);
	for (;;)
		if (!matrix->emit_signal(loop))
			break;
	matrix->show_matrix();
}