////#include"Tree.h"
//#include <queue>
//#include "Lord.h"
//#include <iostream>
//
//
//std::vector<std::string> IBase::horizontal_ordered_hierarchy(Lord* root) {
//	std::queue <Lord*> members;													// создаем новую очередь
//	std::vector<std::string> hierarchy;											// об€вл€ем список, в который будет записана иерахи€
//	members.push(root);															// добавл€ем в очередь корневой элемент, дальнеейшее обращение через элементы очереди
//	while (!members.empty()) {													// то есть пока не просмотрены все уровни иерархии
//		std::list<Lord*>slaves = (members.front())->get_list();					// список подчиненных объектов экземпл€ра 
//																				// Lord на рассматриваемом уровне иерархии
//		if (!slaves.empty()) {
//			hierarchy.push_back(members.front()->get_name());								// особенности вывода - перед очередным уровнем подчиненных
//																				// экземпл€ров выводим им€ корневого дл€ них объекта
//			for (typename std::list<Lord*>::iterator p = slaves.begin(); p != slaves.end(); p++) {
//				members.push(*p);
//				hierarchy.push_back((*p)->get_name());
//			}
//		}
//		members.pop();															// удал€ем первый элемент в очереди, указыва€ на то, что данный уровень иерархии пройден
//	}
//	return hierarchy;
//}
//std::vector<std::string>IBase::vertical_ordered_hierarchy(Lord* root) {
//	std::vector<std::string> hierarchy, iter;
//	if (root != nullptr) {
//		hierarchy.push_back(root->get_name());
//		std::list<Lord*> clone = root->get_list();
//		for (typename std::list<Lord*>::iterator p = clone.begin(); p != clone.end(); p++) {
//			iter = vertical_ordered_hierarchy(*p);
//			std::copy(iter.begin(), iter.end(), std::back_inserter(hierarchy));
//		}
//	}
//
//	return hierarchy;
//}
//Lord* IBase::vertical_ordered_search(std::string master_name, Lord* root) {// поиск элемента с именем master_name
//																	   // путем обхода дерева св€зей в глубину
//	Lord* answer = nullptr;
//	if (root != nullptr) {
//		if (root->get_name() == master_name)
//			answer = root;
//		else {
//			std::list<Lord*> clone = root->get_list();
//			for (typename std::list<Lord*>::iterator p = clone.begin(); p != clone.end(); p++) {
//				answer = vertical_ordered_search(master_name, *p);
//				if (answer != nullptr)
//					break;
//			}
//		}
//	}
//	return answer;
//}
//bool IBase<Lord>::IsUnique(std::vector<std::string> vec, unsigned int count)
//{
//	// прин€та условность, что если метод get_name() 
//	// возвращает идентичные строки дл€ разных указателей,
//	// то они указывают на один и тот же объект
//	// (не могут встречатс€ два разных объекта с одинаковым именем)
//
//	for (std::vector<std::string>::iterator p = vec.begin(), t = vec.begin() + count; p != t; p++) {
//
//		if (*p == *t)
//		{
//			//std::cout << "element " << *p << "is ununique" << std::endl;
//			return false;
//		}
//	}
//	return true;
//}
//template<class T>
//std::vector <bool>IBase<T>::get_mask(std::vector<std::string> hierarchy) {
//	std::vector<bool>mask;
//	int count = 0;
//	// при помощи функции transform заполн€ем в вектор mask_
//	// где count - пор€дковый номер элемента в векторе
//	transform(hierarchy.begin(), hierarchy.end(), back_inserter(mask), [&count, hierarchy](std::string current)->bool {
//		return IBase::IsUnique(hierarchy, count++);
//		});
//	return mask;
//}
//template<class T>
//size_t IBase<T>::sum_element(std::vector<bool>mask) {
//	return std::count_if(mask.begin(), mask.end(), [](bool x)->int {return !x; });
//}
////class Process {
////public:
////	Process(int level = 0) :_level(level) {}	
////	std::vector<const char*> operator() () {
////		std::vector<const char*>row;
////		int current_lvl = 0;
////		for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
////			if (!*p) {
////				current_lvl++;
////				if (current_lvl == level) {
////					copy(t, p, back_inserter(row));
////					level++;
////					t = p;
////				}
////			}
////		}
////		return row;
////	}
////private:
////	int _level = 0;
////	std::vector<const char*>hierarchy=
////	std::vector<bool>_mask = IBase::get_mask(hierarchy);
////};
//
////std::vector<const char*>Process(int level, std::vector<bool>mask_) {
////	std::vector<const char*>row;
////	int current_lvl = 0;
////	for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
////		if (!*p) {
////			current_lvl++;
////			if (current_lvl == level) {
////				copy(t, p, back_inserter(row));
////				level++;
////				t = p;
////			}
////		}
////	}
////	return row;
////}
//
////[&mask_, line, &level]()->std::vector<const char*> {
////	std::vector<const char*>row;
////	int current_lvl = 0;
////	for (std::vector<bool>::iterator p = mask_.begin(), t = mask_.begin(); p != mask_.end(); p++) {
////		if (!*p) {
////			current_lvl++;
////			if (current_lvl == level) {
////				copy(t, p, back_inserter(row));
////				level++;
////				t = p;
////			}
////		}
////	}
////	return row;
////}
//
////class SuperIterator {
////private:
////	typename std::vector<T>::iterator T_iterator;
////	typename std::vector<G>::iterator G_iterator;
////	typename std::vector<T> T_vector;
////	typename std::vector<G> G_vector;
////public:
////	SuperIterator(std::vector<T> &T_vector, std::vector<G> &G_vector):T_vector(T_vector),G_vector(G_vector),T_iterator(T_vector.begin()),G_iterator(G_vector.begin()) {}
////	void inc(int incr = 1) {
////		if (++T_iterator != T_vector.end() && ++G_iterator != G_vector.end());
////		else {
////			T_iterator--;
////			G_iterator--;
////		}
////	}
////	typename std::vector<T>::iterator& get_T_iterator() {
////		return T_iterator;
////	}
////	typename std::vector<G>::iterator& get_G_iterator() {
////		return G_iterator;
////	}
////	typename std::vector<T>& get_T_vector() {
////		return T_vector;
////	}
////};
//
////std::vector<std::string>get_line(std::vector<bool> mask_,std::vector<std::string>line, size_t &pos) {
////	std::vector<std::string>cur_line;
////	bool first=true;
////	for (int i = pos; i < line.size();i++) {
////		if ((!(mask_[i])&&!first)||line[i]==line.back()) {
////			if (pos!=line.size()) {
////				if (line[i] == line.back())
////					i++;
////				for (; pos != i; pos++)
////					cur_line.push_back(line[pos]);
////			}
////			return cur_line;
////		}
////		first = false;
////	}
////}
//template<class T>
//std::vector<std::vector< std::string>> IBase<T>::get_2_dim_hierarchy(std::vector< std::string> line)
//{
//	std::vector<std::vector<std::string>> matrix;
//	std::vector<bool>mask_ = get_mask(line);
//	size_t row = sum_element(mask_);
//	size_t g = 0;
//	if (!mask_.empty())
//		for (int i = 0; i <= row; i++) {
//			matrix.push_back([&mask_, &line, &g]()->std::vector<std::string> {
//				std::vector<std::string>cur_line;
//				bool first = true;
//				for (int i = g; i < line.size(); i++) {
//					if ((!(mask_[i]) && !first) || line[i] == line.back()) {
//						if (g != line.size()) {
//							if (line[i] == line.back())
//								i++;
//							for (; g != i; g++)
//								cur_line.push_back(line[g]);
//						}
//						return cur_line;
//					}
//					first = false;
//				}
//				});
//
//		}
//	return matrix;
//}
//
