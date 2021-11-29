#pragma once
#ifndef LCDMATH
#define LCDMATH

class LcdMath {
public:
	typedef vector<vector <bool>> oneNum;  //每一个形状
	
	/*友元声明*/
	friend oneNum getNum(vector<oneNum>::size_type wNumber);
private:
	static vector<oneNum> shapeNumber;

};

/*接口声明*/

//返回对应图形状态
LcdMath::oneNum getNum(vector<LcdMath::oneNum>::size_type wNumber);
/*****************成员定义******************/
/****属性定义****/
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
/****接口定义****/
LcdMath::oneNum getNum(vector<LcdMath::oneNum>::size_type wNumber) {
	return LcdMath::shapeNumber[wNumber];//返回矩阵x
}


/*
//测试已通过
for (int j = 0; j < 10; j++) {
			for (auto it : getNum(j)) {
				for (auto itt : it) {
					if (itt) {
						cout << "■";
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
