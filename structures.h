#ifndef STRUCTURES
#define STRUCTURES
#include <string>
#include <vector>
#include <queue>

class Lord;
class IBase;
typedef void (IBase::* sig_ptr_t)(std::string&);
typedef void (IBase::* slt_ptr_t)(std::string&);

typedef  struct {
	IBase* handler;
	slt_ptr_t slot;
	int sig_num;
}sig_info_t;

typedef  struct {
	int sig_num;
	IBase* transmitter;
	IBase* handler;
	sig_ptr_t signal;
}input_form_t;// форма, аналогичная форме задания связей

typedef  struct {
	IBase* transmitter;
	sig_ptr_t signal;
}emit_struct_t; // структура для вызова метода emit_signal


typedef std::pair<sig_ptr_t, sig_info_t*> transm_info_t;// полная информация о связи сигнал-обработчик

typedef std::vector<transm_info_t> connects_t;// разъемы 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // список уникальных объектов-передатчиков и их связных праметров
typedef std::queue<input_form_t> link_queue_t;// очередь объявления связей 

enum class  ClassID {
	ROOT,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};


// ------------------------------------------- Курсовая -------------------------------------//




class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef struct {// координаты элемента по сути просто std::pair
	int row;
	int col;
}position;

struct neighbors {// соседи какого-либо элемента массива. 
	bool top = false;
	bool right = false;
	bool bot = false;
	bool left = false;
};

typedef bool(LeftSnoopy::* lsnooper)(neighbors const);			// методы поиска единицы слева
typedef bool(RightSnoopy::* rsnooper)(neighbors const);			// методы поиска единицы справа
typedef bool(TopSnoopy::* tsnooper)(neighbors const);			// методы поиска единицы сверху
typedef bool(BotSnoopy::* bsnooper)(neighbors const);			// методы поиска единицы снизу

typedef bool (Lord::* stepper)(std::string);					// методы замены и шагов
typedef neighbors(Lord::* looper)(void);						// методы проведения итераций

typedef struct {//  стурктура всех указателей на методы объектов-обработчиков
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;
} snoopers;

typedef struct {//  стурктура всех указателей объекты-обработчики
	TopSnoopy* top;
	RightSnoopy* right;
	BotSnoopy* bot;
	LeftSnoopy* left;
}pack;

typedef  struct {// Структура, отражающая всю информацию о сигнале
	pack handlers;// обработчик
	snoopers slots;// ****
	int sig_num;
}to_snp_info_t;

typedef std::pair<looper, to_snp_info_t> to_snp_pair_t;// полная информация о связи Owner->Snoopy

















#endif