#pragma once
#include "pch.h"
#include "SavePreSet.h"
#include"snow.h"
SavePreSet *sPreset;
extern snow * g_sn;
SavePreSet::SavePreSet() {
	sPreset = this;
}
SavePreSet::~SavePreSet() {
}
CString SavePreSet::IntToStr(int num) {
	return (CString)std::to_wstring(num).c_str();
}
int SavePreSet::SaveToFile(Game *game, std::string savePath)
{
	game->SaveToFile(savePath);
	return 1;
}
int SavePreSet::ReadLine(std::vector<std::any> &line, unsigned int lineId, std::string filePath) {
	std::vector<std::vector<std::any>> mixall;
	if (!g_sn->ReadJson(mixall, filePath) || mixall.size() <= lineId) {
		return 0;
	}
	for (unsigned int i = 1; i < mixall[lineId].size(); i++) {
		line.push_back(mixall[lineId][i]);
	}
	return 1;
}

