#pragma once
#include "SavePreSet.h"
#include "YYS_AssistDlg.h"
#include "snow.h"
extern bool waitFlag1 , waitFlag2 ;
extern bool exbonus1 , exbonus2 ;
extern bool exteamer1, exteamer2;
//�ֿ��ַ
extern CString g_path;
//���ȫ�ֱ���
extern snow *g_sn;
//�汾��
extern CString version;
//�Ƿ���׼����ʶ(���������ж�)
extern bool readyFlag;
//��Ϸ�����һЩ�ļ���
extern std::string fname1, fname2;
extern std::string stoken;
//��ȡԤ���ļ�
extern SavePreSet *sPreset;
//�»
extern CString activityName;
extern CString activitySubName;
extern CString TiLiName;