#ifndef LORD
#define LORD
#include "i_base.h"

class Lord:public IBase {
protected:
	std::string Name;
	Lord* master;// указатель на объект класса Lord, являющийся корневым.
	std::vector<IBase*> slaves;// массив указателей на подчиненные объекты класса Lord
	//  ----------------------------- поля, добавленные для выполнения курсовой работы ----------------//
	std::vector<std::string> field;								// поле
	
	position current_unit;										// координата последней найденной единицы


public:
	to_snp_pair_t connections_course;
	explicit Lord(Lord*, const std::string name="");
	void set_name(const std::string) override final;
	const std::string get_name()const override final;
	Lord* get_master()const override final;
	std::vector<IBase*> get_list()const override final;
	void add_slave(IBase*) override final;
	void inform_condition()const override;
	virtual ClassID get_ID()const override;
	friend bool process(IBase*, std::vector<std::string>&, std::istream &, link_queue_t&,unique_callers_vec_t&);// поток для отладки
	friend link_queue_t set_interfaces(std::istream&, IBase*);
	friend unique_callers_vec_t set_commands(std::istream&, link_queue_t);
	virtual ~Lord();

	//----------------------методы, добавленные для выполнения курсовой работы  -------------------------//
	void set_connection(looper, pack, snoopers, const int);		// установить соеднинение
	bool emit_signal(looper);									// испустить сигнал, опопвестить обработчики
	void delete_connection(const int);							// разорвать связь
	
	neighbors loop_survey();									// опрос обработчиков на текущей итерации
	bool step(std::string);
	explicit Lord(const int dim = 0);
	Lord(const Lord* old);
	position get_curr_unit();
	void create_field(std::istream&);							// метод задания поля
	void show_matrix()const;									// метод вывода поля
	neighbors take_neighbors(position) const;					// использовать catch{}, метод передает структуру соседей
	void find_first_unit();
	friend void process_course(Lord*);
	char& operator[](position);
	friend char& operator%(Lord*, position);



};
#endif
