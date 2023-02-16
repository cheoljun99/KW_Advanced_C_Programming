#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tm
{
	int money;
	char category[20];
	struct tm *nexttm;
}TM;
FILE *fpp;
FILE *fps;
struct sum
{
	int password;
	int sumfood;
	int sumtrans;
	int sumclo;
	int sument;
	int sumetc;
	int sum;
}sum[20];
TM *firsttm = NULL;
TM *lasttm = NULL;
void add(int num, char string[]) {
	TM *newtm = (TM *)malloc(sizeof(TM));
	newtm->money = num;
	strcpy(newtm->category, string);
	newtm->nexttm = NULL;
	if (firsttm == NULL) {
		firsttm = newtm;
		lasttm = newtm;
	}
	else {
		lasttm->nexttm = newtm;
		lasttm = newtm;
	}
}
void menu()
{
	int menun, num, a, i = 0, c;
	printf("1.�Է� 2.��� 3.�� : ");
	scanf("%d", &menun);
	if (menun == 1) {
		fps = fopen("0000.txt", "a+");

		int i = 0;
		while (feof(fps) == 0)
		{
			fscanf(fps, "%d %d %d %d %d %d %d", &sum[i].password, &sum[i].sumfood, &sum[i].sumtrans, &sum[i].sumclo, &sum[i].sument, &sum[i].sumetc, &sum[i].sum);
			i++;
		}
		fclose(fps);
		int password, k = -1;
		printf("��й�ȣ�� �Է��Ͻÿ� : ");
		scanf("%d", &password);

		for (int j = 0; j < i; j++) {
			if (password == sum[j].password)
				k = j;
		}
		if (k != -1)
		{
			printf("����� �� ���� ��й�ȣ �Դϴ�. \n");
			return;
		}
		printf("��й�ȣ�� %d�� �½��ϱ�?\n��й�ȣ�� �ٽ� �����Ϸ��� 0�� �Է��ϰ� �ƴϸ� �ٸ� ���ڸ� �Է��Ͻÿ�. : ", password);
		scanf("%d", &c);
		if (c == 0)
			return;
		fpp = fopen("0000.txt", "a+");
		fprintf(fpp, "%d ", password);
		while (1) {
			int n;
			char c[20];
			printf("-------------------------\n");
			printf("�׸� �Է��Ϸ��� -1�� �Է��Ͻÿ�.\n�󸶸� ����ϼ̽��ϱ�? (���� : ��) : ");
			scanf("%d", &n);
			if (n == -1)
				break;
			printf("-------------------------\n");
			printf("���ó : ����, ����, �Ƿ�, ����, ��Ÿ (������ �͸� �Է��Ͻÿ�.)\n��� ����ϼ̽��ϱ�? : ");
			scanf("%s", c);
			add(n, c);
		}
		TM *temp = firsttm;
		int sum, sumfood = 0, sumtrans = 0, sumclo = 0, sument = 0, sumetc = 0;
		char str1[] = "����";
		char str2[] = "����";
		char str3[] = "�Ƿ�";
		char str4[] = "����";
		char str5[] = "��Ÿ";
		while (temp != NULL) {
			if (!strcmp(temp->category, str1))
				sumfood = sumfood + temp->money;
			else if (!strcmp(temp->category, str2))
				sumtrans = sumtrans + temp->money;
			else if (!strcmp(temp->category, str3))
				sumclo = sumclo + temp->money;
			else if (!strcmp(temp->category, str4))
				sument = sument + temp->money;
			else if (!strcmp(temp->category, str5))
				sumetc = sumetc + temp->money;
			temp = temp->nexttm;
		}
		sum = sumfood + sumclo + sumtrans + sument + sumetc;
		fprintf(fpp, "%d ", sumfood);
		fprintf(fpp, "%d ", sumtrans);
		fprintf(fpp, "%d ", sumclo);
		fprintf(fpp, "%d ", sument);
		fprintf(fpp, "%d ", sumetc);
		fprintf(fpp, "%d ", sum);
		fprintf(fpp, "\n");
		fclose(fpp);
		firsttm = NULL;
	}
	else if (menun == 2)
	{
		fps = fopen("0000.txt", "rt");
		int data;
		if (fscanf(fps, "%d", &data) == EOF)
		{
			printf("��� ������ ����\n");
			fclose(fps);
			return;
		}
		fps = fopen("0000.txt", "rt");
		int i = 0;
		while (feof(fps) == 0)
		{
			fscanf(fps, "%d %d %d %d %d %d %d", &sum[i].password, &sum[i].sumfood, &sum[i].sumtrans, &sum[i].sumclo, &sum[i].sument, &sum[i].sumetc, &sum[i].sum);
			i++;
		}

		fclose(fps);
		int passwordp, k = -1;
		printf("��й�ȣ�� �Է��Ͻÿ� : ");
		scanf("%d", &passwordp);
		for (int j = 0; j < i; j++) {
			if (passwordp == sum[j].password)
				k = j;

		}
		if (k == -1)
		{
			printf("�߸��Է��ϼ̽��ϴ�. \n");
			return;
		}
		printf("-------------------------\n");
		printf("���� �׸� �� %d���� ���\n", sum[k].sumfood);
		printf("���� �׸� �� %d���� ���\n", sum[k].sumtrans);
		printf("�Ƿ� �׸� �� %d���� ���\n", sum[k].sumclo);
		printf("���� �׸� �� %d���� ���\n", sum[k].sument);
		printf("��Ÿ �׸� �� %d���� ���\n", sum[k].sumetc);
		printf("�� %d���� ���\n", sum[k].sum);
		printf("-------------------------\n");
		return;

	}

	else if (menun == 3)
	{
		int password, data, i = 0;
		float foodavg = 0, transavg = 0, cloavg = 0, enteravg = 0, etcavg = 0;
		int sumsumfood = 0, sumsumtrans = 0, sumsumclo = 0, sumsument = 0, sumsumetc = 0;

		fps = fopen("0000.txt", "r");
		if (fscanf(fps, "%d", &data) == EOF) {
			printf("��� ������ ����\n");
			return;
		}
		fclose(fps);
		fps = fopen("0000.txt", "r");

		while (feof(fps) == 0) {
			fscanf(fps, "%d %d %d %d %d %d %d\n", &sum[i].password, &sum[i].sumfood, &sum[i].sumtrans, &sum[i].sumclo, &sum[i].sument, &sum[i].sumetc, &sum[i].sum);
			i++;
		}
		fclose(fps);
		printf("��й�ȣ�� �Է��Ͻÿ� : ");
		scanf("%d", &password);
		for (int j = 0; j < i; j++) {
			sumsumfood += sum[j].sumfood;
			sumsumtrans += sum[j].sumtrans;
			sumsumclo += sum[j].sumclo;
			sumsument += sum[j].sument;
			sumsumetc += sum[j].sumetc;
		}
		foodavg = sumsumfood / i;
		transavg = sumsumtrans / i;
		cloavg = sumsumclo / i;
		enteravg = sumsument / i;
		etcavg = sumsumetc / i;
		int j = -1;
		for (int k = 0; k < i; k++)
		{
			if (password == sum[k].password)
			{
				j = k;
			}
		}
		if (j == -1)
		{

			printf("�߸��Է��ϼ̽��ϴ�. \n");
			return;
		}
		float sumfood = sum[j].sumfood;
		float sumtrans = sum[j].sumtrans;
		float sumclo = sum[j].sumclo;
		float sumenter = sum[j].sument;
		float sumetc = sum[j].sumetc;
		float arr[5] = { sumfood,sumtrans,sumclo,sumenter,sumetc };
		char * crr[5] = { "����","����","�Ƿ�","����","��Ÿ" };
		float brr[5] = { foodavg,transavg,cloavg,enteravg,etcavg };
		printf("-------------------------\n");
		for (int k = 0; k < 5; k++)
		{
			if (arr[k] >= (brr[k] * 2) && (brr[k] != 0))//arr[i]�� ��տ� 2�踸ŭ Ŭ��
			{

				printf("%s�� �κп��� ����� �� 200%% �̻��� ����ϼ̽��ϴ�.(���Һ� �ɰ��մϴ�.) \n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 1.5) && (brr[k] != 0) && arr[k] < (brr[k] * 2))//arr[k]�� ��տ� 1.5�踸ŭ ũ�ų� ���� 2�躸�� ���� ��
			{

				printf("%s�� �κп��� ����� �� 150%%~199%%�� ����ϼ̽��ϴ�.(���Һ��Դϴ�.) \n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 1) && (brr[k] != 0) && arr[k] < (brr[k] * 1.5))//arr[k]�� ��տ� 1�踸ŭ ũ�ų� ���� 1.5�躸�� ���� ��
			{
				printf("%s�� �κп��� ����� �� 100%%~149%%�� ����ϼ̽��ϴ�.(���Һ� ������ ���Դϴ�.)\n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 0.5) && (brr[k] != 0) && arr[k] < (brr[k] * 1))//arr[k]�� ��տ� 0.5�踸ŭ ũ�ų� ���� 1�躸�� ���� ��
			{
				printf("%s�� �κп��� ����� �� 50%%~99%%�� ����ϼ̽��ϴ�.(�������� �����Դϴ�.) \n", crr[k]);
			}
			else if (arr[k] > 0 && (brr[k] != 0) && arr[k] < (brr[k] * 0.5))//arr[k]�� 0�̾ƴϸ�  arr[k]�� ����� 0.5�� ���� ���� �� 
			{
				printf("%s�� �κп��� ����� �� 1%%~49%�� ����ϼ̽��ϴ�.(�̻����� �����Դϴ�.) \n", crr[k]);
			}
			else if (arr[k] == 0 && (brr[k] != 0))//arr[k]�� ������� �ʾ����� �׸��� ��հ��� 0�� �ƴҶ�
			{
				printf("%s�� �κ��� ������� �����̽��ϴ�.\n", crr[k]);
			}
			else if (arr[k] == 0 && (brr[k] == 0))//arr[k]�� ������� �ʾ����� �׸��� ��հ��� 0�� ��
			{
				printf("%s�� �κ��� ������� �����̽��ϴ�.\n", crr[k]);
			}
		}
		printf("-------------------------\n");
	}
	else
		printf("�ٽ� �Է��Ͻÿ�.\n");
}
int main()
{
	while (1)
		menu();
}