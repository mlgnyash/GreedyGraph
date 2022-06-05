#include "Graph.h"
#include <fstream>

void print(vector<Vertex> vec) { //�������� ������ ���������� ������� ������
	auto it = vec.begin();
	while (it != vec.end()) {
		cout << (*it).getnum() << " ";
		it++;
	}
	cout << endl;
}

int main() {
//�������� � ������ ����� � �������� � ������� ������
	string file_name;
	cin >> file_name;
	file_name = "C:\\data\\gc_" + file_name;

// ��� ������ �������� ��������� ���� (���� �����), ����� ���������� ������ ������ � ���-�� �����
	ifstream data_file;
	data_file.open(file_name);
	if(!data_file) {
		cout << "Can not open file  " << file_name << endl;
		return 0;
	}

// �������� ����� � ��������� � ������� N ��������� � � �������
	int N, M;
	data_file >> N >> M;
	Graph G(N);

	int V1, V2;
	for (int i = 0; i < M; i++) {
		data_file >> V1 >> V2;
		G.add_edge(V1, V2);
	}

	//cout << "Graph looks like that:" << endl;
	//G.print();
	//cout << endl << "Vector of vertices before sorting: ";
	//G.print_adj();
	//cout << "Vector of vertices after sorting: ";
	G.adj_sort(); // ���������� �� �������� ����� ������ � ��������
	//G.print_adj();
	//cout << endl;

	int colored = 0, curcolor = 1; // ������ ����� ����������� ������ � "�������� ����"
	vector<Vertex> curadj; // ������ ������ "��������� �������" - ����� �� ���� ��������� ��������� ������ � �������� ������
	while (colored != N) { // ������� ������ ����� ����� �������, � ���� ������ ������������� � curcolor �������
		vector<Vertex>::iterator it = G.begin();
		bool new_vertex_found = 0;
		while (it != G.end() && new_vertex_found == 0) { // ������� ��� ������������� - � �� ������� ������������ ���� ��������� �� � ���� curcolor
			if ((*it).getcolor() == -1) {
				(*it).setcolor(curcolor);
				colored++;
				curadj.push_back((*it));
				new_vertex_found = 1;
				//cout << "Found an uncolored vertex " << (*it).getnum() << endl;
			}
			it++;
		}

		it = G.begin(); // ���������� �������� �� ������, � ����� ����� ����� �������, ����� ��� ��������� � curcolor
		while (it != G.end()) {
			if ((*it).getcolor() == -1) { // ���� ����� �������������
				//cout << "-subfound an uncolored vertex " << (*it).getnum() << endl;
				vector<Vertex>::iterator sub_it = curadj.begin(); // ������ �������� �� ������ ������ ������� ������ ����� �����
				int do_not_use = 0; // ���� ��� ����� ������ �� ����� ����, �� ����� ������������ ��� �������

				while (sub_it != curadj.end() && do_not_use==0) {
					//cout << "--checking it for being adjacent to " << (*sub_it).getnum() << "..." << endl;
					//cout << "--check result is " << G.are_connected((*it), (*sub_it)) << endl;
					do_not_use += G.are_connected((*it), *sub_it);
					sub_it++;
				}

				if (do_not_use == 0) { // ���� �� �� ����� �������� �������, ������, ���� ������� ������ �� ������
					//cout << "--this vertex is not adjacent to anything" << endl;
					(*it).setcolor(curcolor); // ������ �
					//cout << "---colored it in color " << curcolor << endl;
					colored++; // ����������� ���������� ����������� �� 1
					//cout << "---there are now " << colored << " colored vertices" << endl;
					curadj.push_back((*it).getnum()); // ��������� � � ������ ��������� �� ����� �����
					//cout << "---added it to the list of this color's adjacents: ";
					//print(curadj);
				}
			}
			it++; // ������ �����
		} // ���� ���� ���������� => �� � ������ curcolor ������ �� �����
		curcolor++; // ����� �� ���������� �����
		curadj.clear(); // ������� ������ ��������� - � ����� ������ ������� ����� �����
		//cout << endl;
	}

	cout << endl << "The graph is colored in " << curcolor-1 << " colors" << endl;
	//G.print_colors();

	return 0;
}