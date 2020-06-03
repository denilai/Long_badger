#ifndef IBASE_H
#define IBASE_H
#include "structures.h"


//интерфейс, который обязаны реализовать все объекты в программе
class IBase {
protected:
//-----поля для реализации функционала сигналов и обработчиков-----//
	connects_t connections;
// ----------------------Курсовая-------------------------------//
	

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
	virtual void set_connection(sig_ptr_t, IBase*, slt_ptr_t, const int); // установить соеднинение
	virtual void emit_signal(sig_ptr_t, std::string&);					// испустить сигнал, опопвестить обработчики
	void delete_connection(const int);											// разорвать связь

public:
	std::vector<std::string> get_vertical_ordered_hierarchy();
	// !!!(обход в глубину)!!!
	// метод возвращает массив имен объектов,
	// записанных в порядке обхода иерархии в глубину

	IBase* vertical_ordered_search(std::string);
	// метод, возвращающий указатель на элемент с именем, переданным первым параметром

	void show_vertical_ordered_tree(unsigned, bool&);
	// выводит представление иерархии объектов в виде обхода дерева по глубине

	void show_horizontal_ordered_tree();
	// выводит представление иерархии объектов в виде обхода дерева по ширине

	IBase* path_parser(std::string&);
	// совершает проверку введенных координат. Если объект по данным
	// координатам существует, возвращает его указатель 
	// иначе возвращает nullptr

	bool IsUniqueNames(std::string);
	// 1 - все объекты в иерархии имеют уникальные имена
	// 0 - есть объекты с неуникальным именем (разные корневые объекты)

	IBase* get_forerunner(); // forerunner - предтеча; получить отца всех отцов
};
#endif