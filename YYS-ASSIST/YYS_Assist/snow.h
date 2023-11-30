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
	//生成[rangeA, rangeB]区间的随机数 
	long random(long rangeA, long rangeB);;
	//拆分字符串 lpszStr : 要拆的字符串,  lpszSplit : 根据lpszSplit符号拆分,  rArrString : 结果集,   bAllowNullString : 是否允许空格
	int SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString = false);
	//比较函数 CPoint
	static bool comparePoints(const CPoint& point1, const CPoint& point2);
	// 排序函数 CPoint
	void sortPoints(CArray<CPoint, CPoint>& points);
	//鼠标点击整合-[移动+点击]
	void MoveClick(int click_x, int click_y);
	//鼠标拖拽移动
	void DragMouse(int start_x, int start_y, int end_x, int end_y);
	//随即偏移坐标，防止游戏外挂检测  (从左往右，从上往下偏移,可为负值)
	CPoint RandomOffsetPos(int px, int py, int dx_min = 1, int dx_max = 5, int dy_min = 1, int dy_max = 5);
	//读取Json文件
	bool ReadJson(std::vector<std::vector<std::any>> &mixall, std::string filePath = "test.json");
	//写入Json文件
	bool WriteJson(std::vector<std::vector<std::any>> mixall, std::string filePath = "test.json");
};

