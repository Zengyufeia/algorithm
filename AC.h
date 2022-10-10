#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct AcNode {
	struct AcNode* next[26];
	struct AcNode* fail;
	vector<int>exist;
}AcNode;

AcNode* creatTrieNode();
void Insert(AcNode* root, string s);
void getFail(AcNode* root);
void query(AcNode* root, string T);


