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
	Tmp->exist.push_back(s.size());//记录单词结束的长度
}

//广度优先搜索：BFS
void getFail(AcNode* root)
{
	queue<AcNode*>q;
	for (int i = 0; i < 26; i++)//将第二层所有出现了的字母扔进队列
	{
		if (root->next[i] != NULL)
		{
			root->next[i]->fail = root;
			q.push(root->next[i]);
		}

	}
	//fail[now]    ->当前节点now的失败指针指向的地方	
	//tire[now][i]->下一个字母为i + 'a'的节点的下标为tire[now][i]
	while (!q.empty())
	{
		AcNode* now = q.front();
		AcNode* y, * fafail;
		root->fail = NULL;
		q.pop();//查看第一个字母所在字数状态
		for (int i = 0; i < 26; i++)
		{
			if (now->next[i])
			{
				y = now->next[i];//层序遍历
				fafail = now->fail;//父节点的fail指针
				while (fafail != NULL && fafail->next[i] == NULL)//跳出有两种情况1.找不到：fafail指向root既为空，2.找到了，当fafail有第i个儿子就跳出
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


				if (y->fail->exist.size())//exist中有记录说明这个节点有单词
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
		while (tmp->next[index] == NULL && tmp->fail != NULL)//当孩子中没有该字母且它的fail指针不指向root的时候

		{
			tmp = tmp->fail;
		}
		if (tmp->next[index])//如果找到了儿子中有这个字母
		{
			tmp = tmp->next[index];
		}
		else
		{
			continue;//停留在root
		}
		if (tmp->exist.size())
		{

			for (int j = 0; j < tmp->exist.size(); j++)//查找所有单词
			{
				int length = tmp->exist[j];

				cout << "单词的起始位置:" << endl;
				cout << T[i - length + 1] << endl;
			}
		}
	}
}

