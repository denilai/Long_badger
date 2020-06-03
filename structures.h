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
}input_form_t;// �����, ����������� ����� ������� ������

typedef  struct {
	IBase* transmitter;
	sig_ptr_t signal;
}emit_struct_t; // ��������� ��� ������ ������ emit_signal


typedef std::pair<sig_ptr_t, sig_info_t*> transm_info_t;// ������ ���������� � ����� ������-����������

typedef std::vector<transm_info_t> connects_t;// ������� 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // ������ ���������� ��������-������������ � �� ������� ���������
typedef std::queue<input_form_t> link_queue_t;// ������� ���������� ������ 

enum class  ClassID {
	ROOT,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX
};


// ------------------------------------------- �������� -------------------------------------//




class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef struct {// ���������� �������� �� ���� ������ std::pair
	int row;
	int col;
}position;

struct neighbors {// ������ ������-���� �������� �������. 
	bool top = false;
	bool right = false;
	bool bot = false;
	bool left = false;
};

typedef bool(LeftSnoopy::* lsnooper)(neighbors const);			// ������ ������ ������� �����
typedef bool(RightSnoopy::* rsnooper)(neighbors const);			// ������ ������ ������� ������
typedef bool(TopSnoopy::* tsnooper)(neighbors const);			// ������ ������ ������� ������
typedef bool(BotSnoopy::* bsnooper)(neighbors const);			// ������ ������ ������� �����

typedef bool (Lord::* stepper)(std::string);					// ������ ������ � �����
typedef neighbors(Lord::* looper)(void);						// ������ ���������� ��������

typedef struct {//  ��������� ���� ���������� �� ������ ��������-������������
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;
} snoopers;

typedef struct {//  ��������� ���� ���������� �������-�����������
	TopSnoopy* top;
	RightSnoopy* right;
	BotSnoopy* bot;
	LeftSnoopy* left;
}pack;

typedef  struct {// ���������, ���������� ��� ���������� � �������
	pack handlers;// ����������
	snoopers slots;// ****
	int sig_num;
}to_snp_info_t;

typedef std::pair<looper, to_snp_info_t> to_snp_pair_t;// ������ ���������� � ����� Owner->Snoopy

















#endif