#pragma once
#ifndef _VERIFY_GRAPH_H
#define _VERIFY_GRAPH_H
#include "bitmap.h"
#include "verifyNode.h"
#include "graph.h"

static bitmap *bm = bitmap::getInstance();

class verifyGraph
{
public:
	int gs, v, e, len;
	bool *flag;
	u64 unMappedVertex[8]; //

public:
	verifyGraph(graph &g)
	{
		this->init(g);
	}
	verifyGraph()
	{	
		this->flag = 0;
		gs = v = e = len = 0;
	}
	verifyGraph(const verifyGraph &g)
	{
		*this = g;
	}
	~verifyGraph(){ this->clear(); }
	verifyGraph & operator= (const verifyGraph &g)
	{
		if (this != &g)
		{
			this->gs = g.gs, this->v = g.v, this->e = g.e; 
			this->len = g.len;
			assert(g.flag);
			this->flag = new bool[gs]; 
			memcpy(this->flag, g.flag, sizeof(bool) * gs);		
			memcpy(this->unMappedVertex, g.unMappedVertex, sizeof(u64) * this->len);

		}
		return *this;
	}	
	void clear()
	{
		if (this->flag) delete[] this->flag;
		this->v = this->gs = 0;
	}
	inline void undeal_sets(vector<int> &vs)
	{
		vs.clear();
		if (!this->v) return;
		vs.resize(this->v, 0);
		bm->getVertexSet(vs, this->unMappedVertex, this->len);
	}
public:
	void init(graph &g);	
	void remove(verifyNode &node, verifyNode *gn, const int &pos);	
};

#endif
