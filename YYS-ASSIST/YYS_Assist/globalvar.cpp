#pragma once
#include "pch.h"
#include "globalvar.h"
#include<iostream>

bool waitFlag1 = true, waitFlag2 = true;
bool exbonus1 = true, exbonus2 = true;
bool exteamer1 = true, exteamer2 = true;
//�ֿ��ַ
CString g_path = _T("resource");
//�汾��
CString version = _T("�汾��2.4.7");
//�Ƿ���׼����ʶ(���������ж�)
bool readyFlag = TRUE;
//��Ϸ�����һЩ�ļ���
std::string fname1 = "config/game1.json", fname2 = "config/game2.json";
std::string stoken =  "config/token.json";
//�»
CString activityName = _T("���֮��");
CString activitySubName = _T("��������");
CString TiLiName = _T("������");