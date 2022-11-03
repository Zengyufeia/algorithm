#pragma once
#include "FAcNode.h"
class UAcTrie
{
public:
	FAcNode Root;

	TArray<FString>Pattern;
	UAcTrie()
	{
		FString Tmp = FString(TEXT("apple"));
		Pattern.Add(Tmp);
		FString Tmp2 = FString(TEXT("day"));
		Pattern.Add(Tmp2);
		FString Tmp3 = FString(TEXT("damn"));
		Pattern.Add(Tmp3);
		FString Tmp4 = FString(TEXT("action"));
		Pattern.Add(Tmp4);
		FString Tmp5 = FString(TEXT("happy"));
		Pattern.Add(Tmp5);

	}
	
};
