#pragma once



typedef struct DataItem {
	int item1;
	int item2;
	int item3;
} DATAITEM;




typedef struct UserCall {
	int user_floor; //用户所在楼层
	int user_target; //用户目标楼层
	int call_time; //用户请求时刻
	char call_type; //用户请求类型，′U′表示上行指令，′D′表示下行指令
}USERCALL;



typedef struct ServeListNode {
	char serve_state; //电梯服务状态
	USERCALL *user_call;//电梯当前响应用户指令时，指向指令数组的某一个元素
	struct ServeListNode *next_node;//存储下一个结点的地址
}SERVELISTNODE;

typedef struct elevatorstate {
	int current_floor; //电梯当前所处楼层
	char run_state; //电梯运行状态
	SERVELISTNODE *serve_list;//电梯当前服务指令队列指针
}ELEVATORSTATE;

typedef struct ResponseListNode {
	USERCALL *user_call; //用户指令在指令数组中对应的序号
	struct ResponseListNode *next_node;//存储下一个结点的地址
}RESPONSELISTNODE;

typedef struct ResponseListHeadNode {
	int list_num; //待响应用户指令链表中数据结点的个数
	RESPONSELISTNODE *head;//链表中第一个数据结点的指针
	RESPONSELISTNODE *tail;//链表中最后一个数据结点的指针
}RESPONSELISTHEADNODE;

typedef struct conf {
	char *filename;//用于存储数据记录文件的文件名信息
	int leng;//用于数据个数 
	int time;//用于存放时间 
	ELEVATORSTATE *elevator;//用于存放电梯状态
	RESPONSELISTHEADNODE readynode;//用于存放待响应序列
	DATAITEM *dataitem;//结构体数组
	int ii;//结构体的位置 
}CONF;
