
#ifndef _GLOBAL_H
#define _GLOBAL_H
#include "stdafx.h"
#include "nodeEntry.h"
#include "edgeEntry.h"
#include "verifyNode.h"

#define INF 1e9
#define EPASON 1e-9

extern int q[1000];
extern string gname, type, sequence;
extern string x, y, angle;

extern int INSERTED;
extern int DELETED;
extern int UNMAPPED;
extern int DUMMY;
extern u64 expand_nodes;

extern nodeEntry DUMMY_NODE;
extern edgeEntry DUMMY_EDGE;

extern vector<vector<double> > nodeSubMatrix; //C_V
extern vector<vector<double> > edgeSubMatrix; //C_E
extern int node_row;
extern int node_column;
extern int edge_row;
extern int edge_column;

//tree-search
extern vector<vector<int> > adjList1;
extern vector<vector<int > > adjList2;
extern vector<vector<edgeEntry > > E1;
extern vector<vector<edgeEntry > > E2;
extern vector<int> unused_vertices_1;
extern vector<int> unused_vertices_2;
extern verifyNode gn1[1024];
extern verifyNode gn2[1024];
extern edgeEntry adj_edges_1[1024];
extern edgeEntry adj_edges_2[1024];
extern int adj_nums_1;
extern int adj_nums_2;

extern double UB;
extern int LB_CALL;
extern struct timeval time_start;
extern struct timeval time_now;
extern double time_set;
extern bool time_flag;

//parameter and data
const cost_constant GREC_COST_CONSTANT = cost_constant(90, 1.0, 15, 1.0, 0.5);
const cost_constant PRO_COST_CONSTANT = cost_constant(11, 1.0, 1.0, 2.0, 0.75);
const cost_constant MUTA_COST_CONSTANT = cost_constant(11, 2.0, 1.1, 1.0, 0.25);
const cost_constant CMU_COST_CONSTANT = cost_constant(INF, 1.0, INF, 1.0, 0.5);
const cost_constant PATH_COST_CONSTANT = cost_constant(3, 1.0, 3, 1.0, 0.5);
const cost_constant SYN_COST_CONSTANT = cost_constant(0.3, 1.0, 0.5, 1.0, 0.75);

//for debug
extern bool DEBUG;

#ifdef WIN32
extern int gettimeofday(struct timeval *tp, void *tzp);
#endif

#endif
