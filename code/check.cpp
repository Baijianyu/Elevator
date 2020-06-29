#include"stdafx.h"
#include"data.h"
#include"response.h"
#include"check.h"

//函数功能:检查是否可以可以同时响应别的用户指令


int checkinstruct(CONF *data)
{
	int floor = data->elevator->current_floor;
	char state = data->elevator->run_state;
	RESPONSELISTHEADNODE node = data->readynode;
	RESPONSELISTNODE  *A = node.head;
	int i;
	switch (state)
	{
	case 'U'://上升状态 
		for (i = 0; i < node.list_num && A != NULL; i++)//遍历待响应指令列表
		{
			if (floor < A->user_call->user_floor && A->user_call->user_floor <  A->user_call->user_target)
			{
				ftol2(A, data, 0);

				delete1(data,A);
			}
			A = A->next_node;
		}
		break;
	case 'D'://下降状态 
		for (i = 0; i < node.list_num&&A != NULL; i++)//遍历待响应指令列表
		{
			if (floor > A->user_call->user_floor && A->user_call->user_floor >  A->user_call->user_target)
			{
				ftol2(A, data, 0);
				delete1(data, A);
			}
			A = A->next_node;
		}
		break;
	case 'S'://停止状态 
		if (data->elevator->serve_list->user_call->user_target > floor)//遍历待响应指令列表
		{
			for (i = 0; i < node.list_num && A != NULL; i++)
			{
				if (A->user_call->user_floor >= floor && A->user_call->user_floor < A->user_call->user_target)
				{
					ftol2(A, data, floor == A->user_call->user_floor);
					delete1(data, A);
				}
				A = A->next_node;
			}
		}
		else
		{
			for (i = 0; i < node.list_num && A != NULL; i++)//遍历待响应指令列表
			{
				if (A->user_call->user_floor <= floor && A->user_call->user_floor >A->user_call->user_target)
				{
					ftol2(A, data, floor == A->user_call->user_floor);
					delete1(data, A);
				}
				A = A->next_node;
			}
		}
	}
	return 0;
}
