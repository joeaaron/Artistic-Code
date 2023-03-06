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

//���Խӿ�
class Character
{
public:
	void setCommand(ICommandStrategy * comStra)  //�����������
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
	ICommandStrategy* getComService(string comType)
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
