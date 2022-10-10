#include"AC.h"
AcNode* creatTrieNode()
{
	AcNode* Node = new AcNode;
	if (Node == NULL)
	{
		cout << "CreatError" << endl;
		return NULL;
	}
	for (int i = 0; i < 26; i++)
	{
		Node->next[i] = NULL;
	}
	return Node;

}

void Insert(AcNode* root, string s)
{
	int i;
	int index = 0;
	AcNode* Tmp = root;
	if (root == NULL || s.size() == 0)
	{
		cout << "error" << endl;
		return;
	}

	for (i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			index = s[i] - 'a';
		}
		else
		{
			return;
		}

		while (Tmp->next[index] != NULL)
		{
			Tmp = Tmp->next[index];
		}
		Tmp->next[index] = creatTrieNode();
		if (Tmp->next[index] == NULL)
		{
			cout << "Error" << endl;
			return;
		}
		Tmp = Tmp->next[index];
	}
	Tmp->exist.push_back(s.size());//��¼���ʽ����ĳ���
}

//�������������BFS
void getFail(AcNode* root)
{
	queue<AcNode*>q;
	for (int i = 0; i < 26; i++)//���ڶ������г����˵���ĸ�ӽ�����
	{
		if (root->next[i] != NULL)
		{
			root->next[i]->fail = root;
			q.push(root->next[i]);
		}

	}
	//fail[now]    ->��ǰ�ڵ�now��ʧ��ָ��ָ��ĵط�	
	//tire[now][i]->��һ����ĸΪi + 'a'�Ľڵ���±�Ϊtire[now][i]
	while (!q.empty())
	{
		AcNode* now = q.front();
		AcNode* y, * fafail;
		root->fail = NULL;
		q.pop();//�鿴��һ����ĸ��������״̬
		for (int i = 0; i < 26; i++)
		{
			if (now->next[i])
			{
				y = now->next[i];//�������
				fafail = now->fail;//���ڵ��failָ��
				while (fafail != NULL && fafail->next[i] == NULL)//�������������1.�Ҳ�����fafailָ��root��Ϊ�գ�2.�ҵ��ˣ���fafail�е�i�����Ӿ�����
				{
					fafail = fafail->fail;
				}
				if (fafail == NULL)
				{
					y->fail = root;
				}
				else
				{
					y->fail = fafail->next[i];
				}


				if (y->fail->exist.size())//exist���м�¼˵������ڵ��е���
				{
					for (int i = 0; i < y->fail->exist.size(); i++)
					{
						y->exist.push_back(y->fail->exist[i]);
					}
				}
				q.push(y);
			}

		}

	}

}



void query(AcNode* root, string T)
{
	AcNode* tmp = root;
	for (int i = 0; i < T.size(); i++)
	{
		int index = T[i] - 'a';
		while (tmp->next[index] == NULL && tmp->fail != NULL)//��������û�и���ĸ������failָ�벻ָ��root��ʱ��

		{
			tmp = tmp->fail;
		}
		if (tmp->next[index])//����ҵ��˶������������ĸ
		{
			tmp = tmp->next[index];
		}
		else
		{
			continue;//ͣ����root
		}
		if (tmp->exist.size())
		{

			for (int j = 0; j < tmp->exist.size(); j++)//�������е���
			{
				int length = tmp->exist[j];

				cout << "���ʵ���ʼλ��:" << endl;
				cout << T[i - length + 1] << endl;
			}
		}
	}
}

