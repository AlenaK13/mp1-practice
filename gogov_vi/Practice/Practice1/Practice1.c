#include <stdio.h>
#include <math.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Russian");
	double dsp_m, dsp, dvp_m, dvp, wood_m, wood, h, w, d;
	double sidewm, swm, cm, dm, sm, m;
	int nof;
	printf("������� ��������� ���(��/�^3): ");
	scanf("%lf", &dsp_m);
	if (dsp_m < 0) {
		printf(" ������ \a \n ��������� ��� ������ ���� ������ 0\n");
		return;
	}
	printf("������� ��������� ���(��/�^3): ");
	scanf("%lf", &dvp_m);
	if (dvp_m < 0) {
		printf(" ������ \a \n ��������� ��� ������ ���� ������ 0\n");
		return;
	}
	printf("������� ��������� ������(��/�^3): ");
	scanf("%lf", &wood_m);
	if (wood_m < 0) {
		printf(" ������ \a \n ��������� ������ ������ ���� ������ 0\n");
		return;
	}

	dsp = dsp_m / 1000000;
	dvp = dvp_m / 1000000;
	wood = wood_m / 1000000;

	printf("������� ������ ����� � ����������� �� 180 �� 220: ");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220)) {
		printf(" ������ \a \n ������� ������������ ������\n");
		return;
	}

	printf("������� ������ ����� � ����������� �� 80 �� 120: ");
	scanf("%lf", &w);
	if ((w < 80) || (w > 120)) {
		printf(" ������ \a \n ������� ������������ ������\n");
		return;
	}

	printf("������� ������� ����� � ����������� �� 50 �� 90: ");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90)) {
		printf(" ������ \a \n ������� ������������ ������\n");
		return;
	}
	nof = h / 40;
	sidewm = dvp*h*w*0.5;
	swm = 2 * dsp* h*d*1.5;
	cm = 2 * dsp*w*d*1.5;
	dm = wood*h*w * 1;
	sm = dsp*nof*(w - 3)*d*1.5;
	m = sidewm + swm + cm + dm + sm;
	printf("����� ����� = %.2lf ���������\n", m);
}