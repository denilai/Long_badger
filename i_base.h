#ifndef IBASE_H
#define IBASE_H
#include "structures.h"


//���������, ������� ������� ����������� ��� ������� � ���������
class IBase {
protected:
//-----���� ��� ���������� ����������� �������� � ������������-----//
	connects_t connections;
// ----------------------��������-------------------------------//
	

// -------------------------------------------------------------//

//----------------------protected signals--------------------------//
	virtual void signal_template(std::string&);
//----------------------protected slots----------------------------//
	virtual void slot_template(std::string&);
//-----------------------------------------------------------------//
	virtual void set_name(const std::string) = 0;
	virtual const std::string get_name()const = 0;
	virtual IBase* get_master()const = 0;
	virtual std::vector<IBase*> get_list()const = 0;
	virtual void add_slave(IBase*) = 0;
	virtual void inform_condition()const = 0;	
	virtual ClassID get_ID()const = 0;
	virtual void set_connection(sig_ptr_t, IBase*, slt_ptr_t, const int); // ���������� �����������
	virtual void emit_signal(sig_ptr_t, std::string&);					// ��������� ������, ����������� �����������
	void delete_connection(const int);											// ��������� �����

public:
	std::vector<std::string> get_vertical_ordered_hierarchy();
	// !!!(����� � �������)!!!
	// ����� ���������� ������ ���� ��������,
	// ���������� � ������� ������ �������� � �������

	IBase* vertical_ordered_search(std::string);
	// �����, ������������ ��������� �� ������� � ������, ���������� ������ ����������

	void show_vertical_ordered_tree(unsigned, bool&);
	// ������� ������������� �������� �������� � ���� ������ ������ �� �������

	void show_horizontal_ordered_tree();
	// ������� ������������� �������� �������� � ���� ������ ������ �� ������

	IBase* path_parser(std::string&);
	// ��������� �������� ��������� ���������. ���� ������ �� ������
	// ����������� ����������, ���������� ��� ��������� 
	// ����� ���������� nullptr

	bool IsUniqueNames(std::string);
	// 1 - ��� ������� � �������� ����� ���������� �����
	// 0 - ���� ������� � ������������ ������ (������ �������� �������)

	IBase* get_forerunner(); // forerunner - ��������; �������� ���� ���� �����
};
#endif