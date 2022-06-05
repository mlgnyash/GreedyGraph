#include "Graph.h"

Graph::Graph(int N) { // ����������� (������� ��������) ����� � �������� ���-��� ������
	for (int i = 0; i < N; i++) {
		Vertices.push_back(Vertex(i));
	}
	Sorted_Vertices = Vertices;
}

bool Graph::are_connected(Vertex V1, Vertex V2) { 
//������� �������� ��������� ���� ������ ������ �����. ��� 
// ����� �� ������� �������� (�� ����� ������ �����) � 
// ���������� �� ���� ��������� ������ ������ �������.
// ���� ����� - ������ 1 (true), �� ����� - ������ 0 (false).
	vector<int>::iterator it = V1.begin();
	while (it != V1.end()) {
		if ((*it) == V2.getnum()) {
			return 1;
		}
		it++;
	}
	return 0;
}

void Graph::add_edge(int V1, int V2) {
// ������� ���������� ����� ����� ����� ������� ���������.
// ��� ����� � ������ ������ ������ ������� ��������� ������ �������.
	if (V1 != V2) {
		Vertices[V1].add_adj(V2);
		Vertices[V2].add_adj(V1);
	}
}

void Graph::print() {
	vector<Vertex>::iterator it = Vertices.begin();
	while (it != Vertices.end()) {
		cout << "Adjacent vertices to vertex " << (*it).getnum() << " are: ";
		vector<int>::iterator sub_it = (*it).begin();
		while (sub_it != (*it).end()) {
			cout << (*sub_it) << " ";
			sub_it++;
		}
		cout << endl;
		it++;
	}
}

vector<Vertex> Graph::get_vertices() { // ������� ����������� ������ �����
	return Vertices;
}

Vertex Graph::vertex(int i) { //������� ����������� ������� � �������� ��������
	return Vertices[i];
}

vector<Vertex>::iterator Graph::begin() { //������� ��� ����������� ������ ������� ������
	return Vertices.begin();
}

vector<Vertex>::iterator Graph::end() { // ������� ��� ����������� ����� ������� ������
	return Vertices.end();
}

vector<Vertex>::iterator Graph::sorted_begin() { // ������� ��� ����������� ������ ������� ��������������� (�� ��������) ������
	return Sorted_Vertices.begin();
}

vector<Vertex>::iterator Graph::sorted_end() { // ���������� ����� ���������������� �������
	return Sorted_Vertices.end();
}

void Graph::adj_sort() { //������� ���������� ������� ������
	sort(Vertices.begin(), Vertices.end());
}

void Graph::print_adj() { //������� ��� ������ � ������� �������� ������ �������
	vector<Vertex>::iterator it = Vertices.begin();
	while (it != Vertices.end()) {
		cout << (*it).getnum() << " ";
		it++;
	}
	cout << endl;
}

void Graph::print_colors() { // ������� ��� ������ � ������� ��������� (�����) ������ �������
	vector<Vertex>::iterator it = Vertices.begin();
	while (it != Vertices.end()) {
		cout << (*it).getnum() << " is colored in color " << (*it).getcolor() << endl;
		it++;
	}
}