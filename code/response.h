#pragma once
int elect(CONF *data);
int  ftol1(CONF *data);
int  ftol2(ResponseListNode *node, CONF *data, int state);
int delete1(CONF *data, RESPONSELISTNODE *del);
int delete2(CONF *data, SERVELISTNODE *del);
