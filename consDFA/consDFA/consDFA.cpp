// consDFA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
״̬ת��ʽ���죺
	current������ǰ״̬
	next������һ״̬
*/
class TransTile
{
public:
	char current;
	char next;
	char input;
	TransTile(char C,char I,char Ne){
		current = C;
		next = Ne;
		input = I;
	}
};

class DFA
{
public:
	//����״̬������Ԫ��
	string States;
	char startStates;
	string finalStates;
	string Alphabets;
	vector <TransTile> Tile;
	
	DFA(){
		init();
	}
	void init()
	{
		cout << "��������״̬��S��" << endl;
		cin >> States;
		cout << "�����ַ���A��" << endl;
		cin >> Alphabets;
		cout << "����״̬ת��ʽ����ʽΪ��״̬-�����ַ�-��һ״̬������#��������" << endl;
		cout << "���磺1a1 \n 1a0 \n 2a1 \n #" << endl;
		int h = 0;

		//while (cin>>input){
		//	TransTile transval(input[0], input[1], input[2]);
		//	Tile.push_back(transval);
		//}
		while(true){
			char input[4];
			cin>>input;
			if(strcmp(input,"#")==0)
				break;
			TransTile transval(input[0],input[1],input[2]);
			Tile.push_back(transval);
		}
		cout << "�����̬��" << endl;
		cin >> startStates;
		cout << "������̬��" << endl;
		cin >> finalStates;
	}
	//����ת����
	char move(char P,char I){
		for (int i = 0; i < Tile.size(); i++){
			if (Tile[i].current == P&&Tile[i].input == I){
				return Tile[i].next;
			}	
		}
		return 'E';
	}
	//ʶ���ַ�������
	void recognition(){
		string str;
		cout << "������Ҫʶ����ַ�����" << endl;
		cin >> str;
		int i = 0;
		char current = startStates;
		while (i < str.length()){
			current = move(current, str[i]);
			if (current == 'E'){
				break;
			}
			i++;
		}
		if (finalStates.find(current) != finalStates.npos){
			cout << "���Զ���ʶ����ַ�����" << endl;
		}
		else
		{
			cout << "���Զ�������ʶ����ַ�����" << endl;
		}
	}
};

int main(){
	DFA dfa;	
	bool tag;

	while(1){
		cout<<"����Ҫ��������������1��������0��"<<endl;
		cin>>tag;
		if(tag){
			dfa.recognition();
		}else
			break;

	}
	return 0;
}
