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
	//ͬ��
	virtual void synchronization(bool &waitFlag1, bool &waitFlag2) = 0;
	//��ȡʱ��
	virtual CString GetTime() = 0;
	//����ͬ��״̬
	virtual void reSetWaitFlag(bool &flag1, bool &flag2) = 0;
	//��ȡjson�ļ���
	virtual std::string getFileName() = 0;
	//����Ԥ��
	virtual int SaveToFile(std::string savePath) = 0;
};
