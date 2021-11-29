#pragma once
#ifndef DROP
#define DROP

class Drop {
public:
	typedef vector<vector <bool>> oneState;  //每一个形状
	typedef vector<oneState> oneShape;       //每一个形状变化总和
	/*友元声明*/
	friend oneState getState(vector<oneShape>::size_type wShape, oneShape::size_type wChange);
private:
	static vector<oneShape> shapeTotal;

};

/*接口声明*/

//返回对应图形状态
Drop::oneState getState(vector<Drop::oneShape>::size_type wShape, Drop::oneShape::size_type wChange);

/*****************成员定义******************/
/****属性定义****/
vector<Drop::oneShape> Drop::shapeTotal{
		oneShape{//梯形
		oneState{{1,1,1},{0,1,0}},
		oneState{{0,1},{1,1},{0,1}},
		oneState{{0,1,0},{1,1,1}},
		oneState{{1,0},{1,1},{1,0}},
		},oneShape{//初始左突L形
		oneState{{1,0},{1,0},{1,1}},
		oneState{{1,1,1},{1,0,0}},
		oneState{{1,1},{0,1},{0,1}},
		oneState{{0,0,1},{1,1,1}},
		},
		oneShape{//初始右突L形
		oneState{{0,1},{0,1},{1,1}},
		oneState{{1,0,0},{1,1,1}},
		oneState{{1,1},{1,0},{1,0}},
		oneState{{1,1,1},{0,0,1}},
		},
		oneShape{//右尾闪电形
		oneState{{1,1,0},{0,1,1}},
		oneState{{0,1},{1,1},{1,0}},
		oneState{{1,1,0},{0,1,1}},
		oneState{{0,1},{1,1},{1,0}},
		},
		oneShape{//左尾闪电形
		oneState{{0,1,1},{1,1,0}},
		oneState{{1,0},{1,1},{0,1}},
		oneState{{0,1,1},{1,1,0}},
		oneState{{1,0},{1,1},{0,1}},
		},
		oneShape{//正方形
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		oneState{{1,1},{1,1}},
		},
		oneShape{//长方形
		oneState{{1},{1},{1},{1}},
		oneState{{1,1,1,1}},
		oneState{{1},{1},{1},{1}},
		oneState{{1,1,1,1}},
		oneState{{1,1,1,1}},
		}
};
/****接口定义****/
Drop::oneState getState(vector<Drop::oneShape>::size_type wShape, Drop::oneShape::size_type wChange){
	return Drop::shapeTotal[wShape][wChange];
}


/*
测试 - 已通过
for (int i = 0; i < 7; i++) {
		for(int j = 0; j< 4; j++){
			for (auto it : getState(i, j)) {
				for (auto itt : it) {
					if(itt){
						cout << "■";
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
