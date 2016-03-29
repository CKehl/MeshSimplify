#include "meshSimplify.h"
#include "config.h"
#include "matrix.h"
#include "vector4.h"
#include "solve.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc,char* argv[]){	
	if(argc != 4){
		cout << "error input " << endl;
		return -1;
	}else{
		clock_t start = clock();//��ʱ��ʼ

		MeshSimplify* meshSimplify = new MeshSimplify();
		freopen(argv[1],"r",stdin);
		freopen(argv[2],"w",stdout);
		meshSimplify->setRatio(atof(argv[3]));//���ü���
		meshSimplify->input();//����
		meshSimplify->start();//��ʼ��
		meshSimplify->output();//���

		clock_t finish = clock();//��ʱ�����������ʱ��
		cout << "# time use: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	}
	return 0;
}


/*ע�⣺
0.���ѹ��̵�break�����׳���������
1.vertexgroup�еĽ���Ǵӡ�1��cnt��
2.edgeheap�еı��ǡ�1��cnt��
3.Ϊʲô�����ʱ����ʱѡ�е㣬Ϊʲô��ʱ�ⷽ�̷���0,0,0��-1
*/


/*

Ŀǰ���ȣ���дmeshsimplify����start������

*/