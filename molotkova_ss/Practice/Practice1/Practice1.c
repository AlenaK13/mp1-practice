#include <stdio.h> 
#include <math.h> 
#include <locale.h> 

void main()
{ 
    float dsp=0.65; float dvp=0.82; float der=0.5; // ���,���,��������� ������ � ��3
	float h, w, d; // �������� ������������� ������: ������, ������, �������
	float kolvopolok;
	float mz, mb, mk, md, mp, m;//�����
	float t1, t2, t3, t4;// �������
	t1=0.5;//5 �� � ��(�1)
	t2=1.5;// 15�� � ��(�2)
	t3=1.5;//15 �� � ��(�3)
	t4=1;// ��(�4)
    setlocale(LC_ALL, "Russian"); 

    printf("������� ������\n" ); 
	scanf("%f", &h); 
	printf("������� ������\n"); 
	scanf("%f", &w); 
	printf("������� �������\n"); 
    scanf("%f", &d); 
	kolvopolok=floor(h/40);
    if ((180<h)&&(h<220)&&(80<w)&&(w<120)&&(50<d)&&(d<90))
	{
		mz=h*w*t1*dvp;
		mb=2*h*d*t2*dsp;
		mk=2*dsp*w*d*t3;
		md=2*h*w*t4*der;
		mp=d*dsp*w*kolvopolok;
		m= (mz+mb+mk+md+mp)/1000;
		
		printf("����� ����� %0.f ��\n",m);
	}
	else printf("��������� �������� �� ������������� �������");
}