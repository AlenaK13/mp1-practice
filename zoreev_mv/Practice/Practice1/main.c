#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() {
	setlocale(LC_ALL, "Russian");
	double h, w, d, dvp, dsp, wood,back, side, top, door, shelf, M;
	int n;
	printf("������� ������, ������ � ������� ����� � ��\n");
	scanf("%lf%lf%lf",&h,&w,&d);
	printf("������� ��������� ���, ��� � ������ � ��/�^3\n");
	scanf("%lf%lf%lf",&dvp,&dsp,&wood);
	
	if ((dvp < 0) || (dsp < 0) || (wood < 0) || (h < 180) || (h > 220) || (d < 50) || (d > 90) || (w < 80) || (w > 100)) {
		printf("������ �����\n");
		return;
	}

	n = floor(h/40); //������ ��� 40�� ��� ���������� ����� �������� ����������� �����, ����� ������� ��� ������ ������� 40 ������� ����� ����� �������� ������� ������
	back = (h * w * 0.5 * dvp); //����� �� 1000000 ����� �������� ��^3 � �^3
	side = (h * d* 1.5 * dsp);
	top = (w * d * 1.5 * dsp);
	door = (h * w * 1 * wood);
	shelf = (n * d * (w-3) * 1.5 * dsp); //�������� 3�� �.� �������� �� ���������, � ������ ����� ����� ���

	M = (back + side + top + door + shelf) / 1000000;  //����� �� ������� �.� ��������� ������� ��/�^3, � ������� ������� � ��
	printf("����� �����: %lf��\n",M);
}
