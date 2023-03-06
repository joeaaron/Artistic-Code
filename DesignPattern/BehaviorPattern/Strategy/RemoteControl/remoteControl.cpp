#include<iostream>
#include<string>
#include<map>

using namespace std;

#define SENDENDFLAG  0x0D   //控制指令最后一个字节    回车
#define OK "ok";

/*
模拟TCP客户端，其中有封装好的发送命令的接口和接收数据的接口
*/
class TcpClient 
{
public:
	//发送命令
	int SendCMD(string cmd)
	{
		cout << "发送命令：" << cmd << endl;
		return 0;
	}
	//接收数据
	int RecvData()
	{
		cout << "接收数据：" << endl;
		return 0;
	}
};
TcpClient tcpCli;

/*
定义命令策略接口
抽象类不能创建对象，只能创建指针对象
*/
class ICommandStrategy
{
public:
	virtual string Command() = 0;
};

//启动命令
class StartCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //地址码      
		string strCMD = "<" + Address;    //命令字
		strCMD += "/1_111";              //命令码_操作
		strCMD += SENDENDFLAG;
		return strCMD;
	}
};

//关闭命令
class CloseCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //地址码      
		string strCMD = "<" + Address;    //命令字
		strCMD += "/2_222";              //命令码_操作
		strCMD += SENDENDFLAG;
		return strCMD;
	}

};

//查询命令
class SearchCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //地址码      
		string strCMD = "<" + Address;    //命令字
		strCMD += "/3_333";              //命令码_操作
		strCMD += SENDENDFLAG;
		return strCMD;
	}

};

//策略接口
class Character
{
public:
	void setCommand(ICommandStrategy * comStra)  //创建命令对象
	{
		if (comStra == nullptr)
		{
			//创建
			return;
		}
		else
		{
			this->pCom = comStra;
		}
	}
	void TCPSend()
	{
		if (this->pCom == nullptr)
		{
			return;
		}
		else
		{
			string com = this->pCom->Command();  //生成命令
			tcpClient->SendCMD(com); //发送命令

		}

	}
public:
	ICommandStrategy *pCom;
	TcpClient *tcpClient;
};

//工厂方法
class ServiceFactory {
public:
	ServiceFactory()
	{
		mapStrategy.insert(pair<string, ICommandStrategy*>("1", new StartCmd));
		mapStrategy.insert(pair<string, ICommandStrategy*>("2", new CloseCmd));
		mapStrategy.insert(pair<string, ICommandStrategy*>("3", new SearchCmd));
	}
	ICommandStrategy* getComService(string comType)
	{
		if (mapStrategy.count(comType) == 0)
		{
			cout << "命令无效！" << endl;
			return nullptr;
		}
		else
		{
			return mapStrategy.at(comType);
		}
	}
private:
	map<string, ICommandStrategy*> mapStrategy;

};

//优化后的接口内容如下
string OnUpdate(string inJson)
{
	Character* cha = new Character;
	ServiceFactory fac;
	ICommandStrategy* Str = fac.getComService(inJson);
	if (Str == nullptr)
	{
		return "FALSE";
	}
	else
	{
		cha->setCommand(Str);
		cha->TCPSend();
	}

	delete Str;
	delete cha;
	return OK;
}

//模拟显控停止指令
void test02()
{
	string str = "2";
	OnUpdate(str);

}

int main()
{
	test02();
	
	return 0;
}
