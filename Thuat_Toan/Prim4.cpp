#include <bits/stdc++.h>
using namespace std;
  
#define INF 9999
//đồ thị chứa 11 đỉnh
#define V 11
//mảng G lưu trữ ma trận kề cho đồ thị đầu vào
int G[V][V] = { { 0, 4, 0, 0, 3, 0, 0, 0, 2, 0, 0 },
                { 4, 0, 9, 0, 8, 3, 0, 0, 0, 0, 0 },
                { 0, 9, 0, 7, 0, 4, 0, 0, 0, 0, 0 },
                { 0, 0, 7, 0, 0, 0, 2, 1, 0, 0, 0 },
                { 3, 8, 0, 0, 0, 1, 0, 0, 7, 0, 0 },
                { 0, 3, 4, 0, 1, 0, 3, 0, 0, 9, 0 },
                { 0, 0, 0, 2, 0, 3, 0, 15, 0, 3, 12 },
                { 0, 0, 0, 1, 0, 0, 15, 0, 0, 0, 3 },
                { 2, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0 },
                { 0, 0, 0, 0, 0, 9, 3, 0, 1, 0, 8 },
                { 0, 0, 0, 0, 0, 0, 12, 3, 0, 8, 0 } };
 
int prim(){
	int num_edge;		//số cạnh
  
  	//mst_vertex - mảng để theo dõi các đỉnh được chọn cho cây khung
 	int mst_vertex[V];
   
 	//đặt ban đầu đã chọn sai
	memset (mst_vertex, false, sizeof (mst_vertex));
  
 	//đặt số cạnh thành 0
	num_edge = 0;
  
   //để đỉnh thứ 0 là đỉnh đầu tiên được chọn
	mst_vertex[0] = true;
	int x;            //ngang
	int y;            //dọc
  
   //in chi tiết của MST
	cout << "Cay khung toi thieu cua thuat toan Prim: "<<endl;
	cout << "Canh" << " : " << "Trong so";
	cout << endl;

	int sum_weight = 0;
	while (num_edge < V - 1) {
  
   //thuật toán prim
		int min = INF;
    	x = 0;
    	y = 0;
  
	for (int i = 0; i < V; i++) {
		if (mst_vertex[i]) {
			for (int j = 0; j < V; j++) {
				if (!mst_vertex[j] && G[i][j]) { //không có trong mst_vertex và có một cạnh
					if (min > G[i][j]) {
						min = G[i][j];
                      	x = i;
                     	y = j;
                  	}
             	}
          	}
        }
    }
	cout << x <<  " - " << y << " :  " << G[x][y];
	cout << endl;
	mst_vertex[y] = true;
	num_edge++;
	sum_weight += G[x][y];
    }
	cout << "Tong trong so cac canh la: " << sum_weight << endl;
}
int main () {
	prim();
  	return 0;
}
