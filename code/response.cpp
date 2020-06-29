#include"stdafx.h"
#include"data.h"
#include"response.h"


//函数功能:将一个用户数据存入待响应列表

int elect(CONF *data)
{
	RESPONSELISTHEADNODE *elect1;
	elect1 = &data->readynode;
	RESPONSELISTNODE *B = (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE)), *B1 = elect1->head;
	B->user_call = (USERCALL*)malloc(sizeof(USERCALL));
	B->user_call->user_target = data->dataitem[data->ii].item1;
	B->user_call->user_floor = data->dataitem[data->ii].item2;
	B->user_call->call_time = data->dataitem[data->ii].item3;

	if (data->dataitem[data->ii].item2 > data->dataitem[data->ii].item1)
		B->user_call->call_type = 'U';
	else B->user_call->call_type = 'D';

	B->next_node = NULL;
	while (elect1->list_num > 0 && B1->next_node != NULL)B1 = B1->next_node;
	elect1->tail = B1;
	if (elect1->list_num == 0)  elect1->head = elect1->tail = B;//结构体为空
	else
	{
		elect1->tail->next_node = B;
		elect1->tail = B;
	}
	elect1->list_num++;
	data->ii++;
	return 0;
}

//函数功能:将一个用户数据从待响应列表存入电梯服务列表的尾部


int  ftol1(CONF *data)
{
	SERVELISTNODE *slnode ;
	SERVELISTNODE *slnode2=NULL;
	slnode = data->elevator->serve_list;
	while (data->elevator->serve_list != NULL)
	{
		slnode2 = data->elevator->serve_list;
		data->elevator->serve_list = data->elevator->serve_list->next_node;
	}
	data->elevator->serve_list = (SERVELISTNODE *)malloc(sizeof(SERVELISTNODE));
	data->elevator->serve_list->user_call = data->readynode.head->user_call;
	data->elevator->serve_list->next_node = NULL;
	int floor = data->readynode.head->user_call->user_floor;
	data->readynode.head = data->readynode.head->next_node;
	data->readynode.list_num--;
	if (floor == data->elevator->current_floor)
		data->elevator->serve_list->serve_state = 'E';

	else data->elevator->serve_list->serve_state = 'P';

	return 0;
}


//函数功能:将一个用户数据从待响应列表存入电梯服务列表的尾部


int ftol2(ResponseListNode *node, CONF *data, int state)
{
	SERVELISTNODE *slnode = data->elevator->serve_list, *slnode2 = data->elevator->serve_list;
	while (data->elevator->serve_list != NULL)
	{
		slnode2 = data->elevator->serve_list;
		data->elevator->serve_list = data->elevator->serve_list->next_node;
	}
	data->elevator->serve_list = (SERVELISTNODE *)malloc(sizeof(SERVELISTNODE));
	data->elevator->serve_list->user_call = node->user_call;
	data->elevator->serve_list->next_node = NULL;

	if (state)data->elevator->serve_list->serve_state = 'E';
	else data->elevator->serve_list->serve_state = 'P';
	return 0;
}

//函数功能:将一个用户数据从待响应列表存删除

int delete1(CONF *data, RESPONSELISTNODE *del)
{
	data->readynode.list_num--;
	int i = 0, j;
	RESPONSELISTNODE *B = data->readynode.head;
	data->readynode.head = data->readynode.head->next_node;
	free(del);
	return 0;
}

//函数功能:将一个用户数据从待响应列表存删除


int delete2(CONF *data, SERVELISTNODE *del)
{
	data->leng--;
	int i = 0, j;
	SERVELISTNODE *B = data->elevator->serve_list;
	data->elevator->serve_list = B->next_node;
	free(del);
	return 0;
}

