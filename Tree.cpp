#include"Tree.h"
#include<vector>
#include<queue>
#include<string>
#include <iostream>
#include <algorithm>
#include <iomanip>
std::vector<const char*> Tree::get_hierarchy(Lord* root) {
	std::queue <Lord*> members;													// создаем новую очередь
	std::vector<const char*> hierarchy;													// об€вл€ем список, в который будет записана иерахи€
	members.push(root);															// добавл€ем в очередь корневой элемент, дальнеейшее обращение через элементы очереди
	while (!members.empty()) {													// то есть пока не просмотрены все уровни иерархии
		std::list<Lord*>slaves = (members.front())->get_list();					// список подчиненных объектов экземпл€ра 
																				// Lord на рассматриваемом уровне иерархии
		if (!slaves.empty()) {
			hierarchy.push_back(members.front()->get_name());								// особенности вывода - перед очередным уровнем подчиненных
																				// экземпл€ров выводим им€ корневого дл€ них объекта
			for (std::list<Lord*>::iterator p = slaves.begin(); p != slaves.end(); p++) {
				members.push(*p);
				hierarchy.push_back((*p)->get_name());
			}
		}
		members.pop();															// удал€ем первый элемент в очереди, указыва€ на то, что данный уровень иерархии пройден
	}
	return hierarchy;
}
Lord* Tree::vertical_order_search(std::string master_name,Lord* root) {
	Lord* answer = nullptr;
	if (root != nullptr) {
		if (root->get_name() == master_name)
			answer = root;
		else {
			std::list<Lord*> clone = root->get_list();
			for (std::list<Lord*>::iterator p = clone.begin(); p != clone.end(); p++) {
				answer = vertical_order_search(master_name, *p);
				if (answer != nullptr)
					break;
			}
		}
	}
	return answer;
}
bool Tree::IsUnique(std::vector<const char*> vec,unsigned int count)
{
	// прин€та условность, что если метод get_name() 
	// возвращает идентичные строки дл€ разных указателей,
	// то они указывают на один и тот же объект
	// (не могут встречатс€ два разных объекта с одинаковым именем)

	for (std::vector<const char*>::iterator p = vec.begin(),t= vec.begin() + count; p != t; p++) {
		
		if (*p == *t)
		{
			std::cout << "element " << *p << "is ununique" << std::endl;
			return false;
		}
	}
	return true;
}
std::vector <bool>Tree::get_mask(std::vector<const char*> hierarchy) {
	std::vector<bool>mask;
	int count = 0;
	transform(hierarchy.begin(), hierarchy.end(), back_inserter(mask), [&count,hierarchy](const char* current)->bool {
			return Tree::IsUnique(hierarchy, count++);
		});
	return mask;
}
size_t Tree::sum_element(std::vector<bool>mask) {
	return std::count_if(mask.begin(), mask.end(), [](bool x)->int {return !x;});
}
//class Process {
//public:
//	Process(int level = 0) :_level(level) {}	
//	std::vector<const char*> operator() () {
//		std::vector<const char*>row;
//		int current_lvl = 0;
//		for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
//			if (!*p) {
//				current_lvl++;
//				if (current_lvl == level) {
//					copy(t, p, back_inserter(row));
//					level++;
//					t = p;
//				}
//			}
//		}
//		return row;
//	}
//private:
//	int _level = 0;
//	std::vector<const char*>hierarchy=
//	std::vector<bool>_mask = Tree::get_mask(hierarchy);
//};

//std::vector<const char*>Process(int level, std::vector<bool>mask_) {
//	std::vector<const char*>row;
//	int current_lvl = 0;
//	for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
//		if (!*p) {
//			current_lvl++;
//			if (current_lvl == level) {
//				copy(t, p, back_inserter(row));
//				level++;
//				t = p;
//			}
//		}
//	}
//	return row;
//}

//[&mask_, line, &level]()->std::vector<const char*> {
//	std::vector<const char*>row;
//	int current_lvl = 0;
//	for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
//		if (!*p) {
//			current_lvl++;
//			if (current_lvl == level) {
//				copy(t, p, back_inserter(row));
//				level++;
//				t = p;
//			}
//		}
//	}
//	return row;
//}

//class SuperIterator {
//private:
//	typename std::vector<T>::iterator T_iterator;
//	typename std::vector<G>::iterator G_iterator;
//	typename std::vector<T> T_vector;
//	typename std::vector<G> G_vector;
//public:
//	SuperIterator(std::vector<T> &T_vector, std::vector<G> &G_vector):T_vector(T_vector),G_vector(G_vector),T_iterator(T_vector.begin()),G_iterator(G_vector.begin()) {}
//	void inc(int incr = 1) {
//		if (++T_iterator != T_vector.end() && ++G_iterator != G_vector.end());
//		else {
//			T_iterator--;
//			G_iterator--;
//		}
//	}
//	typename std::vector<T>::iterator& get_T_iterator() {
//		return T_iterator;
//	}
//	typename std::vector<G>::iterator& get_G_iterator() {
//		return G_iterator;
//	}
//	typename std::vector<T>& get_T_vector() {
//		return T_vector;
//	}
//};
//T-bool
//G-const char*
template<typename T, typename G>
std::vector<G>get_line(std::vector<T> mask_,std::vector<G>line, size_t &pos) {
	std::vector<G>cur_line;
	bool first=true;
	for (int i = pos; i < line.size();i++) {
		if ((!(mask_[i])&&!first)||line[i]==line.back()) {
			if (pos!=line.size()) {
				for (; pos != i; pos++)
					cur_line.push_back(line[pos]);
			}
			return cur_line;
		}
		first = false;
	}
}
std::vector<std::vector<const char*>> Tree::get_2_dim_hierarchy(std::vector<const char*> line)
{
	std::vector<std::vector<const char*>> matrix;
	std::vector<bool>mask_ = get_mask(line);
	size_t row = sum_element(mask_);
	size_t g = 0;
	for (int i = 0; i <= row; i++) {
		matrix.push_back(get_line<bool, const char*>(mask_, line, g));
	}
	return matrix;
}

