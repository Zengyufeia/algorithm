#pragma once

struct FAcNode
{
   FAcNode* Next[26];
   FAcNode* Fail;
   TArray<int32>Exist;;

public:
   FAcNode* CreatTrieNode()
   {
      FAcNode* Node = new FAcNode;
      if (Node == NULL)
      {
         UE_LOG(LogTemp, Warning, TEXT("CreatError"));
         return NULL;
      }
      for (int32 I = 0; I < 26; I++)
      {
         Node->Next[I] = NULL;
      }
      return Node;

   }


   void Insert(FAcNode& Root, FString S)
   {
      
      int32 Index = 0;
      FAcNode* Tmp = &Root;

      for (int32 I = 0; I < S.Len(); I++)
      {
         if ('a' <= S[I] && S[I] <= 'z')
         {
            Index = S[I] - 'a';
         }
         else
         {
            return;
         }

         if (Tmp->Next[Index] != NULL)
         {
            Tmp->Next[Index] = CreatTrieNode();
         }
         
         Tmp = Tmp->Next[Index];

      }

      Tmp->Exist.Add(S.Len());
   }

   void BuildFail(FAcNode& Root)
   {
      TQueue<FAcNode*>Q;
      Root.Fail = NULL;

      for (int32 I = 0; I < 26; I++)//���ڶ������г����˵���ĸ�ӽ�����
      {
         if (Root.Next[I] != NULL)
         {
            Root.Next[I]->Fail = &Root;
            Q.Enqueue(Root.Next[I]);
         }

      }



      while (!Q.IsEmpty())
      {
         FAcNode* Now = *Q.Peek();
         FAcNode* Y, * Fafail;
         Root.Fail = NULL;
         Q.Pop();//�鿴��һ����ĸ��������״̬
         for (int32 I = 0; I < 26; I++)
         {
            if (Now->Next[I])
            {
               Y = Now->Next[I];//�������
               Fafail = Now->Fail;//���ڵ��failָ��


               while (Fafail != NULL && Fafail->Next[I] == NULL)//�������������1.�Ҳ�����fafailָ��root��Ϊ�գ�2.�ҵ��ˣ���fafail�е�i�����Ӿ�����
               {
                  Fafail = Fafail->Fail;
               }


               if (Fafail == NULL)
               {
                  Y->Fail = &Root;
               }
               else
               {
                  Y->Fail = Fafail->Next[I];
               }


               if (Y->Fail->Exist.Num())//exist���м�¼˵������ڵ��е���
               {

                  for (int32 J = 0; J < Y->Fail->Exist.Num(); J++)
                  {
                     Y->Exist.Add(Y->Fail->Exist[J]);
                  }

               }
               Q.Enqueue(Y);
            }

         }

      }

   }

   void Query(FAcNode& Root, FString T)
   {
      FAcNode* Tmp = &Root;

      for (int32 I = 0; I < T.Len(); I++)
      {
         int32 Index = T[I] - 'a';
         while (Tmp->Next[Index] == NULL && Tmp->Fail != NULL)//��������û�и���ĸ������failָ�벻ָ��root��ʱ��

         {
            Tmp = Tmp->Fail;
         }
         if (Tmp->Next[Index])//����ҵ��˶������������ĸ
         {
            Tmp = Tmp->Next[Index];
         }
         else
         {
            continue;//ͣ����root
         }
         if (Tmp->Exist.Num())
         {


                  for (int32 J = 0; J < (*Tmp).Exist.Num(); J++)//�������е���
                     {
                        int32 Length = (*Tmp).Exist[J];
         
                        UE_LOG(LogTemp, Warning, TEXT("���ʵ���ʼλ��:\n"));
                        UE_LOG(LogTemp, Warning, TEXT("%c\n"), T[I - Length + 1]);
                        UE_LOG(LogTemp, Warning, TEXT("�õ���Ϊ:"));
         
         
                        for (int32 K = 0; K < Length; K++)
                        {
                           UE_LOG(LogTemp, Warning, TEXT("%c\n"), T[I - Length + 1 + K]);
                        }
                        UE_LOG(LogTemp, Warning, TEXT("\n"));
                     }
         }
      }
   }
	
};


