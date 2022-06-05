#include "Vertex.h"

Vertex::Vertex(int i) { // �������� ������� � �������� ��������� � �������������� ������
	num = i;
	color = -1;
}

int Vertex::getnum() { //������� ��������
	return num;
}

void Vertex::setnum(int n) { //����� ��������
	num = n;
}

int Vertex::getcolor() { //������� �����
	return color;
}
void Vertex::setcolor(int c) { //����� �����
	color = c;
}

vector<int>::iterator Vertex::begin() { //�������, ������� ���������� ������ ������� ��������� � ������ �������� ������ ������
	return adj_Vertices.begin();
}
vector<int>::iterator Vertex::end() { //�� �� ����� ��� �������, �� ���������� �����
	return adj_Vertices.end();
}

void Vertex::add_adj(int i) { //��������� � ������ ��������� ������ �����
	adj_Vertices.push_back(i);
}

int Vertex::adj_count() const { //���������� ���-�� ��������� � ������ �������� ������ ������
	return (adj_Vertices.size());
}

bool Vertex::operator<(const Vertex & V2) { //�������� ��������� ���� ������ �� ���������� ��������� � ���� ������ ������
	return (this->adj_count() > V2.adj_count());
}