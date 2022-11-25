#include<iostream>
using namespace std;
template<class T>

class SqList {

private:

	T* data;
	int length;
	int capacity;

public:

	SqList()
	{
	    data = NULL;
		length = 0;
		capacity = 0;
	}


	~SqList()
	{
		Destory();
	}


	bool IsEmpty()
	{
		if (length == 0||capacity==0)
			return true;
		else
			return false;
	}


	bool IsFull()
	{
		if (length == capacity)
			return true;
		else
			return false;
	}


	bool PushBack(T a)
	{
		if (capacity == 0)
		{
			data = new T[4];//T*p=new T


			if (!data)
				return false;
			

			capacity = 4;//capacity++;
		}
		else if (IsFull())
		{

			T* tmp = new T[2 * capacity];//capcity+1


			if (tmp == NULL)
				return false;


			for (int i = 0; i < length; i++)
				tmp[i] = data[i];


			delete data;
			data = tmp;
			capacity *= 2;//capacity++;
		}

		data[length] = a;
		length++;
		
		return true;

	}


	bool Insert(int index, T a)
	{
		if (capacity < index)
		{
			return false;
		}
		else
		{
			if (IsFull())
			{
				T*tmp = new T[2 * capacity];
				

				if (tmp == NULL)
					return false;
				

				for (int i = 0; i < length; i++)
					tmp[i] = data[i];


				delete data;
				data = tmp;
                capacity *= 2;//capacity++;
			}
			

			int end=length-1;
			int begin =index -1;
			

			for (end; end>=begin; end--)
				data[end   + 1] = data[end];


			data[begin] = a;
			length++;

			return true;
		}
	}

	bool Delete(int index)
	{
		if (capacity < index)
		{
			return false;
		}
		else
		{
			int begin = index - 1;
			int end = length-1;


			for (begin; begin <= end; begin++)
				data[begin] = data[begin+1];


			length--;


			return true;
        }
	}

	T Search(int i)
	{
		if (i > length)
			exit(-1);
		return data[i-1];
	}

	bool Change(int i,T a)
	{
		if (i > length)
			return false;

		data[i - 1] = a;
		return true;
	}

	void Destory()
	{
		if (data==NULL)
		{
			delete data;
		}
	}

	void Display()
	{
		for (int i = 0; i < length; i++)
			cout << data[i] << " ";
	}
};

