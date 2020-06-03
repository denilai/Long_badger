#ifndef TREE
#define TREE
#include "Lord.h"
#include <vector>
using namespace Lord_;
class Tree {
public:
	static std::vector<const char*> get_hierarchy(Lord* root); // �����, ������������ ������ ����������
															// �� ������� ������ Lord, ��������������
															// ����� ����������� � ������ �������� 
															// ����������� � �������� ��������
	static Lord* vertical_order_search(std::string master_name,Lord* root);// �����, ������������ ��������� �� ������� � ������ master_name
	static std::vector<std::vector <const char*>> get_2_dim_hierarchy(std::vector<const char*> line);// ����� ������ ��������� ������������� ������� ��������
	static bool IsUnique(std::vector<const char*> vec, unsigned int count);
																								// False � ��������� ������
	static std::vector<bool> get_mask(std::vector<const char*>);// ����� ���������� ������ �� ������� ������ hierarchy. 
																// ����������, ����� �� ��������� hierarchy ���������� �����
	static size_t sum_element(std::vector < bool >mask);// ������������ ���������� false-��������� � �������
};

#endif
