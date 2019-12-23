#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;






int main()
{
	double array[4][4] = { 0.0 };//如果数据量过大 则需要把 array 定义成static类型，
	//因为默认的堆栈大小容量不够，可以放到静态存储区

	ifstream infile;//定义文件流对象

	infile.open("E:\\graduating_design\\PCLTest\\ICP_begin.txt");//打开文档

	//定义
	double* ptr = &array[0][0];
	while (!infile.eof())
	{
		infile >> *ptr;//这个是把文档里面的数对应在ptr位置的数值上
		ptr++;
	}

	infile.close();

	cout << setiosflags(ios::fixed) << setprecision(6);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << setfill('0') << setw(10) <<array[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;

}


