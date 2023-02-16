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
	printf("1.입력 2.출력 3.비교 : ");
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
		printf("비밀번호를 입력하시오 : ");
		scanf("%d", &password);

		for (int j = 0; j < i; j++) {
			if (password == sum[j].password)
				k = j;
		}
		if (k != -1)
		{
			printf("사용할 수 없는 비밀번호 입니다. \n");
			return;
		}
		printf("비밀번호가 %d가 맞습니까?\n비밀번호를 다시 설정하려면 0을 입력하고 아니면 다른 숫자를 입력하시오. : ", password);
		scanf("%d", &c);
		if (c == 0)
			return;
		fpp = fopen("0000.txt", "a+");
		fprintf(fpp, "%d ", password);
		while (1) {
			int n;
			char c[20];
			printf("-------------------------\n");
			printf("그만 입력하려면 -1을 입력하시오.\n얼마를 사용하셨습니까? (단위 : 원) : ");
			scanf("%d", &n);
			if (n == -1)
				break;
			printf("-------------------------\n");
			printf("사용처 : 음식, 교통, 의류, 오락, 기타 (정해진 것만 입력하시오.)\n어디에 사용하셨습니까? : ");
			scanf("%s", c);
			add(n, c);
		}
		TM *temp = firsttm;
		int sum, sumfood = 0, sumtrans = 0, sumclo = 0, sument = 0, sumetc = 0;
		char str1[] = "음식";
		char str2[] = "교통";
		char str3[] = "의류";
		char str4[] = "오락";
		char str5[] = "기타";
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
			printf("사용 내역이 없음\n");
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
		printf("비밀번호를 입력하시오 : ");
		scanf("%d", &passwordp);
		for (int j = 0; j < i; j++) {
			if (passwordp == sum[j].password)
				k = j;

		}
		if (k == -1)
		{
			printf("잘못입력하셨습니다. \n");
			return;
		}
		printf("-------------------------\n");
		printf("음식 항목에 총 %d원을 사용\n", sum[k].sumfood);
		printf("교통 항목에 총 %d원을 사용\n", sum[k].sumtrans);
		printf("의류 항목에 총 %d원을 사용\n", sum[k].sumclo);
		printf("오락 항목에 총 %d원을 사용\n", sum[k].sument);
		printf("기타 항목에 총 %d원을 사용\n", sum[k].sumetc);
		printf("총 %d원을 사용\n", sum[k].sum);
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
			printf("사용 내역이 없음\n");
			return;
		}
		fclose(fps);
		fps = fopen("0000.txt", "r");

		while (feof(fps) == 0) {
			fscanf(fps, "%d %d %d %d %d %d %d\n", &sum[i].password, &sum[i].sumfood, &sum[i].sumtrans, &sum[i].sumclo, &sum[i].sument, &sum[i].sumetc, &sum[i].sum);
			i++;
		}
		fclose(fps);
		printf("비밀번호를 입력하시오 : ");
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

			printf("잘못입력하셨습니다. \n");
			return;
		}
		float sumfood = sum[j].sumfood;
		float sumtrans = sum[j].sumtrans;
		float sumclo = sum[j].sumclo;
		float sumenter = sum[j].sument;
		float sumetc = sum[j].sumetc;
		float arr[5] = { sumfood,sumtrans,sumclo,sumenter,sumetc };
		char * crr[5] = { "음식","교통","의류","오락","기타" };
		float brr[5] = { foodavg,transavg,cloavg,enteravg,etcavg };
		printf("-------------------------\n");
		for (int k = 0; k < 5; k++)
		{
			if (arr[k] >= (brr[k] * 2) && (brr[k] != 0))//arr[i]가 평균에 2배만큼 클때
			{

				printf("%s비 부분에서 평균의 약 200%% 이상을 사용하셨습니다.(과소비가 심각합니다.) \n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 1.5) && (brr[k] != 0) && arr[k] < (brr[k] * 2))//arr[k]가 평균에 1.5배만큼 크거나 같고 2배보다 작을 때
			{

				printf("%s비 부분에서 평균의 약 150%%~199%%를 사용하셨습니다.(과소비입니다.) \n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 1) && (brr[k] != 0) && arr[k] < (brr[k] * 1.5))//arr[k]가 평균에 1배만큼 크거나 같고 1.5배보다 작을 때
			{
				printf("%s비 부분에서 평균의 약 100%%~149%%를 사용하셨습니다.(과소비 경향이 보입니다.)\n", crr[k]);
			}
			else if (arr[k] >= (brr[k] * 0.5) && (brr[k] != 0) && arr[k] < (brr[k] * 1))//arr[k]가 평균에 0.5배만큼 크거나 같고 1배보다 작을 때
			{
				printf("%s비 부분에서 평균의 약 50%%~99%%를 사용하셨습니다.(정상적인 지출입니다.) \n", crr[k]);
			}
			else if (arr[k] > 0 && (brr[k] != 0) && arr[k] < (brr[k] * 0.5))//arr[k]가 0이아니며  arr[k]가 평균의 0.5배 보다 작을 때 
			{
				printf("%s비 부분에서 평균의 약 1%%~49%를 사용하셨습니다.(이상적인 지출입니다.) \n", crr[k]);
			}
			else if (arr[k] == 0 && (brr[k] != 0))//arr[k]를 사용하지 않았을때 그리고 평균값이 0이 아닐때
			{
				printf("%s비 부분을 사용하지 않으셨습니다.\n", crr[k]);
			}
			else if (arr[k] == 0 && (brr[k] == 0))//arr[k]를 사용하지 않았을때 그리고 평균값이 0일 때
			{
				printf("%s비 부분을 사용하지 않으셨습니다.\n", crr[k]);
			}
		}
		printf("-------------------------\n");
	}
	else
		printf("다시 입력하시오.\n");
}
int main()
{
	while (1)
		menu();
}