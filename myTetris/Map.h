#pragma once
class Map {
public:
	/*�����*/
	typedef vector<bool>::size_type mapCol;  //vector<bool>::size_type
	typedef vector<vector<bool>>::size_type mapRow;  //vector<bool>::size_type

	/*��Ԫ*/
	friend class Drop;
	friend class LcdMath;
	friend class RuningEls;
	friend void gameRun();
	/*��Ա����*/
	Map& drawOriginalMap();//��������������ͼ-���Ʊ߽糡��
	Map& drawNow();        //���Ƶ�ͼ��ǰ״̬
    
private:
	/*��̬��Ա*/
	static constexpr mapCol totalHeight = 30; //�ܸ�
	static constexpr mapRow totalWidth = 60;  //�ܿ�
	static constexpr mapCol mapHeight = 30;   //��ͼ�߶�
	static constexpr mapRow mapWidth = 20;    //��ͼ���
	//static vector<vector<bool>> map;          //��ͼ���� 
	vector<vector<bool>> map = { totalHeight, vector<bool>(totalWidth, 0) }; //��ͼ���� 

	/*��̬����*/

};
/*****************�ӿ�����******************/

/*****************��Ա����******************/
/****���Զ���****/
//vector<vector<bool>> Map::map(totalHeight, vector<bool>(totalWidth, 0));//��ͼ
             
/****��������****/
/*��������������ͼ-���Ʊ߽糡��*/
Map& Map::drawOriginalMap() {
	//��һ�к����һ�еĸ���ȫ����Ϊʵ
	std::fill(map[0].begin(), map[0].begin() + mapWidth, 1);
	std::fill(map[(mapHeight - 1)].begin(), map[(mapHeight - 1)].begin() + mapWidth, 1);
	//��һ�е������ڶ���֮�������е� ��һ�������һ���ĸ�����Ϊʵ
	for (int i = 1; i <= (mapHeight - 2); i++) {
		map[i][0] = 1;
		map[i][(mapWidth - 1)] = 1;
	}
	return *this;
}
/*���Ƶ�ͼ��ǰ״̬*/
Map& Map::drawNow() {
	system("cls");
	for (vector<vector<bool>>::iterator cols = map.begin(); cols != map.end(); cols++) {
		for (vector<bool>::iterator rows = cols->begin(); rows != cols->end(); rows++) {
			if (*rows) cout << "��";
			else cout << ' ' << ' ';
		}
		cout << endl;
	}
	return *this;
}


