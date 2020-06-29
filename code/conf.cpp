#include "stdafx.h"
#include "data.h"
 
//函数功能：初始化参数
int fillform(CONF *data) {
	data->time = 0;
	data->elevator = (ELEVATORSTATE *)malloc(sizeof(ELEVATORSTATE));
	data->elevator->current_floor = 1;
	data->elevator->run_state = 'S';
	data->elevator->serve_list = NULL;
	data->readynode.list_num = 0;
	data->elevator->serve_list = NULL;
	data->ii = 0;
	data->filename = "文本文件.txt";
	return 0;
}