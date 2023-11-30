#pragma once
#include<string>
class Game
{
public:
	virtual void log(CString logMsg) = 0;
	virtual void setThreadPauseState(bool state) = 0;
	virtual bool getThreadPauseState() = 0;	
	virtual void setThreadStartState(bool state) = 0;
	virtual bool getThreadStartState() = 0;
	virtual void setThreadStopState(bool state) = 0;
	virtual bool getThreadStopState() = 0;
	//同步
	virtual void synchronization(bool &waitFlag1, bool &waitFlag2) = 0;
	//获取时间
	virtual CString GetTime() = 0;
	//重置同步状态
	virtual void reSetWaitFlag(bool &flag1, bool &flag2) = 0;
	//获取json文件名
	virtual std::string getFileName() = 0;
	//保存预设
	virtual int SaveToFile(std::string savePath) = 0;
};
