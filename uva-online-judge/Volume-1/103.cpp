//27382914	103	Stacking Boxes	Accepted	C++11	0.000	2022-04-05 14:00:50
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Box
{
private:
	int _numDimension;
	vector<int> _dimension;

public:
	Box();
	Box(int numDimension, const vector<int> & dimension);
	Box(const Box & other) : _numDimension(other._numDimension),
				 _dimension(other._dimension) {}
	~Box() {}

	Box & operator= (const Box & rhs);
	bool canBeNestedIn(const Box & other) const;	
};

Box::Box()
{
	_numDimension = 0;
}

Box::Box(int numDimension, const vector<int> & dimension) :
	_numDimension(numDimension), _dimension(dimension)
{
	sort(_dimension.begin(), _dimension.end());
}

Box & Box::operator= (const Box & rhs)
{
	if(this == &rhs)
		return *this;
	
	_numDimension = rhs._numDimension;
	_dimension = rhs._dimension;
	return *this;
}

bool Box::canBeNestedIn(const Box & other) const
{
	if(_numDimension != other._numDimension)
		return false;

	for(int i = 0; i < _numDimension; i++)
		if(_dimension[i] >= other._dimension[i])
			return false;
	return true;
}

void buildAdjList(const vector<Box> & boxArr, vector<vector<int> > & adjList);
void getLongestPathDAG(const vector<vector<int> > & adjList, vector<int> & longestPath);
void getTopoOrder(const vector<vector<int> > & adjList, vector<int> & topoOrder);

int main(void)
{
	int numBox, numDimension;
	vector<Box> boxArr;
	vector<vector<int> > adjList;
	vector<int> longestNestedSeq;

	while(scanf("%d %d", &numBox, &numDimension) > 0)
	{
		boxArr.clear();
		for(int i = 0; i < numBox; i++)
		{
			vector<int> dimension(numDimension, 0);
			for(int j = 0; j < numDimension; j++)
				scanf("%d", &dimension[j]);
			boxArr.push_back(Box(numDimension, dimension));
		}

		buildAdjList(boxArr, adjList);

		getLongestPathDAG(adjList, longestNestedSeq);

		printf("%d\n", (int) longestNestedSeq.size());
		printf("%d", longestNestedSeq[0] + 1);
		for(int i = 1; i < (int) longestNestedSeq.size(); i++)
			printf(" %d", longestNestedSeq[i] + 1);
		printf("\n");		
	}

	return 0;	
}

void buildAdjList(const vector<Box> & boxArr, vector<vector<int> > & adjList)
{
	int numV = (int) boxArr.size();

	adjList.assign(numV, vector<int> ());

	for(int boxOne = 0; boxOne < numV; boxOne++)
		for(int boxTwo = 0; boxTwo < numV; boxTwo++)
			if(boxArr[boxOne].canBeNestedIn(boxArr[boxTwo]))
				adjList[boxOne].push_back(boxTwo);
}

void getLongestPathDAG(const vector<vector<int> > & adjList, vector<int> & longestPath)
{
	vector<int> topoOrder;

	getTopoOrder(adjList, topoOrder);

	int numV = (int) adjList.size();
	vector<int> predecessor(numV, 0);
	for(int i = 0; i < numV; i++)
		predecessor[i] = i;
	vector<int> pathLength(numV, 0);
	for(int i = 0; i < numV; i++)
	{
		int u = topoOrder[i];
		for(int k = 0; k < (int) adjList[u].size(); k++)
		{
			int v = adjList[u][k];

			if(pathLength[u] + 1 > pathLength[v])
			{
				pathLength[v] = pathLength[u] + 1;
				predecessor[v] = u;
			}
		}
	}

	longestPath.clear();
	int maxInd = 0;
	for(int v = 1; v < numV; v++)
		if(pathLength[v] > pathLength[maxInd])
			maxInd = v;

	int pathV = maxInd;
	while(1)
	{
		longestPath.push_back(pathV);
		int parent = predecessor[pathV];
		if(parent == pathV)
			break;
		pathV = parent;
	}
	reverse(longestPath.begin(), longestPath.end());
}

void getTopoOrder(const vector<vector<int> > & adjList, vector<int> & topoOrder)
{
	int numV = (int) adjList.size();
	topoOrder.clear();
	
	vector<int> inDegree(numV, 0);
	for(int u = 0; u < numV; u++)
		for(int ind = 0; ind < (int) adjList[u].size(); ind++)
		{
			int v = adjList[u][ind];
			inDegree[v]++;
		}

	queue<int> zeroInDegree;
	for(int v = 0; v < numV; v++)
		if(inDegree[v] == 0)
			zeroInDegree.push(v);

	while(!zeroInDegree.empty())
	{
		int v = zeroInDegree.front();
		zeroInDegree.pop();

		topoOrder.push_back(v);

		for(int ind = 0; ind < (int) adjList[v].size(); ind++)
		{
			int nextV = adjList[v][ind];

			inDegree[nextV]--;
			if(inDegree[nextV] == 0)
				zeroInDegree.push(nextV);
		}
	}
}
