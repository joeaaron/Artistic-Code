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
	virtual void AddMainboard() { m_computer->Add("主板：微星B460M PRO VDH WIFI"); }
	virtual void AddMemory() { m_computer->Add("内存：金士顿骇客神条2666 8Gx2"); }
	virtual void AddGpu() { m_computer->Add("显卡:微星万图师3X RTX3070"); }
	virtual void AddStorage() { m_computer->Add("固态：西数SN550 500G"); }
	virtual void AddPowersupply() { m_computer->Add("电源：九州风神DQ650-M-V2L"); }
	virtual void AddRadiator() { m_computer->Add("散热器：九州风神玄冰400蓝光版"); }
	virtual void AddCase() { m_computer->Add("机箱：先马平头哥M3"); }
	virtual Computer *GetComputer() { return m_computer; }

private:
	Computer *m_computer;
};

class Builder11199 : public Builder
{
public:
	Builder11199() : m_computer(nullptr) {}
	virtual void BuildComputer() { m_computer = new Computer; m_computer->SetPrice(11199); }
	virtual void AddCpu() { m_computer->Add("CPU:AMD锐龙3900X散片"); }
	virtual void AddMainboard() { m_computer->Add("主板：微星B550 CARBON WIFI"); }
	virtual void AddMemory() { m_computer->Add("内存：金士顿骇客神条RGB3200 8Gx2"); }
	virtual void AddGpu() { m_computer->Add("显卡:微星RTX2070Super魔龙"); }
	virtual void AddStorage() { m_computer->Add("固态：西数黑盘SN750 500G"); }
	virtual void AddPowersupply() { m_computer->Add("电源：九州风神DQ850"); }
	virtual void AddRadiator() { m_computer->Add("散热器：九州风神堡垒360EX RGB"); }
	virtual void AddCase() { m_computer->Add("机箱：九州风神CL500"); }
	virtual Computer *GetComputer() { return m_computer; }

private:
	Computer *m_computer;
};