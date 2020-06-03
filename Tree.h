#ifndef TREE
#define TREE
#include "Lord.h"
#include <vector>
using namespace Lord_;
class Tree {
public:
	static std::vector<const char*> get_hierarchy(Lord* root); // метод, возвращающий список указателей
															// на объекты класса Lord, представл€ющий
															// собой развернутую в строку иерархию 
															// производных и корневых объектов
	static Lord* vertical_order_search(std::string master_name,Lord* root);// метод, возвращающий указатель на элемент с именем master_name
	static std::vector<std::vector <const char*>> get_2_dim_hierarchy(std::vector<const char*> line);// метод строит двумерное представление ирархии объектов
	static bool IsUnique(std::vector<const char*> vec, unsigned int count);
																								// False в противном случае
	static std::vector<bool> get_mask(std::vector<const char*>);// метод возвращает вектор по размеру равный hierarchy. 
																// ќпредел€ет, какой из элементов hierarchy встречалс€ ранее
	static size_t sum_element(std::vector < bool >mask);// подсчитывает количество false-элементов в массиве
};

#endif
