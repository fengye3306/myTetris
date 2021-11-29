#pragma once
#ifndef DROP
#define DROP

class Drop {
public:
	typedef vector<vector <bool>> oneState;  //ÿһ����״
	typedef vector<oneState> oneShape;       //ÿһ����״�仯�ܺ�
	/*��Ԫ����*/
	friend oneState getState(vector<oneShape>::size_type wShape, oneShape::size_type wChange);
private:
	static vector<oneShape> shapeTotal;

};

/*�ӿ�����*/

//���ض�Ӧͼ��״̬
Drop::oneState getState(vector<Drop::oneShape>::size_type wShape, Drop::oneShape::size_type wChange);

/*****************��Ա����******************/
/****���Զ���****/
vector<Drop::oneShape> Drop::shapeTotal{
		oneShape{//����
		oneState{{1,1,1},{0,1,0}},
		oneState{{0,1},{1,1},{0,1}},
		oneState{{0,1,0},{1,1,1}},
		oneState{{1,0},{1,1},{1,0}},
		},oneShape{//��ʼ��ͻL��
		oneState{{1,0},{1,0},{1,1}},
		oneState{{1,1,1},{1,0,0}},
		oneState{{1,1},{0,1},{0,1}},
		oneState{{0,0,1},{1,1,1}},
		},
		oneShape{//��ʼ��ͻL��
		oneState{{0,1},{0,1},{1,1}},
		oneState{{1,0,0},{1,1,1}},
		oneState{{1,1},{1,0},{1,0}},
		oneState{{1,1,1},{0,0,1}},
		},
		oneShape{//��β������
		oneState{{1,1,0},{0,1,1}},
		oneState{{0,1},{1,1},{1,0}},
		oneState{{1,1,0},{0,1,1}},
		oneState{{0,1},{1,1},{1,0}},
		},
		oneShape{//��β������
		oneState{{0,1,1},{1,1,0}},
		oneState{{1,0},{1,1},{0,1}},
		oneState{{0,1,1},{1,1,0}},
		oneState{{1,0},{1,1},{0,1}},
		},
		oneShape{//������
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		},
		oneShape{//������
		oneState{{1},{1},{1},{1}},
		oneState{{1,1,1,1}},
		oneState{{1},{1},{1},{1}},
		oneState{{1,1,1,1}},
		oneState{{1,1,1,1}},
		}
};
/****�ӿڶ���****/
Drop::oneState getState(vector<Drop::oneShape>::size_type wShape, Drop::oneShape::size_type wChange){
	return Drop::shapeTotal[wShape][wChange];
}


/*
���� - ��ͨ��
for (int i = 0; i < 7; i++) {
		for(int j = 0; j< 4; j++){
			for (auto it : getState(i, j)) {
				for (auto itt : it) {
					if(itt){
						cout << "��";
					}else{
						cout << "  ";
					}

				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
*/
#endif
