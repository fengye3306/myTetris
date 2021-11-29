#pragma once
#ifndef LCDMATH
#define LCDMATH

class LcdMath {
public:
	typedef vector<vector <bool>> oneNum;  //ÿһ����״
	
	/*��Ԫ����*/
	friend oneNum getNum(vector<oneNum>::size_type wNumber);
private:
	static vector<oneNum> shapeNumber;

};

/*�ӿ�����*/

//���ض�Ӧͼ��״̬
LcdMath::oneNum getNum(vector<LcdMath::oneNum>::size_type wNumber);
/*****************��Ա����******************/
/****���Զ���****/
vector<LcdMath::oneNum> LcdMath::shapeNumber{
	oneNum{{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}},//0
	oneNum{{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},//1
	oneNum{{1,1,1,1},{0,0,0,1},{1,1,1,1},{1,0,0,0},{1,1,1,1}},//2
	oneNum{{1,1,1,1},{0,0,0,1},{1,1,1,1},{0,0,0,1},{1,1,1,1}},//3
	oneNum{{1,0,0,1},{1,0,0,1},{1,1,1,1},{0,0,0,1},{0,0,0,1}},//4
	oneNum{{1,1,1,1},{1,0,0,0},{1,1,1,1},{0,0,0,1},{1,1,1,1}},//5
	oneNum{{1,0,0,0},{1,0,0,0},{1,1,1,1},{1,0,0,1},{1,1,1,1}},//6
	oneNum{{1,1,1,1},{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1}},//7
	oneNum{{1,1,1,1},{1,0,0,1},{1,1,1,1},{1,0,0,1},{1,1,1,1}},//8
	oneNum{{1,1,1,1},{1,0,0,1},{1,1,1,1},{0,0,0,1},{0,0,0,1}},//9
};
/****�ӿڶ���****/
LcdMath::oneNum getNum(vector<LcdMath::oneNum>::size_type wNumber) {
	return LcdMath::shapeNumber[wNumber];//���ؾ���x
}


/*
//������ͨ��
for (int j = 0; j < 10; j++) {
			for (auto it : getNum(j)) {
				for (auto itt : it) {
					if (itt) {
						cout << "��";
					}
					else {
						cout << "  ";
					}

				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;

*/


#endif // !LCDMATH
