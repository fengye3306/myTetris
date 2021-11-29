#pragma once
/*����һ�е���Դ ��Ϊ�����������*/

//ȫ�ֱ���
constexpr vector<bool>::size_type mapWidth = 20;//��ͼ���
constexpr vector<vector<bool>>::size_type mapHeight = 20;//��ͼ�߶�
static vector<vector<bool>> map (mapHeight, vector<bool>(mapWidth,0));//��ͼ���� 

void drawOriginalMap();//��������ĵ�ͼ-���Ʊ߽糡��
void drawNow();//���Ƶ�ǰ״̬�µĵ�ͼ

void drawOriginalMap() {
	//��һ�к����һ�еĸ���ȫ����Ϊʵ
	 std::fill(map[0].begin(), map[0].end(), 1);
	 std::fill(map[(mapHeight-1)].begin(), map[(mapHeight-1)].end(), 1);
	//��һ�е������ڶ���֮�������е� ��һ�������һ���ĸ�����Ϊʵ
	for (int i = 1; i <= (mapHeight - 2); i++) {
		map[i][0] = 1;
		cout << 1;
		map[i][(mapWidth-1)] = 1;
	}
}

void drawNow() {
	system("cls");
	for (vector<vector<bool>>::iterator cols = map.begin(); cols != map.end(); cols++) {
		for (vector<bool>::iterator rows = cols->begin(); rows != cols->end(); rows++) {
			if (*rows) cout << "��";
			else cout << ' '<< ' ';		
		}
		cout <<endl;		
	}	
}