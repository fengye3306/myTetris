#pragma once
class Map {
public:
	/*类别名*/
	typedef vector<bool>::size_type mapCol;  //vector<bool>::size_type
	typedef vector<vector<bool>>::size_type mapRow;  //vector<bool>::size_type

	/*友元*/
	friend class Drop;
	friend class LcdMath;
	friend class RuningEls;
	friend void gameRun();
	/*成员方法*/
	Map& drawOriginalMap();//绘制最初的游玩地图-绘制边界场地
	Map& drawNow();        //绘制地图当前状态
    
private:
	/*静态成员*/
	static constexpr mapCol totalHeight = 30; //总高
	static constexpr mapRow totalWidth = 60;  //总宽
	static constexpr mapCol mapHeight = 30;   //地图高度
	static constexpr mapRow mapWidth = 20;    //地图宽度
	//static vector<vector<bool>> map;          //地图声明 
	vector<vector<bool>> map = { totalHeight, vector<bool>(totalWidth, 0) }; //地图声明 

	/*静态方法*/

};
/*****************接口声明******************/

/*****************成员定义******************/
/****属性定义****/
//vector<vector<bool>> Map::map(totalHeight, vector<bool>(totalWidth, 0));//地图
             
/****方法定义****/
/*绘制最初的游玩地图-绘制边界场地*/
Map& Map::drawOriginalMap() {
	//第一行和最后一行的格子全部设为实
	std::fill(map[0].begin(), map[0].begin() + mapWidth, 1);
	std::fill(map[(mapHeight - 1)].begin(), map[(mapHeight - 1)].begin() + mapWidth, 1);
	//第一行到倒数第二行之间所有行的 第一个和最后一个的格子设为实
	for (int i = 1; i <= (mapHeight - 2); i++) {
		map[i][0] = 1;
		map[i][(mapWidth - 1)] = 1;
	}
	return *this;
}
/*绘制地图当前状态*/
Map& Map::drawNow() {
	system("cls");
	for (vector<vector<bool>>::iterator cols = map.begin(); cols != map.end(); cols++) {
		for (vector<bool>::iterator rows = cols->begin(); rows != cols->end(); rows++) {
			if (*rows) cout << "■";
			else cout << ' ' << ' ';
		}
		cout << endl;
	}
	return *this;
}


