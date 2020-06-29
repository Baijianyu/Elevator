#include "stdafx.h"
#include"data.h"
#include"view.h"


//功能描述:将电梯服务列表的数据展示

int view(CONF *data) {
	int num;
	SERVELISTNODE *C = data->elevator->serve_list;
	if (C == NULL)return 0;;

	puts("\n电梯工作状态:");
	for (num = 1; C != NULL; num++)
	{
		printf("电梯中的第%d人，电梯目前状态是%c，从%d层去%d层\n", num, C->serve_state, C->user_call->user_floor, C->user_call->user_target);
		C = C->next_node;
	}
	putchar('\n');
	return 0;
}

