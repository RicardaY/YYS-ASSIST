#pragma once
#include "pch.h"
#include "snow.h"
#include<random>
#include<json/json.h>
#include<fstream>


using namespace Json;
snow::snow() {
	CoInitializeEx(NULL, 0);
}
snow::~snow() {
	CoUninitialize();
}
//���������
long snow::random(long rangeA, long rangeB) {
	static std::random_device rd;	//��ȡ���������
	static std::mt19937 gen(rd());	//ʹ��Mersenne Twister�㷨���������
	std::uniform_int_distribution<int> dist(rangeA, rangeB);	//����[rangeA, rangeB]���������� 
	return dist(gen);
}
//����ַ���
int snow::SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString)
{
	rArrString.RemoveAll();
	CString szStr = lpszStr;
	szStr.TrimLeft();
	szStr.TrimRight();
	if (szStr.GetLength() == 0)
	{
		return 0;
	}
	CString szSplit = lpszSplit;
	if (szSplit.GetLength() == 0)
	{
		rArrString.Add(szStr);
		return 1;
	}
	CString s;
	int n;
	do
	{
		n = szStr.Find(szSplit);
		if (n > 0)
		{
			rArrString.Add(szStr.Left(n));
			szStr = szStr.Right(szStr.GetLength() - n - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else if (n == 0)
		{
			if (bAllowNullString)
			{
				rArrString.Add(_T(""));
			}
			szStr = szStr.Right(szStr.GetLength() - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else
		{
			if ((szStr.GetLength() > 0) || bAllowNullString)
			{
				rArrString.Add(szStr);
			}
			break;
		}
	} while (1);
	return (int)rArrString.GetSize();
}
//�ȽϺ��� CPoint
bool snow::comparePoints(const CPoint& point1, const CPoint& point2)
{
	return point1.x <= point2.x && abs(point1.y - point2.y) < 100;
}

// ������
void snow::sortPoints(CArray<CPoint, CPoint>& points) {
	// ʹ��std::sort��CArray�еĵ��������
	std::sort(points.GetData(), points.GetData() + points.GetSize(), comparePoints);
}
//������¼� click_x,click_y:����Ӿ������
void snow::MoveClick(int click_x, int click_y) {
	MoveTo(click_x, click_y);
	Sleep(100);
	LeftClick();
	Sleep(50);
	return;
}
//����ƶ�
void snow::DragMouse(int start_x, int start_y, int end_x, int end_y) {
	MoveTo(start_x, start_y);
	Sleep(200);
	LeftDown();
	Sleep(200);
	MoveTo(end_x, end_y);
	Sleep(200);
	LeftUp();
	Sleep(500);
	return;
}
//�漴ƫ�����꣬��ֹ��Ϸ��Ҽ��
CPoint snow::RandomOffsetPos(int px, int py, int dx_min, int dx_max, int dy_min, int dy_max) {
	CPoint newPos;
	newPos.x = px + random(dx_min, dx_max), newPos.y = py + random(dy_min, dy_max);
	return newPos;
}
//��ȡJson�ļ�
bool snow::ReadJson(std::vector<std::vector<std::any>> &mixall, std::string filePath) {
	std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

	Reader rd;
	Value root;
	rd.parse(ifs, root);

	//read
	std::ifstream  infile(filePath.c_str());
	if (!infile.good()) {
		infile.close();
		return false;
	}
	std::vector<std::any> subvec;
	if (root.isArray()) {
		for (unsigned int i = 0; i < root.size(); i++) {
			for (unsigned int j = 0; j < root[i].size(); j++) {
				if (root[i][j].isString()) {
					subvec.push_back((std::string)root[i][j].asString());
				}
				else if (root[i][j].isInt()) {
					subvec.push_back((int)root[i][j].asInt());
				}
			}
			mixall.push_back(subvec);
			subvec.clear();
		}
	}
	infile.close();
	ifs.close();
	return true;
}
//д��Json�ļ�
bool snow::WriteJson(std::vector<std::vector<std::any>> mixall, std::string filePath) {
	Value root, subArray[20];
	for (unsigned int i = 0; i < mixall.size(); i++) {
		for (unsigned int j = 0; j < mixall[i].size(); j++) {
			if (mixall[i][j].type() == typeid(const char*)) {
				subArray[i].append(std::any_cast<const char*>(mixall[i][j]));
			}
			else if (mixall[i][j].type() == typeid(std::string)) {
				subArray[i].append(std::any_cast<std::string>(mixall[i][j]));
			}
			else if (mixall[i][j].type() == typeid(int)) {
				subArray[i].append(std::any_cast<int>(mixall[i][j]));
			}
		}
		root.append(subArray[i]);
	}
	
	//������������
	StreamWriterBuilder jswBuilder;
	jswBuilder["emitUTF8"] = true;
	std::unique_ptr<StreamWriter>jsWriter(jswBuilder.newStreamWriter());
	//д��json����
	std::fstream fs;
	fs.open(filePath, std::ios::out);
	jsWriter->write(root, &fs);
	fs.close();
	return true;
}