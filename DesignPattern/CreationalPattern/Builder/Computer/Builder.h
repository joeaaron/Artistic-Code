#pragma once
#include "Computer.h"

class Builder {
public:
	virtual void BuildComputer() {}
	virtual void AddCpu() {}
	virtual void AddMainboard() {}
	virtual void AddMemory() {}
	virtual void AddGpu() {}
	virtual void AddStorage() {}
	virtual void AddPowersupply() {}
	virtual void AddRadiator() {}
	virtual void AddCase() {}
	virtual Computer *GetComputer() { return nullptr; }
protected:
	Builder() {}
};

class Builder6666 : public Builder
{
public:
	Builder6666() : m_computer(nullptr) {}
	virtual void BuildComputer() { m_computer = new Computer; m_computer->SetPrice(6666); }
	virtual void AddCpu() { m_computer->Add("CPU:10400F"); }
	virtual void AddMainboard() { m_computer->Add("���壺΢��B460M PRO VDH WIFI"); }
	virtual void AddMemory() { m_computer->Add("�ڴ棺��ʿ�ٺ�������2666 8Gx2"); }
	virtual void AddGpu() { m_computer->Add("�Կ�:΢����ͼʦ3X RTX3070"); }
	virtual void AddStorage() { m_computer->Add("��̬������SN550 500G"); }
	virtual void AddPowersupply() { m_computer->Add("��Դ�����ݷ���DQ650-M-V2L"); }
	virtual void AddRadiator() { m_computer->Add("ɢ���������ݷ�������400�����"); }
	virtual void AddCase() { m_computer->Add("���䣺����ƽͷ��M3"); }
	virtual Computer *GetComputer() { return m_computer; }

private:
	Computer *m_computer;
};

class Builder11199 : public Builder
{
public:
	Builder11199() : m_computer(nullptr) {}
	virtual void BuildComputer() { m_computer = new Computer; m_computer->SetPrice(11199); }
	virtual void AddCpu() { m_computer->Add("CPU:AMD����3900XɢƬ"); }
	virtual void AddMainboard() { m_computer->Add("���壺΢��B550 CARBON WIFI"); }
	virtual void AddMemory() { m_computer->Add("�ڴ棺��ʿ�ٺ�������RGB3200 8Gx2"); }
	virtual void AddGpu() { m_computer->Add("�Կ�:΢��RTX2070Superħ��"); }
	virtual void AddStorage() { m_computer->Add("��̬����������SN750 500G"); }
	virtual void AddPowersupply() { m_computer->Add("��Դ�����ݷ���DQ850"); }
	virtual void AddRadiator() { m_computer->Add("ɢ���������ݷ�����360EX RGB"); }
	virtual void AddCase() { m_computer->Add("���䣺���ݷ���CL500"); }
	virtual Computer *GetComputer() { return m_computer; }

private:
	Computer *m_computer;
};