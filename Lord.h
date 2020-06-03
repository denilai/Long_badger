#ifndef LORD
#define LORD
#include <list>
#include <string>
namespace Lord_{
	class Lord {
	private:
		char* Name = nullptr;
		Lord* master;// ��������� �� ������ ������ Lord, ���������� ��������.
		std::list<Lord*> slaves;// ������ ���������� �� ����������� ������� ������ Lord
	public:
		Lord(Lord*, std::string);
		Lord(Lord*);
		~Lord();
		void set_name(const std::string);
		const char* get_name();
		void add_slave(Lord*);
		void show_list(std::list<Lord*>);
		Lord* get_master();
		std::list<Lord*> get_list();
	};
};
#endif
