#include"AC.h"
int main()
{
    int n;
    string s,T;
    cin >> n;
    AcNode* root = creatTrieNode();
    for (int i = 0; i < n; i++) {
        cin >> s;
        Insert(root,s);
    }
    getFail(root);
    cin >> T;
    query(root,T);
    return 0;
}