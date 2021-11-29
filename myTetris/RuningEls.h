#pragma once
#ifndef RUNINGELS
#define RUNINGELS

#define random(x) rand()%(x) 
class RuningEls {

public:
	/*构造函数*/
	RuningEls(){
		srand((int)time(0));//随机数种子
		dropNumFutr = random(7);//赋值
	};


	/*友元*/
	friend void gameRun();

	typedef vector<bool>::size_type cols;        //行
	typedef vector<vector<bool>>::size_type rows;//列
	typedef vector<vector<vector<bool>>>::size_type choice;          //掉落物的抉择
	typedef vector <vector<vector<vector<bool>>>>::size_type change; //掉落物的变幻
private:
	/***************属性***********************/


	const cols startCol = 4;  //暴风点的归原-行 
	const rows startRow = 4; //暴风点的归原-列
	cols stormCol = startCol; //风暴点的当前值 - col;
	rows stormRow = startRow; //风暴点的当前值 - row

	choice dropNumNow = 0;        //当前掉落物的抉择 - 根据数字选对象
	choice dropNumFutr;       //下次掉落物的抉择 - 根据数字选对象
	change dropNowchState = 0;    //掉落物当前状态
	vector<vector <bool>> Icarus = { {0} }; //Icarus - 给予初始值
	Map playMap;  //地图对象

	//面向下一步
	cols futrCol = 0; //风暴点变形后 - col;
	rows futrRow = 0; //风暴点变形后 - row

	/******方法*******/
	void getIcarus();//更新Icarus矩阵
	/*
	* 方法作用：  
	*	Icarus的勾勒函数 - 根据风暴点当前的位置勾勒出掉落物 （更高Map:map 面向用户）
	* 输入：
	*	NULL
	* 输出：
	*	this
	*/
	RuningEls& born(); //Icarus的勾勒函数
	

};

/**********************接口声明*******************************/
/*
函数作用:
	游戏控制 - 作为RuningEls的友元 控制游戏的进程
返回值:
	void 
*/
void gameRun();
/*
函数作用 
	辅助函数，对于一个vector<bool> 给定范围中 快速确定是否有true值
形式参数
	vector<bool>& arr 目标vector容器
	vector<bool>::size_type start 检测的起始地址
	vector<bool>::size_type end   检测的结束地址
*/
inline bool umpirage(vector<bool>& arr, vector<bool>::size_type start, vector<bool>::size_type end);


/******************成员定义************************/
/****方法定义****/
//Icarus的勾勒函数
RuningEls& RuningEls::born(){
	//根据风暴点位置, 当前形状， 当前形状的姿态勾勒出坠落物
	for (cols i = 0; i < Icarus.size(); i++){
		for (rows j = 0; j < Icarus[i].size(); j++){
			//如果Icarus当前点为1  同时目标位置没有值 才会被覆写
			if(Icarus[i][j] && !playMap.map[startCol - i][startRow + j]){
				playMap.map[startCol - i][startRow + j] = Icarus[i][j];
			}
			
		}
	}

	return *this;
} 

//更新Icarus矩阵
void RuningEls::getIcarus(){
	Icarus = getState(dropNumNow, dropNowchState);
}

/**********************接口定义***********人************/
void gameRun(){
	RuningEls runNow;
	runNow.playMap.drawOriginalMap();//绘制场地
	runNow.playMap.drawNow();//
	while(1){//游戏入口
		//判断 如果伊卡利亚的潮水漫过天空 游戏将会结束
		if(umpirage(runNow.playMap.map[1],1, runNow.playMap.mapWidth-1)){
			break;
		}

		//坠落前 更新状态
		srand((int)time(0));//注入随机数种子
		runNow.dropNumNow = runNow.dropNumFutr; //当前掉落物变为未来的
		runNow.dropNumFutr = random(7);         //未来的值需要重新随机

		runNow.getIcarus();
		runNow.born();
		runNow.playMap.drawNow();
		while(1){//第二重循环 - Icarus的坠落
			
			for (int i = 0; i <= 10; i++) {//每次坠落 Icarus有十次机会调整姿态
				Sleep(100);//每0.1秒有一次机会转变姿态
				//使用空格触发翻转判定，使用左右触发位移判定

				//姿态转换有效判定 - 失败则无视本次姿态转换


				//姿态转换有效判定成功 - 实行姿态变化


			}
			//坠落完成 开启下一个回合

		}
	}
	//勾勒出最初Icarus 

	//一个循环

}

inline bool umpirage(vector<bool>& arr, vector<bool>::size_type start, vector<bool>::size_type end) {
	for (vector<bool>::size_type i = start; i < end; i++) {
		if (arr[i]) return true;
	}
	return false;
}

#endif // !RUNINGELS



