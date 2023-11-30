#pragma once
#include<vector>
#include<any>
#include <iostream>
#include <algorithm>
#include<cmath>
#include "obj.h"
class snow: public dmsoft
{
public:
	snow();
	~snow();
	//����[rangeA, rangeB]���������� 
	long random(long rangeA, long rangeB);;
	//����ַ��� lpszStr : Ҫ����ַ���,  lpszSplit : ����lpszSplit���Ų��,  rArrString : �����,   bAllowNullString : �Ƿ�����ո�
	int SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString = false);
	//�ȽϺ��� CPoint
	static bool comparePoints(const CPoint& point1, const CPoint& point2);
	// ������ CPoint
	void sortPoints(CArray<CPoint, CPoint>& points);
	//���������-[�ƶ�+���]
	void MoveClick(int click_x, int click_y);
	//�����ק�ƶ�
	void DragMouse(int start_x, int start_y, int end_x, int end_y);
	//�漴ƫ�����꣬��ֹ��Ϸ��Ҽ��  (�������ң���������ƫ��,��Ϊ��ֵ)
	CPoint RandomOffsetPos(int px, int py, int dx_min = 1, int dx_max = 5, int dy_min = 1, int dy_max = 5);
	//��ȡJson�ļ�
	bool ReadJson(std::vector<std::vector<std::any>> &mixall, std::string filePath = "test.json");
	//д��Json�ļ�
	bool WriteJson(std::vector<std::vector<std::any>> mixall, std::string filePath = "test.json");
};

