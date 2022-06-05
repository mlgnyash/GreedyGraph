#pragma once
#include "Vertex.h" //������ ������ �������

class Graph
{
private: //��������� ���� ������ - ������ ������ ����� � ������ ��������������� ������ �����
	vector<Vertex> Vertices;
	vector<Vertex> Sorted_Vertices;
public:
// ���������� ��������� ������� 
	Graph(int); //�����������
	bool are_connected(Vertex V1, Vertex V2); //�������� ��������� 2 ������ �����
	void add_edge(int V1, int V2); //���������� ����� ����� ���������
	void print(); //������ ������ �����
	vector<Vertex> get_vertices(); //��������� ������� ������� � Graph.cpp
	Vertex vertex(int);
	vector<Vertex>::iterator begin();
	vector<Vertex>::iterator end();
	vector<Vertex>::iterator sorted_begin();
	vector<Vertex>::iterator sorted_end();
	void adj_sort();
	void print_adj();
	void print_colors();
};

