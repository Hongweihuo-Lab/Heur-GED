#ifndef  _TREE_VERIFY_GRAPH_Node_H
#define  _TREE_VERIFY_GRAPH_Node_H

#include "global.h"
#include "verifyGraph.h"
#include "Hungarian.h"

class treeNode
{
public:
	int *matching, *inverseMatching;
	bool visited;
	verifyGraph uG1, uG2;
	double deep, estimate_cost; //online 

public:
	treeNode()
	{
		this->estimate_cost = this->deep = 0.0;
		this->matching = this->inverseMatching = NULL;
		this->visited = false;
	}
	treeNode(const treeNode &tn) //deep copy
	{
		*this = tn;
	}
	treeNode & operator= (const treeNode &tn) //deep copy
	{
		if (this != &tn)
		{
			this->uG1 = tn.uG1, this->uG2 = tn.uG2;
			this->deep = tn.deep, this->estimate_cost = tn.estimate_cost;
			this->visited = false;
			assert(tn.matching); matching = new int[uG1.gs]; 
			for (int i = 0; i < uG1.gs; i++) 
				matching[i] = tn.matching[i];
			assert(tn.inverseMatching); inverseMatching = new int[uG2.gs]; 
			for (int j = 0; j < uG2.gs; j++) 
				inverseMatching[j] = tn.inverseMatching[j];
		}
		return *this;
	}	
	bool operator< (const treeNode &bb) const 
	{
		
		double costa = deep + estimate_cost; 
		double costb = bb.deep + bb.estimate_cost;
		if (costa > costb)
			return true;			
		else  if(costa < costb)
			return false;
		else
		{
			if(deep > bb.deep) 
				return true;
			else
				return false;
		}	
	}
	~treeNode()
	{
		if (matching)
		 {
			delete[]matching; matching = 0;
		}
		if (inverseMatching)
		{
			delete[] inverseMatching; inverseMatching = 0;
		}
	}
private: 
	inline void  addCost(double c)
	{
		this->deep += c;
	}
	bool allverifyGraphNodesUsed()
	{
		if (uG1.v == 0 && uG2.v == 0)
			return true;
		return false;
	}

	double adjacent_edge_cost_insert(int *m, int i);
	double adjacent_edge_cost_delete(int *m, int i);
	void process_edges(int &start, int &end);
	void adjacent_edge(int &start, int *m, vector<vector<int > > &adjList, 
		vector<vector<edgeEntry > > &E, int &adj_num, edgeEntry * ve);
	double out_distance(int &start, int &u, int &v); //<u --> v>
	double assign_cost_BED(int &start, int &u, int &v);
	double estimate_BED(int &start, int &end, vector<int > &vs);    // h = BED+ or BED 	
	double estimate_LED(int &start, int &end, vector<int> &vs); // h = LED	
	double assign_cost_HED(int &u, int &v); 
	double estimate_HED(int &start, int &end, vector<int> &vs); // h = HED
	double estimate(int &start, int &end, vector<int > &vs); 
public:
	void init(graph &g1, graph &g2);
	void generateSuccessors(vector<treeNode *> &successors);
	double edit_cost()
	{
		return UB;
	}

};
#endif
