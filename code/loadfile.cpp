#include "stdafx.h"
#include"data.h"
#include"loadfile.h"
//函数功能：排序
int cmp(const void *a, const void *b) {
	return ((int*)a)[2] - ((int*)b)[2];
}

//函数功能：将文件中的数据导入
int fileread(CONF *data) {
	FILE *fp;
	fp = fopen(data->filename, "r");
	fscanf(fp, "%d", &data->leng);
	data->dataitem = (DATAITEM *)malloc(sizeof(DATAITEM)* data->leng);
	int num;
	for (num = 0; num != data->leng; num++)
		fscanf(fp, "%d,%d,%d", &data->dataitem[num].item1, &data->dataitem[num].item2, &data->dataitem[num].item3);

	printf("下面是电梯需要服务的列表\n");
	Sleep(1000);
	printf("一共有%d人等待电梯服务\n", data->leng);
	Sleep(1000);
	printf("他们所在楼层，目标楼层，和发出指令的时刻如下\n");
	Sleep(1000);
	qsort(data->dataitem, data->leng, sizeof(DATAITEM), cmp);
	for (num = 0; num < data->leng; num++) {
		printf("%d %d %d\n", data->dataitem[num].item1, data->dataitem[num].item2, data->dataitem[num].item3);
		Sleep(1000);
	}
	fclose(fp);
	return 0;

}
























