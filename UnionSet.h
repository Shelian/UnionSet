#pragma once
#include <iostream>
using namespace std;

#pragma once
#ifndef __UNION_FIND_SET_H__
#define __UNION_FIND_SET_H__
#include <assert.h>

class UnionFindSet
{
public:
	UnionFindSet(int size);
	//void Union(int root1, int root2);
	void Union(int child1, int child2);//合并child1与child2
	size_t FindRoot(int child);//寻找child的根节点
	void Print()const;
protected:
	int* _set;
	size_t _size;
};

UnionFindSet::UnionFindSet(int size) :_set(new int[size]), _size(size)
{
	//初始化
	for (size_t i = 0; i < size; ++i)
	{
		this->_set[i] = -1;
	}
}

void UnionFindSet::Union(int child1, int child2)
{
	size_t root1 = FindRoot(child1);
	size_t root2 = FindRoot(child2);

	if (root1 != root2)
	{
		if (_set[root1] < _set[root2])
		{
			_set[root2] += _set[root1];
			_set[root1] = root2;
		}
		else
		{
			_set[root1] += _set[root2];
			_set[root2] = root1;
		}
	}
}



void UnionFindSet::Union(int child1, int child2)
{
	size_t root1 = FindRoot(child1);
	size_t root2 = FindRoot(child2);
	assert(_set[root1] < 0);
	assert(_set[root2] < 0);//并查集出现错误
	//如果root1 == root2，两个已经属于同一个集合，已不需要合并
	if (root1 != root2)
	{
		//root1的结点比root2的结点多，将2并入1
		if (_set[root1] <= _set[root2])
		{
			_set[root1] += _set[root2];
			_set[root2] = root1;
		}
		else//将1并入2
		{
			_set[root2] += _set[root1];
			_set[root1] = root2;
		}
	}
}

//需要在外面寻找root
//void UnionFindSet::Union(int root1, int root2)
//{
//	assert(_set[root1] < 0);
//	assert(_set[root2] < 0);//并查集出现错误
//	//如果root1 == root2，两个已经属于同一个集合，已不需要合并
//	if (root1 != root2)
//	{
//		//root1的结点比root2的结点多，将2并入1
//		if (_set[root1] <= _set[root2])
//		{
//			_set[root1] += _set[root2];
//			_set[root2] = root1;
//		}
//		else//将1并入2
//		{
//			_set[root2] += _set[root1];
//			_set[root1] = root2;
//		}
//	}
//}

size_t UnionFindSet::FindRoot(int child)
{
	int root = child;
	while (_set[root] >= 0)
	{
		root = _set[root];
	}
	return root;
}

size_t UnionFindSet::FindRoot(int child)
{
	int root = child;
	while (this->_set[root] >= 0)
	{
		root = this->_set[root];
	}
	return root;
}

void UnionFindSet::Print()const
{
	for (size_t i = 0; i < this->_size; ++i)
	{
		cout << this->_set[i] << " ";
	}
	cout << endl;
}

void testUnion()
{
	UnionFindSet ufs(10);
	ufs.Union(0, 6);
	ufs.Union(0, 7);
	ufs.Union(0, 8);
	ufs.Union(1, 4);
	ufs.Union(1, 9);
	ufs.Union(2, 3);
	ufs.Union(2, 5);
	ufs.Print();
	ufs.Union(4, 8);
	ufs.Print();
}

#endif /*__UNION_FIND_SET_H__*/
int Union(int n,int m,int **a)
{
	int *arr = new int[n];
	for (int i = 0; i < n;i++)
	{
		arr[i] = -1;
	}

	int count = 0;

	for (int j = 0; j < m; j++)
	{
		int m = a[j][0];
		int n = a[j][1];
		arr[m]--;
		arr[n] = m;
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			count++;
	}

	return count;
}

void test()
{
	int r[7][2] = { { 0, 6 }, { 0, 7 }, { 0, 8 }, { 1, 4 }, { 1, 9 }, { 2, 3 }, {2,5} };
	int *arr = new int[9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = -1;
	}

	int count = 0;

	for (int j = 0; j < 7; j++)
	{
		int m = r[j][0];
		int n = r[j][1];
		arr[m]--;
		arr[n] = m;
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] < 0)
			count++;
	}
	cout <<count<<endl;

	int x = 1;
	int y = 6;
	
	int ret = arr[6];
	while (arr[ret]>0)
	{
		if (arr[ret] < 0)
		{
			break;
		}
		else
			ret = arr[ret];
	}
	y = ret;
		if (arr[x] < 0)
		{
			arr[y] += arr[x];
			arr[x] = y;
		}
		else
		{
			arr[y]++;
			arr[x] = y;
		}
		count = 0;
		for (int i = 0; i < 9; i++)
		{
			if (arr[i] < 0)
				count++;
		}

	cout << count << endl;
}
