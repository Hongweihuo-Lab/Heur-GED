#ifndef _EDGENTRY_H
#define _EDGENTRY_H
#include "stdafx.h"

struct edgeData
{
	string type; //Line type and angle
	string angle;
	edgeData()
	{
		type = "+";
		angle = "+"; 
	}
	edgeData(string t, string a) : type(t), angle(a){}
};
class edgeEntry
{
public:
	int edge_id; //-1, dummy 
	int frequency; //number of property 
	vector<edgeData> edgeInfo;
	edgeEntry()
	{	
		edge_id = -1;
		frequency = 0;
	}
	edgeEntry(int &eid, int &freq, vector<edgeData> &e) : 
		edge_id(eid), frequency(freq), edgeInfo(e) {}
	~edgeEntry(){}

	void edgeEntrySequence(string &edgeSeqStr)
	{
		edgeSeqStr = ""; vector<string> tmp(frequency, "");
		for (int i = 0; i < frequency; i++)
		{
			tmp[i] = edgeInfo[i].type + edgeInfo[i].angle;
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < frequency; i++)
			edgeSeqStr += tmp[i];
		
		
	}
};

#endif