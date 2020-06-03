#ifndef LORD
#define LORD
#include "i_base.h"

class Lord:public IBase {
protected:
	std::string Name;
	Lord* master;// ��������� �� ������ ������ Lord, ���������� ��������.
	std::vector<IBase*> slaves;// ������ ���������� �� ����������� ������� ������ Lord
	//  ----------------------------- ����, ����������� ��� ���������� �������� ������ ----------------//
	std::vector<std::string> field;								// ����
	
	position current_unit;										// ���������� ��������� ��������� �������


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
	friend bool process(IBase*, std::vector<std::string>&, std::istream &, link_queue_t&,unique_callers_vec_t&);// ����� ��� �������
	friend link_queue_t set_interfaces(std::istream&, IBase*);
	friend unique_callers_vec_t set_commands(std::istream&, link_queue_t);
	virtual ~Lord();

	//----------------------������, ����������� ��� ���������� �������� ������  -------------------------//
	void set_connection(looper, pack, snoopers, const int);		// ���������� �����������
	bool emit_signal(looper);									// ��������� ������, ����������� �����������
	void delete_connection(const int);							// ��������� �����
	
	neighbors loop_survey();									// ����� ������������ �� ������� ��������
	bool step(std::string);
	explicit Lord(const int dim = 0);
	Lord(const Lord* old);
	position get_curr_unit();
	void create_field(std::istream&);							// ����� ������� ����
	void show_matrix()const;									// ����� ������ ����
	neighbors take_neighbors(position) const;					// ������������ catch{}, ����� �������� ��������� �������
	void find_first_unit();
	friend void process_course(Lord*);
	char& operator[](position);
	friend char& operator%(Lord*, position);



};
#endif
