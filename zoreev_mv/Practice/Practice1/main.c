#include <stdio.h>
void main () {
	double h, d, w, Qdvp, Qdsp, Qder, m, back, bottom, top,door,polka;
	printf("Enter h,d,w in mm");
	scanf("%lflflf",h,d,w);
	scanf("%lflflf",Qdvp,Qdsp,Qder);
	
	if ((Qdvp <= 0) || (Qdsp <= 0) || (Qder <= 0) || (h < 1800) || (h>2200) || (w < 800) || (w > 1000) || (d < 500) || (d > 900)) {
		printf("Input error");
		return;
	}

	//����� ������ ������
	
	back=h*w*5*Qdvp;

	//����� ���� �������

	bottom=h*d*30*Qdsp;

	//����� ���� ��������� ������

	top=w*d*30*Qdsp;

	//����� �������� ������

	door=h*w*10*Qder;

	//����� �����



	//��������� �����

	m=back+bottom+top+door+polka;
	printf("mass: %lf",m);
}


