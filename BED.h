#ifndef _BED_H
#define _BED_H

#include "graph.h"
#include "Hungarian.h"
#include "edit_path.h"

class BED
{
private:	
	double assign_cost(graph &G, graph &Q, int &u, int &v, const double &factor)
	{
		if (u == DUMMY && v == DUMMY) return 0.0;
		
		int to, size; 
		if (u == DUMMY)
		{
			double value = 0.0;
			value += nodeSubMatrix[node_row][Q.V[v].vertex_id];		
			size = Q.adjMatrix[v].size(); 
			for (int i = 0; i < size; i++)
			{
				to = Q.adjMatrix[v][i]; 
				value += factor * edgeSubMatrix[edge_row][Q.E[v][to].edge_id];
			}
			return value;
		}
		if (v == DUMMY)
		{
			double value = 0.0;
			value += nodeSubMatrix[G.V[u].vertex_id][node_column];
			size = G.adjMatrix[u].size(); 
			for (int i = 0; i < size; i++)
			{
				int to = G.adjMatrix[u][i]; 
				value += factor * edgeSubMatrix[G.E[u][to].edge_id][edge_column];
			}
			return value;
		}

		double value = 0.0;
		value += nodeSubMatrix[G.V[u].vertex_id][Q.V[v].vertex_id];

		//then computing the best mapping from Nu to Nv
		int n1 = G.adjMatrix[u].size(), n2 = Q.adjMatrix[v].size(); 
		int n = n1 + n2;
		vector<double > tmp_sim(n, 0.0);
		vector<vector<double > > sim_matrix(n, tmp_sim);
		int to_1, to_2; 

		for (int i = 0; i < n1; i++)
		{
			to_1 = G.adjMatrix[u][i];
			for (int j = 0; j < n2; j++)
			{
				to_2 = Q.adjMatrix[v][j];
				sim_matrix[i][j] = edgeSubMatrix[G.E[u][to_1].edge_id][Q.E[v][to_2].edge_id];
			}
		}
			
		for (int i = n1; i < n; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				to_2 = Q.adjMatrix[v][j];
				if (i - n1 == j)
					sim_matrix[i][j] = edgeSubMatrix[edge_row][Q.E[v][to_2].edge_id]; 
				else
					sim_matrix[i][j] = INF;
			}
		}
		for (int i = 0; i < n1; i++)
		{
			to_1 = G.adjMatrix[u][i]; 
			for (int j = n2; j < n; j++)
			{
				if (j - n2 == i)
					sim_matrix[i][j] = edgeSubMatrix[G.E[u][to_1].edge_id][edge_column];
				else
					sim_matrix[i][j] = INF;
			}
		}
		vector<int> match; double cost_value;
		Hungarian hg; cost_value = hg.Solve(sim_matrix, match); 
		value += factor * cost_value;
		return value;
	}
	void compute_sim_matrix_BED(graph &G, graph &Q, 
		vector<vector<double > > &sim_matrix, const double &factor)
	{
		int n1 = G.v, n2 = Q.v;
		int n = n1 + n2;
		assert(sim_matrix.size() == 0);
		sim_matrix.resize(n, vector<double >(n, 0.0));
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				sim_matrix[i][j] = assign_cost(G, Q, i, j, factor);
			}
		}
		for (int i = n1; i < n; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				if (i - n1 == j)
					sim_matrix[i][j] = assign_cost(G, Q, DUMMY, j, factor);
				else
					sim_matrix[i][j] = INF;
			}
		}
		for (int i = 0; i < n1; i++)
		{
			for (int j = n2; j < n; j++)
			{
				if (j - n2 == i)
					sim_matrix[i][j] = assign_cost(G, Q, i, DUMMY, factor);
				else
					sim_matrix[i][j] = INF;
			}
		}
	}
public:
	double BED_cost(graph &G, graph &Q)
	{
		vector<int> match; double cost_value;
		vector<vector<double > > sim_matrix;
		compute_sim_matrix_BED(G, Q, sim_matrix, 0.5);
		Hungarian hg; cost_value = hg.Solve(sim_matrix, match);
		return cost_value; 
	}

	double BP(graph &G, graph &Q)
	{
		vector<int> match; double cost_value;
		vector<vector<double > > sim_matrix;
		compute_sim_matrix_BED(G, Q, sim_matrix, 1.0);
		Hungarian hg; cost_value = hg.Solve(sim_matrix, match);
		return edit_path::edit_path_cost(G, Q, match);
	}

};
#endif