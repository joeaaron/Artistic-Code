#include<iostream>
#include<string>
#include<map>

using namespace std;

#define SENDENDFLAG  0x0D   //����ָ�����һ���ֽ�    �س�
#define OK "ok";

/*
ģ��TCP�ͻ��ˣ������з�װ�õķ�������Ľӿںͽ������ݵĽӿ�
*/
class TcpClient 
{
public:
	//��������
	int SendCMD(string cmd)
	{
		cout << "�������" << cmd << endl;
		return 0;
	}
	//��������
	int RecvData()
	{
		cout << "�������ݣ�" << endl;
		return 0;
	}
};
TcpClient tcpCli;

/*
����������Խӿ�
�����಻�ܴ�������ֻ�ܴ���ָ�����
*/
class ICommandStrategy
{
public:
	virtual string Command() = 0;
};

//��������
class StartCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //��ַ��      
		string strCMD = "<" + Address;    //������
		strCMD += "/1_111";              //������_����
		strCMD += SENDENDFLAG;
		return strCMD;
	}
};

//�ر�����
class CloseCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //��ַ��      
		string strCMD = "<" + Address;    //������
		strCMD += "/2_222";              //������_����
		strCMD += SENDENDFLAG;
		return strCMD;
	}

};

//��ѯ����
class SearchCmd :public ICommandStrategy
{
public:
	virtual string Command()
	{
		string Address = "255";           //��ַ��      
		string strCMD = "<" + Address;    //������
		strCMD += "/3_333";              //������_����
		strCMD += SENDENDFLAG;
		return strCMD;
	}

};

// Context
class Character
{
public:
	void SetCommand(ICommandStrategy * comStra)  //�����������
	{
		if (comStra == nullptr)
		{
			//����
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
			string com = this->pCom->Command();  //��������
			tcpClient->SendCMD(com); //��������
		}

	}
public:
	ICommandStrategy *pCom;
	TcpClient *tcpClient;
};

//��������
class ServiceFactory {
public:
	ServiceFactory()
	{
		mapStrategy.insert(pair<string, ICommandStrategy*>("1", new StartCmd));
		mapStrategy.insert(pair<string, ICommandStrategy*>("2", new CloseCmd));
		mapStrategy.insert(pair<string, ICommandStrategy*>("3", new SearchCmd));
	}
	ICommandStrategy* GetComService(string comType)
	{
		if (mapStrategy.count(comType) == 0)
		{
			cout << "������Ч��" << endl;
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

//�Ż���Ľӿ���������
string OnUpdate(string inJson)
{
	Character* cha = new Character;
	ServiceFactory fac;
	ICommandStrategy* cmd = fac.GetComService(inJson);
	if (cmd == nullptr)
	{
		return "FALSE";
	}
	else
	{
		cha->SetCommand(cmd);
		cha->TCPSend();
	}

	delete cmd;
	delete cha;
	return OK;
}

//ģ���Կ�ָֹͣ��
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
