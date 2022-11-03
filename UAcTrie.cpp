#include "UAcTrie.h"
int main()
{
	UAcTrie A;
	for (int32 I = 0; I < A.Pattern.Num(); I++)
	{
		A.Root.Insert(A.Root, A.Pattern[I]);

	}
	A.Root.BuildFail(A.Root);

	FString T = FString(TEXT("sheisveryhappybecauseshehasanappletoday"));
	A.Root.Query(A.Root, T);
	return 0;
}