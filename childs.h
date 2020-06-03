#ifndef CHILDS_H
#define CHILDS_H
#include "lord.h"

class Two :public Lord {
private:
	const int condition;
public:
	Two(Lord* master, const std::string Anonimus, int condition);
	ClassID get_ID()const override;
	void inform_condition()const override;
};

class Three : public Lord {
private:
	const int condition;
public:
	Three(Lord* master, const std::string Anonimus, int condition);
	ClassID get_ID()const override;
	void inform_condition()const override;
};

class Four : public Lord {
private:
	const int condition;
public:
	Four(Lord* master, const std::string Anonimus, int condition);
	ClassID get_ID()const override;
	void inform_condition()const override;
};

class Five : public Lord {
private:
	const int condition;
public:
	Five(Lord* master, const std::string Anonimus, int condition);
	ClassID get_ID()const override;
	void inform_condition()const override;
};

class Six : public Lord {
private:
	const int condition;
public:
	Six(Lord* master, const std::string Anonimus, int condition);
	ClassID get_ID()const override;
	void inform_condition()const override;
};
#endif