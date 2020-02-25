#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

static int L1[5] = { 0 };
static int onlyL1[5] = { 0 };
static int onlyL1_InfoList[5] = { 0 };
static int L2[20] = { 0 };
static int L3[200] = { 0 };
static int RAM[500] = { 0 };
static int HD[5000];

static int L1_InfoList[5] = { 0 }; //���������� �����ϴ� �迭
static int L2_InfoList[20] = { 0 };
static int L3_InfoList[200] = { 0 };
static int RAM_InfoList[500] = { 0 };

static int hit = 0; //��Ʈ��
static int num = 0; //���� ���� Ƚ��
static int miss = 0; //�̽���
static int onlyhit = 0;
static int onlynum = 0;
static int onlymiss = 0;
static int twicehit = 0;
static int twicemiss = 0;

static int R1 = 0, R2 = 0; //��������

void onlyL1_func(int a);
void onlyHD_func(int a);
void onlyL1_store(int a);
void L1_func(int a);
void L2_func(int a);
void L3_func(int a);
void RAM_func(int a);
void HD_func(int a);
void L1_store(int a);
void L2_store(int a);
void L3_store(int a);
void RAM_store(int a);

int main()
{
	srand(time(0));

	onlyL1_InfoList[0] = 1;
	L1_InfoList[0] = 1;
	L2_InfoList[0] = 1;
	L3_InfoList[0] = 1;
	RAM_InfoList[0] = 1;

	for (int i = 0; i < 5000; i++)
	{
		HD[i] = i + 1;
	}
	int a, b;

	clock_t start, end;
	double result;
	start = clock(); //���� �ð� ���� ���� 

	for (int i = 0; i < 10000; i++)
	{
		a = rand() % 5001;
		b = rand() % 5001;
		R1 = 0;
		L1_func(a);
		L1_func(b);
	}

	end = clock(); //�ð� ���� �� 
	result = (double)(end - start); //�ð� ���� ���(ms�� ��ϵ�)

	cout << a << " + " << b << "�� ����" << endl;
	cout << "����� ���������� ���� " << R1 << ", " << R2 << endl;
	cout << endl;

	cout << "L1�� ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << L1[i] << " ";
	}
	cout << endl;

	cout << "\nL2�� ����" << endl;
	for (int i = 0; i < 20; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << L2[i] << " ";
	}
	cout << endl;

	cout << "\nL3�� ����" << endl;
	for (int i = 0; i < 200; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << L3[i] << " ";
	}
	cout << endl;

	cout << "\nRAM�� ����" << endl;
	for (int i = 0; i < 500; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << RAM[i] << " ";
	}
	cout << endl;

	cout << "\n���� ���� Ƚ���� " << num << "ȸ" << endl;
	cout << "ĳ�� ��Ʈ ���� " << hit / static_cast<double>(num) * 100 << "%" << endl;
	cout << "ĳ�� �̽� ���� " << miss / static_cast<double>(num) * 100 << "%" << endl;
	cout << "�� ������ ���� �ð��� " << ((result) / CLOCKS_PER_SEC) << " ��" << endl; //ms�� ��ϵ� result�� �ʷ� �ٲ� ���

	L1[5] = { 0 };
	L2[20] = { 0 };
	L3[200] = { 0 };
	RAM[500] = { 0 };

	L1_InfoList[5] = { 0 }; //���������� �����ϴ� �迭
	L2_InfoList[20] = { 0 };
	L3_InfoList[200] = { 0 };
	RAM_InfoList[500] = { 0 };

	hit = 0; //��Ʈ��
	num = 0; //���� ���� Ƚ��
	miss = 0; //�̽���

	clock_t start1, end1;
	double result1;
	start1 = clock(); //���� �ð� ���� ���� 

	cout << "\n** �������� -1 **" << endl;
	cout << "\n<L1 ĳ�ÿ뷮�� 2�谡 �� ������ ���� ����>" << endl;
	for (int i = 0; i < 10; i++)
	{
		a = rand() % 5001;
		b = rand() % 5001;
		R1 = 0;
		L1_func(a);
		L1_func(b);
	}

	end1 = clock(); //�ð� ���� �� 
	result1 = (double)(end1 - start1); //�ð� ���� ���(ms�� ��ϵ�)

	cout << "L1�� ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << L1[i] << " ";
	}
	cout << endl;
	cout << "���� ���� Ƚ���� 10ȸ" << endl;
	cout << "ĳ�� ��Ʈ ���� " << hit / static_cast<double>(num) * 100 << "%" << endl;
	cout << "ĳ�� �̽� ���� " << miss / static_cast<double>(num) * 100 << "%" << endl;
	cout << "������ ���� �ð��� " << ((result1) / CLOCKS_PER_SEC) << " ��" << endl;

	cout << "\n** �������� -2 **" << endl;
	cout << "\n<L1 ĳ�ø� ���� �� ���� ����>" << endl;

	clock_t start2, end2;
	double result2;
	start2 = clock(); //���� �ð� ���� ���� 

	for (int i = 0; i < 10000; i++)
	{
		a = rand() % 5001;
		b = rand() % 5001;
		R1 = 0;
		onlyL1_func(a);
		onlyL1_func(b);
	}

	end2 = clock(); //�ð� ���� �� 
	result2 = (double)(end2 - start2); //�ð� ���� ���(ms�� ��ϵ�)

	cout << "���� ���� Ƚ���� " << onlynum << "ȸ" << endl;
	cout << "L1�� ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << onlyL1[i] << " ";
	}
	cout << endl;
	cout << "ĳ�� ��Ʈ ���� " << onlyhit / static_cast<double>(onlynum) * 100 << "%" << endl;
	cout << "ĳ�� �̽� ���� " << onlymiss / static_cast<double>(onlynum) * 100 << "%" << endl;
	cout << "L1�� ���� ���� ������ ���� �ð��� " << ((result2) / CLOCKS_PER_SEC) << " ��" << endl;

	cout << "\n<L1, L2, L3 ĳ�ð� ���� �� ���� ����>" << endl;
	clock_t start3, end3;
	double result3;
	start3 = clock(); //���� �ð� ���� ���� 

	for (int i = 0; i < 10000; i++)
	{
		a = rand() % 5001;
		b = rand() % 5001;
		R1 = 0;
		L1_func(a);
		L1_func(b);
	}

	end3 = clock(); //�ð� ���� �� 
	result3 = (double)(end3 - start3); //�ð� ���� ���(ms�� ��ϵ�)

	cout << "L1�� ����" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << L1[i] << " ";
	}
	cout << endl;

	cout << "\nL2�� ����" << endl;
	for (int i = 0; i < 20; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << L2[i] << " ";
	}
	cout << endl;

	cout << "\nL3�� ����" << endl;
	for (int i = 0; i < 200; i++)
	{
		if ((i != 0) && (i % 10 == 0))
			cout << endl;
		cout << L3[i] << " ";
	}
	cout << endl;
	cout << "\n���� ���� Ƚ���� " << num << "ȸ" << endl;
	cout << "ĳ�� ��Ʈ ���� " << hit / static_cast<double>(num) * 100 << "%" << endl;
	cout << "ĳ�� �̽� ���� " << miss / static_cast<double>(num) * 100 << "%" << endl;
	cout << "�� ������ ���� �ð��� " << ((result3) / CLOCKS_PER_SEC) << " ��" << endl; //ms�� ��ϵ� result�� �ʷ� �ٲ� ���

	system("pause");
	return 0;
}

// L1���� �ٷ� HDD�� ���� �Լ�
void onlyL1_func(int a)
{
	bool tf = false;
	onlynum++;
	for (int i = 0; i < 5; i++)//ã��
	{
		if (tf)
			break;
		if (onlyL1[i] == a)
		{
			onlyhit++;
			tf = true;
			if (R1 == 0)
				R1 = a;
			else
				R2 = a;
		}
	}
	if (tf == false)
	{
		onlymiss++;
		onlyHD_func(a);
	}
}

void onlyHD_func(int a)
{
	bool tf = false;
	onlynum++;
	for (int i = 0; i < 5000; i++)//ã��
	{
		if (tf)
			break;
		if (HD[i] == a)
		{
			tf = true;
			onlyL1_store(a);
		}
	}
}

void onlyL1_store(int a)
{
	bool tf = false;
	onlynum++;
	for (int i = 0; i < 5; i++)
	{
		if (tf)
			break;
		if (onlyL1[i] == 0)
		{
			tf = true;
			onlyL1[i] = a;
			onlyL1_func(a);
		}
	}
	if (tf == false)
	{
		//���Լ��� �̿�
		for (int i = 0; i < 5; i++)
		{
			if (onlyL1_InfoList[i] == 1)
			{
				onlyL1[i] = a;
				onlyL1_InfoList[i] = 0;
				onlyL1_InfoList[(i + 1) % 5] = 1;

				break;
			}
		}
		onlyL1_func(a);
	}
}

void L1_func(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 5; i++)//ã��
	{
		if (tf)
			break;
		if (L1[i] == a)
		{
			hit++;
			tf = true;
			if (R1 == 0)
				R1 = a;
			else
				R2 = a;
		}
	}
	if (tf == false)
	{
		miss++;
		L2_func(a);
	}
}

void L2_func(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 20; i++)//ã��
	{
		if (tf)
			break;
		if (L2[i] == a)
		{
			hit++;
			tf = true;
			L1_store(a);
		}
	}
	if (tf == false)
	{
		miss++;
		L3_func(a);
	}
}

void L3_func(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 200; i++)//ã��
	{
		if (tf)
			break;
		if (L3[i] == a)
		{
			hit++;
			tf = true;
			L2_store(a);
		}
	}
	if (tf == false)
	{
		miss++;
		RAM_func(a);
	}
}

void RAM_func(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 500; i++)//ã��
	{
		if (tf)
			break;
		if (RAM[i] == a)
		{
			tf = true;
			L3_store(a);
		}
	}
	if (tf == false)
	{
		miss++;
		HD_func(a);
	}
}

void HD_func(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 5000; i++)//ã��
	{
		if (tf)
			break;
		if (HD[i] == a)
		{
			tf = true;
			RAM_store(a);
		}
	}
}

void L1_store(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 5; i++)
	{
		if (tf)
			break;
		if (L1[i] == 0)
		{
			tf = true;
			L1[i] = a;
			L1_func(a);
		}
	}
	if (tf == false)
	{
		//���Լ��� �̿�
		for (int i = 0; i < 5; i++)
		{
			if (L1_InfoList[i] == 1)
			{
				L1[i] = a;
				L1_InfoList[i] = 0;
				L1_InfoList[(i + 1) % 5] = 1;

				break;
			}
		}
		L1_func(a);
	}
}

void L2_store(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 20; i++)
	{
		if (tf)
			break;
		if (L2[i] == 0)
		{
			tf = true;
			L2[i] = a;
			L1_store(a);
		}
	}
	if (tf == false)
	{
		//���Լ��� �̿�
		for (int i = 0; i < 20; i++)
		{
			if (L2_InfoList[i] == 1)
			{
				L2[i] = a;
				L2_InfoList[i] = 0;
				L2_InfoList[(i + 1) % 20] = 1;

				break;
			}
		}
		L1_store(a);
	}
}

void L3_store(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 5; i++)
	{
		if (tf)
			break;
		if (L3[i] == 0)
		{
			tf = true;
			L3[i] = a;
			L2_store(a);
		}
	}
	if (tf == false)
	{
		//���Լ��� �̿�
		for (int i = 0; i < 200; i++)
		{
			if (L3_InfoList[i] == 1)
			{
				L3[i] = a;
				L3_InfoList[i] = 0;
				L3_InfoList[(i + 1) % 200] = 1;

				break;
			}
		}
		L2_store(a);
	}
}

void RAM_store(int a)
{
	bool tf = false;
	num++;
	for (int i = 0; i < 5; i++)
	{
		if (tf)
			break;
		if (RAM[i] == 0)
		{
			tf = true;
			RAM[i] = a;
			L3_store(a);
		}
	}
	if (tf == false)
	{
		//���Լ��� �̿�
		for (int i = 0; i < 500; i++)
		{
			if (RAM_InfoList[i] == 1)
			{
				RAM[i] = a;
				RAM_InfoList[i] = 0;
				RAM_InfoList[(i + 1) % 500] = 1;

				break;
			}
		}
		L3_store(a);
	}
}