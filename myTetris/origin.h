#pragma once
/*这是一切的起源 作为纪念保留在这里*/

//全局变量
constexpr vector<bool>::size_type mapWidth = 20;//地图宽度
constexpr vector<vector<bool>>::size_type mapHeight = 20;//地图高度
static vector<vector<bool>> map (mapHeight, vector<bool>(mapWidth,0));//地图本体 

void drawOriginalMap();//绘制最初的地图-绘制边界场地
void drawNow();//绘制当前状态下的地图

void drawOriginalMap() {
	//第一行和最后一行的格子全部设为实
	 std::fill(map[0].begin(), map[0].end(), 1);
	 std::fill(map[(mapHeight-1)].begin(), map[(mapHeight-1)].end(), 1);
	//第一行到倒数第二行之间所有行的 第一个和最后一个的格子设为实
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
			if (*rows) cout << "■";
			else cout << ' '<< ' ';		
		}
		cout <<endl;		
	}	
}