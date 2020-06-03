#include "structures.h"
#include "lord.h"
#include "snoopes.h"


//------------------------------------class LeftSnoopy---------------------------------//

std::string LeftSnoopy::IsUnitHere(const neighbors symb) { return symb.left ? "lsignal_1" : "lsignal_2"; }

std::string LeftSnoopy::get_name()const { return "LeftSnoopy"; }

bool LeftSnoopy::emit_signal(const neighbors symb) { return (handler->*slot)(IsUnitHere(symb)); }

void LeftSnoopy::delete_connection() {
	handler = nullptr;
	slot = nullptr;
}

void LeftSnoopy::set_connection(Lord* header, stepper& slot) {
	delete_connection();
	this->handler = header;
	this->slot = (slot);
}

//------------------------------------class RightSnoopy---------------------------------//

std::string RightSnoopy::IsUnitHere(const neighbors symb) { return symb.right ? "rsignal_1" : "rsignal_2"; }

std::string RightSnoopy::get_name()const { return "RightSnoopy"; }

bool RightSnoopy::emit_signal(const neighbors symb) { return (handler->*slot)(IsUnitHere(symb)); }

void RightSnoopy::delete_connection() {
	handler = nullptr;
	slot = nullptr;
}

void RightSnoopy::set_connection(Lord* header, stepper& slot) {
	delete_connection();
	this->handler = header;
	this->slot = (slot);
}

//------------------------------------class TopSnoopy---------------------------------//
std::string TopSnoopy::IsUnitHere(const neighbors symb) { return symb.top ? "tsignal_1" : "tsignal_2"; }

std::string TopSnoopy::get_name()const { return "TopSnoopy"; }

bool TopSnoopy::emit_signal(const neighbors symb) { return (handler->*slot)(IsUnitHere(symb)); }

void TopSnoopy::delete_connection() {
	handler = nullptr;
	slot = nullptr;
}

void TopSnoopy::set_connection(Lord* header, stepper& slot) {
	delete_connection();
	this->handler = header;
	this->slot = (slot);
}

//------------------------------------class BotSnoopy---------------------------------//

std::string BotSnoopy::IsUnitHere(const neighbors symb) { return symb.bot ? "bsignal_1" : "bsignal_2"; }

std::string BotSnoopy::get_name()const { return "BotSnoopy"; }

bool BotSnoopy::emit_signal(const neighbors symb) { return (handler->*slot)(IsUnitHere(symb)); }

void BotSnoopy::delete_connection() {
	handler = nullptr;
	slot = nullptr;
}

void BotSnoopy::set_connection(Lord* header, stepper& slot) {
	delete_connection();
	this->handler = header;
	this->slot = (slot);
	std::string a;
}

//-------------------------------------------------------------------------------------//
