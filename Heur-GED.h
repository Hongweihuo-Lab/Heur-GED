#ifndef _HEUR_GED_H
#define _HEUR_GED_H

#include "cost.h"
#include "BED.h"
#include "editDistance.h"

class Heur_GED
{
public:
	graph G, Q;
	cost_constant cc;  //the cost function 

public:
	Heur_GED()
	{
		time_set = 1000.0; //1s 
	}
	~Heur_GED(){}

	Heur_GED(string &ga, string &gb, cost_constant &cs, double dt = 1000)
	{
		graph g1, g2;
		g1.readGraph(ga);
		g2.readGraph(gb);

		if (g1.v <= g2.v) //swap 
		{
			this->G = g1;
			this->Q = g2;
		}
		else
		{
			this->G = g2;
			this->Q = g1;
		}
		this->cc = cs;
		time_set = dt;

		UB = INF;
		time_flag = false;
		expand_nodes = 0; 

		init_cost_matrix();
	}

public:
	void init_cost_matrix()
	{
		nodeSubMatrix.clear();
		edgeSubMatrix.clear();
		this->init_node_cost_matrix();
		this->init_edge_cost_matrix();
		node_row = nodeSubMatrix.size() - 1;
		node_column = nodeSubMatrix[0].size() - 1;
		edge_row = edgeSubMatrix.size() - 1;
		edge_column = edgeSubMatrix[0].size() - 1;
	}

	void init_node_cost_matrix()
	{
		int r = G.node_label_set.size() + 1;
		int c = Q.node_label_set.size() + 1;

		vector<double > node_tmp(c, 0.0);
		nodeSubMatrix.resize(r, node_tmp);

		nodeEntry a, b;
		map<string, node_entry_info> ::iterator va_iter;
		map<string, node_entry_info> ::iterator vb_iter;
		int idx_i, idx_j;

		for (va_iter = G.node_label_set.begin(); va_iter != G.node_label_set.end(); va_iter++)
		{
			idx_i = va_iter->second.nid;
			a = va_iter->second.ne;
			for (vb_iter = Q.node_label_set.begin(); vb_iter != Q.node_label_set.end(); vb_iter++)
			{
				idx_j = vb_iter->second.nid;
				b = vb_iter->second.ne;
				nodeSubMatrix[idx_i][idx_j] = cost::node_cost(a, b, cc);
			}
		}

		for (va_iter = G.node_label_set.begin(); va_iter != G.node_label_set.end(); va_iter++)
		{
			idx_i = va_iter->second.nid;
			a = va_iter->second.ne;
			nodeSubMatrix[idx_i][c - 1] = cost::node_cost(a, DUMMY_NODE, cc);
		}
		for (vb_iter = Q.node_label_set.begin(); vb_iter != Q.node_label_set.end(); vb_iter++)
		{
			idx_j = vb_iter->second.nid;
			b = vb_iter->second.ne;
			nodeSubMatrix[r - 1][idx_j] = cost::node_cost(DUMMY_NODE, b, cc);
		}
	}

	void init_edge_cost_matrix()
	{
		int r = G.edge_label_set.size() + 1, c = Q.edge_label_set.size() + 1;
		vector<double > e_tmp(c, 0.0);
		edgeSubMatrix.resize(r, e_tmp);

		int idx_i, idx_j;
		edgeEntry a, b;
		map<string, edge_entry_info> ::iterator ea_iter;
		map<string, edge_entry_info> ::iterator eb_iter;
		for (ea_iter = G.edge_label_set.begin(); ea_iter != G.edge_label_set.end(); ea_iter++)
		{
			idx_i = ea_iter->second.eid;
			a = ea_iter->second.ee;
			for (eb_iter = Q.edge_label_set.begin(); eb_iter != Q.edge_label_set.end(); eb_iter++)
			{
				idx_j = eb_iter->second.eid;
				b = eb_iter->second.ee;
				edgeSubMatrix[idx_i][idx_j] = cost::edge_cost(a, b, cc);
			}
		}
		for (ea_iter = G.edge_label_set.begin(); ea_iter != G.edge_label_set.end(); ea_iter++)
		{
			idx_i = ea_iter->second.eid;
			a = ea_iter->second.ee;
			edgeSubMatrix[idx_i][c - 1] = cost::edge_cost(a, DUMMY_EDGE, cc);
		}
		for (eb_iter = Q.edge_label_set.begin(); eb_iter != Q.edge_label_set.end(); eb_iter++)
		{
			idx_j = eb_iter->second.eid;
			b = eb_iter->second.ee;
			edgeSubMatrix[r - 1][idx_j] = cost::edge_cost(DUMMY_EDGE, b, cc);
		}
	}
public:
	double approximate_GED()
	{
		gettimeofday(&time_start, NULL); 
		UB = BED().BP(G, Q);			
		editDistance().getEditDistance(G, Q); //tree-based search
		return UB;
	}
};
#endif 