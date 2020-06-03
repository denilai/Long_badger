#include <iostream>
#include <cstring>
#include <algorithm> 
#include "Lord.h"
#include "Tree.h"
#include <list>
#include <iomanip>
#include <conio.h>

using namespace std;
using namespace Lord_;
int main() {
	unsigned count = 0;
	string Name1, Name2, Anonimus;
	cin>>Name1;
	Lord root(nullptr, Name1);
	Lord* master = nullptr;
	for (;;) {
		cin >> Name1;
		cin >> Anonimus;
		if (Name1==Anonimus)
			break;
		master = Tree::vertical_order_search (Name1, &root);
		Lord*ptr= new Lord(master);
		ptr->set_name(Anonimus);
		master->add_slave(ptr);
	}

	/*Lord B(&root, "B");
	root.add_slave(&B);
	Lord C(&root, "C");
	root.add_slave(&C);
	Lord D(&root, "D");
	root.add_slave(&D);
	Lord B_1(&B, "B_1");
	Lord B_2(&B, "B_2");
	Lord B_3(&B, "B_3");
	B.add_slave(&B_1);
	B.add_slave(&B_2);
	B.add_slave(&B_3);
	Lord B_2_1(&B_2, "B_2_1");
	Lord B_2_2(&B_2, "B_2_2");
	Lord B_2_3(&B_2, "B_2_3");
	B_2.add_slave(&B_2_1);
	B_2.add_slave(&B_2_2);
	B_2.add_slave(&B_2_3);
	Lord D_1(&D, "D_1");
	Lord D_2(&D, "D_2");
	Lord D_3(&D, "D_3");
	Lord D_4(&D, "D_4");
	D.add_slave(&D_1);
	D.add_slave(&D_2);
	D.add_slave(&D_3);
	D.add_slave(&D_4);*/


	vector<const char*> hierarchy = Tree::get_hierarchy(&root);
	vector<vector<const char*>> hell = Tree::get_2_dim_hierarchy(hierarchy);
	int count_of_enter = hell.size()-1;
	cout << root.get_name() << endl;
	for_each(hell.begin(), hell.end(), [&count_of_enter](vector<const char*> vec)->void {
		int count_of_space = vec.size()-1;
		for_each(vec.begin(), vec.end(), [&count_of_space](const char* el)->void {
			cout << el;
			if(count_of_space)
				cout<<"  ";
			count_of_space--;
		});
		if(count_of_enter)
			cout << endl;
		count_of_enter--;
	});
	[]() {
		
	}
	system("pause");
	return 0;
}