#include "openglDemo.h"
int drawTriangleAndSquare() {
	//һ������
	glTranslatef(0.0f, 0.0f, -1.0f);	 // ����1.5��λ,��������Ļ 6.0
	glColor3f(1.0f, 0.0f, 0.0f);	 // ���õ�ǰɫΪ��ɫ
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();
	glLoadIdentity();	 // ����ģ�͹۲����
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);	 // ��Y����ת������
	glBegin(GL_TRIANGLES);	 // ����������
	glColor3f(1.0f, 0.0f, 0.0f);	 // ���õ�ǰɫΪ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	 // �϶���
	glColor3f(0.0f, 1.0f, 0.0f);	 // ���õ�ǰɫΪ��ɫ
	glVertex3f(-1.0f, -1.0f, 0.0f);	 // ����
	glColor3f(0.0f, 0.0f, 1.0f);	 // ���õ�ǰɫΪ��ɫ
	glVertex3f(1.0f, -1.0f, 0.0f);	 // ����
	glEnd();
	glLoadIdentity();	 // ����ģ�͹۲����
	glTranslatef(1.5f, 0.0f, -6.0f);	 // ����1.5��λ,��������Ļ 6.0
										 //glTranslatef(3.0f, 0.0f, 0.0f);	 // ����3��λ
	glRotatef(rquad, 1.0f, 0.0f, 0.0f);	 // ��X����ת�ı���
	glBegin(GL_QUADS);	 // ����������
	glVertex3f(-1.0f, 1.0f, 0.0f);	 // ����
	glVertex3f(1.0f, 1.0f, 0.0f);	 // ����
	glVertex3f(1.0f, -1.0f, 0.0f);	 // ����
	glVertex3f(-1.0f, -1.0f, 0.0f);	 // ����
	glEnd();	 // �����λ��ƽ���
	rtri += 1.0f;	 // ���������ε���ת����
	rquad -= 1.0f;	 // �����ı��ε���ת����
	return NULL;
}
int drawThreePyramid() {
	glTranslatef(-1.5f, 0.0f, -6.0f);	 // ���� 1.5 ��λ����������Ļ 6.0
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);	 // ��Y����ת������
	glBegin(GL_TRIANGLES);	 // ��ʼ���ƽ������ĸ�����
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	 // �����ε��϶��� (ǰ����)
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // �����ε����¶��� (ǰ����)
	glColor3f(0.0f, 0.0f, 1.0f);	 // ��ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	 // �����ε����¶��� (ǰ����)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	 // �����ε��϶��� (�Ҳ���)
	glColor3f(0.0f, 0.0f, 1.0f);	 // ��ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	 // �����ε����¶��� (�Ҳ���)
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	 // �����ε����¶��� (�Ҳ���)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	 // �����ε��϶��� (�����)
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	 // �����ε����¶��� (�����)
	glColor3f(0.0f, 0.0f, 1.0f);	 // ��ɫ
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // �����ε����¶��� (�����)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ
	glVertex3f(0.0f, 1.0f, 0.0f);	 // �����ε��϶��� (�����)
	glColor3f(0.0f, 0.0f, 1.0f);	 // ��ɫ
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // �����ε����¶��� (�����)
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // �����ε����¶��� (�����)
	glEnd();	 // ���������ƽ���
	glLoadIdentity();
	glTranslatef(1.5f, 0.0f, -7.0f);	 // ��������������Ļ
	glRotatef(rquad, 1.0f, 1.0f, 1.0f);	 // ��XYZ������ת������
	glBegin(GL_QUADS);	 // ��ʼ����������
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ��Ϊ��ɫ
	glVertex3f(1.0f, 1.0f, -1.0f);	 // �ı��ε����϶��� (����)
	glColor3f(1.0f, 1.0f, 0.0f);	 // ��ɫ�ĳɻ�ɫ
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // �ı��ε����϶��� (����)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ�ĳɺ�ɫ
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // �ı��ε����¶��� (����)
	glColor3f(1.0f, 0.0f, 1.0f);	 // ��ɫ�ĳ�������ɫ
	glVertex3f(1.0f, 1.0f, 1.0f);	 // �ı��ε����¶��� (����)
	glColor3f(1.0f, 0.5f, 0.0f);	 // ��ɫ�ĳɳ�ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	 // �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glVertex3f(1.0f, -1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ�ĳɺ�ɫ
	glColor3f(1.0f, 0.0f, 1.0f);	 // ��ɫ�ĳ�������ɫ
	glVertex3f(1.0f, 1.0f, 1.0f);	 // �ı��ε����϶���(ǰ��)
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ�ĳɺ�ɫ
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // �ı��ε����϶���(ǰ��)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // �ı��ε����¶���(ǰ��)
	glColor3f(1.0f, 0.5f, 0.0f);	 // ��ɫ�ĳɳ�ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	 // �ı��ε����¶���(ǰ��)
	glColor3f(1.0f, 1.0f, 0.0f);	 // ��ɫ�ĳɻ�ɫ
	glVertex3f(1.0f, -1.0f, -1.0f);	 // �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // �ı��ε����϶���(����)
	glColor3f(1.0f, 1.0f, 0.0f);	 // ��ɫ�ĳɻ�ɫ
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ��Ϊ��ɫ
	glVertex3f(1.0f, 1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glColor3f(0.0f, 0.0f, 1.0f);	 // ��ɫ�ĳ���ɫ
	glColor3f(1.0f, 0.0f, 0.0f);	 // ��ɫ�ĳɺ�ɫ
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // �ı��ε����϶���(����)
	glColor3f(1.0f, 1.0f, 0.0f);	 // ��ɫ�ĳɻ�ɫ
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // �ı��ε����϶���(����)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // �ı��ε����¶���(����)
	glColor3f(1.0f, 0.0f, 1.0f);	 // ��ɫ�ĳ�������ɫ
	glColor3f(0.0f, 1.0f, 0.0f);	 // ��ɫ��Ϊ��ɫ
	glVertex3f(1.0f, 1.0f, -1.0f);	 // �ı��ε����϶���(����)
	glVertex3f(1.0f, 1.0f, 1.0f);	 // �ı��ε����϶���(����)
	glColor3f(1.0f, 0.5f, 0.0f);	 // ��ɫ�ĳɳ�ɫ
	glVertex3f(1.0f, -1.0f, 1.0f);	 // �ı��ε����¶���(����)
	glVertex3f(1.0f, -1.0f, -1.0f);	 // �ı��ε����¶���(����)
	glEnd();	 // ��������ƽ���
	rtri += 1.0f;	 // ���������ε���ת����
	rquad -= 1.0f;	 // �����ı��ε���ת����
	return NULL;
}
int textureMapping() {
	glLoadIdentity();	 // ���õ�ǰ��ģ�͹۲����
	glTranslatef(0.0f, 0.0f, -5.0f);	 // ������Ļ 5 ����λ
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);	 // ��X����ת
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);	 // ��Y����ת
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);	 // ��Z����ת
	glBindTexture(GL_TEXTURE_2D, texture[0]);	 // ѡ������
												 /*	Ϊ�˽�������ȷ��ӳ�䵽�ı����ϣ������뽫��������Ͻ�ӳ�䵽�ı��ε����Ͻǣ���������Ͻ�ӳ�䵽�ı��ε����Ͻǣ���������½�ӳ�䵽�ı��ε����½ǣ���������½�ӳ�䵽�ı��ε����½ǡ����ӳ�����Ļ���ͼ����ʾʱ�������µߵ�������һ�߻���ʲô�����ǡ�
												 glTexCoord2f �ĵ�һ��������X���ꡣ 0.0f ���������ࡣ 0.5f ��������е㣬 1.0f ��������Ҳࡣ glTexCoord2f �ĵڶ���������Y���ꡣ 0.0f ������ĵײ��� 0.5f ��������е㣬 1.0f ������Ķ�����
												 ������������������� X��0.0f��Y��1.0f ���ı��ε����϶����� X�� -1.0f��Y��1.0f �����������������ơ�
												 �������� glTexCoord2f ��X��Y����������� 1.0f ��Ϊ 0.5f ��ֻ��ʾ�������벿�֣��� 0.0f ��Ϊ 0.5f ��ֻ��ʾ������Ұ벿�֡�*/
	glBegin(GL_QUADS);
	// ǰ��
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
																// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
																// ����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
																// ����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
																// ����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// ������ı��ε�����
																// ����
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// ������ı��ε�����
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// ������ı��ε�����
	glEnd();
	/*�������� xrot, yrot �� zrot ��ֵ�����Ա仯ÿ�θ������ĸı�ֵ���������������ת�ٶȣ���ı� + / -�����������������ת����*/
	xrot += 0.3f;	 // X ����ת
	yrot += 0.2f;	 // Y ����ת
	zrot += 0.4f;	 // Z ����ת
	return true;	 // ��������
}
