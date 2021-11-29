#pragma once
#ifndef RUNINGELS
#define RUNINGELS

#define random(x) rand()%(x) 
class RuningEls {

public:
	/*���캯��*/
	RuningEls(){
		srand((int)time(0));//���������
		dropNumFutr = random(7);//��ֵ
	};


	/*��Ԫ*/
	friend void gameRun();

	typedef vector<bool>::size_type cols;        //��
	typedef vector<vector<bool>>::size_type rows;//��
	typedef vector<vector<vector<bool>>>::size_type choice;          //������ľ���
	typedef vector <vector<vector<vector<bool>>>>::size_type change; //������ı��
private:
	/***************����***********************/


	const cols startCol = 4;  //�����Ĺ�ԭ-�� 
	const rows startRow = 4; //�����Ĺ�ԭ-��
	cols stormCol = startCol; //�籩��ĵ�ǰֵ - col;
	rows stormRow = startRow; //�籩��ĵ�ǰֵ - row

	choice dropNumNow = 0;        //��ǰ������ľ��� - ��������ѡ����
	choice dropNumFutr;       //�´ε�����ľ��� - ��������ѡ����
	change dropNowchState = 0;    //�����ﵱǰ״̬
	vector<vector <bool>> Icarus = { {0} }; //Icarus - �����ʼֵ
	Map playMap;  //��ͼ����

	//������һ��
	cols futrCol = 0; //�籩����κ� - col;
	rows futrRow = 0; //�籩����κ� - row

	/******����*******/
	void getIcarus();//����Icarus����
	/*
	* �������ã�  
	*	Icarus�Ĺ��պ��� - ���ݷ籩�㵱ǰ��λ�ù��ճ������� ������Map:map �����û���
	* ���룺
	*	NULL
	* �����
	*	this
	*/
	RuningEls& born(); //Icarus�Ĺ��պ���
	

};

/**********************�ӿ�����*******************************/
/*
��������:
	��Ϸ���� - ��ΪRuningEls����Ԫ ������Ϸ�Ľ���
����ֵ:
	void 
*/
void gameRun();
/*
�������� 
	��������������һ��vector<bool> ������Χ�� ����ȷ���Ƿ���trueֵ
��ʽ����
	vector<bool>& arr Ŀ��vector����
	vector<bool>::size_type start ������ʼ��ַ
	vector<bool>::size_type end   ���Ľ�����ַ
*/
inline bool umpirage(vector<bool>& arr, vector<bool>::size_type start, vector<bool>::size_type end);


/******************��Ա����************************/
/****��������****/
//Icarus�Ĺ��պ���
RuningEls& RuningEls::born(){
	//���ݷ籩��λ��, ��ǰ��״�� ��ǰ��״����̬���ճ�׹����
	for (cols i = 0; i < Icarus.size(); i++){
		for (rows j = 0; j < Icarus[i].size(); j++){
			//���Icarus��ǰ��Ϊ1  ͬʱĿ��λ��û��ֵ �Żᱻ��д
			if(Icarus[i][j] && !playMap.map[startCol - i][startRow + j]){
				playMap.map[startCol - i][startRow + j] = Icarus[i][j];
			}
			
		}
	}

	return *this;
} 

//����Icarus����
void RuningEls::getIcarus(){
	Icarus = getState(dropNumNow, dropNowchState);
}

/**********************�ӿڶ���***********��************/
void gameRun(){
	RuningEls runNow;
	runNow.playMap.drawOriginalMap();//���Ƴ���
	runNow.playMap.drawNow();//
	while(1){//��Ϸ���
		//�ж� ����������ǵĳ�ˮ������� ��Ϸ�������
		if(umpirage(runNow.playMap.map[1],1, runNow.playMap.mapWidth-1)){
			break;
		}

		//׹��ǰ ����״̬
		srand((int)time(0));//ע�����������
		runNow.dropNumNow = runNow.dropNumFutr; //��ǰ�������Ϊδ����
		runNow.dropNumFutr = random(7);         //δ����ֵ��Ҫ�������

		runNow.getIcarus();
		runNow.born();
		runNow.playMap.drawNow();
		while(1){//�ڶ���ѭ�� - Icarus��׹��
			
			for (int i = 0; i <= 10; i++) {//ÿ��׹�� Icarus��ʮ�λ��������̬
				Sleep(100);//ÿ0.1����һ�λ���ת����̬
				//ʹ�ÿո񴥷���ת�ж���ʹ�����Ҵ���λ���ж�

				//��̬ת����Ч�ж� - ʧ�������ӱ�����̬ת��


				//��̬ת����Ч�ж��ɹ� - ʵ����̬�仯


			}
			//׹����� ������һ���غ�

		}
	}
	//���ճ����Icarus 

	//һ��ѭ��

}

inline bool umpirage(vector<bool>& arr, vector<bool>::size_type start, vector<bool>::size_type end) {
	for (vector<bool>::size_type i = start; i < end; i++) {
		if (arr[i]) return true;
	}
	return false;
}

#endif // !RUNINGELS



