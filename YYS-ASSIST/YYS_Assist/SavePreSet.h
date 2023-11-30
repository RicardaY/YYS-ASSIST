#pragma once
#include "Game.h"
#include<vector>
#include<any>
class SavePreSet
{
public:
	SavePreSet();
	~SavePreSet();
	CStringArray preSetList, readList1[14], readList2[14], globalArray;
	CString IntToStr(int num);
	int SaveToFile(Game *game, std::string savePath);
	int ReadLine(std::vector<std::any> &line, unsigned int lineId, std::string filePath);
};
