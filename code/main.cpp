#include "stdafx.h"
#include"data.h"
#include"loadfile.h"
#include"view.h"
#include"conf.h"
#include"main.h"
#include"check.h"
#include"response.h"
#include"view.h"
#include"change.h"

int run(int argc, char* argv[]) {
	CONF *data = (CONF *)malloc(sizeof(CONF));
	fillform(data);
	system("生成文件.exe");
	fileread(data);
	while (data->leng)
	{
		while (data->dataitem[data->ii].item3 == data->time)//到达发送指令的时刻 
			elect(data);//读入一个用户指令到待响应区 
		if (data->elevator->run_state != 'S')//如果电梯目前停止 
			checkinstruct(data);//检验可以响应的指令 
		else if (data->readynode.list_num > 0 && data->elevator->serve_list == NULL)
		{
			ftol1(data);//将一个用户数据从待响应列表的头部存入电梯服务列表的尾部  
			checkinstruct(data);	//检验可以响应别的指令 
		}
		change(data);//改变电梯为下一秒的运行状态 
		view(data);//将电梯状态显示在屏幕上 
		data->time++;
		printf("电梯在%d楼，状态是%c，时间是%d\n", data->elevator->current_floor, data->elevator->run_state, data->time);
		Sleep(1000);
		if (data->time > 80)break;
		
	}
	printf("电梯成功完成任务，共用时%d秒 \n", data->time);
	system("pause");
	return 0;
}





