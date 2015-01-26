#include <windows.h>	 // Windows��ͷ�ļ�
#include <stdio.h>	 // ��׼����/������ͷ�ļ�
#include "glew.h"	 // �������µ�gl.h,glu.h��
#include "glut.h"	 // ����OpenGLʵ�ÿ�
#ifndef OPENGL_DEMO_H
#define OPENGL_DEMO_H
/*
��һ�����õı�����Rendering Context(��ɫ������)��
ÿһ��OpenGL�������ӵ�һ����ɫ�������ϡ�
��ɫ���������е�OpenGL�����������ӵ�Device Context(�豸������)�ϡ�
�ҽ�OpenGL����ɫ��������Ϊ hRC ��
Ҫ�����ĳ����ܹ����ƴ��ڵĻ�������Ҫ����һ���豸������Ҳ���ǵڶ��е����ݡ�
Windows���豸����������Ϊ hDC ��
DC���������ӵ�GDI(Graphics Device Interfaceͼ���豸�ӿ�)��
��RC��OpenGL���ӵ�DC��
�����еı��� hWnd ��������Windows�����ǵĴ���ָ�ɵľ����
��󣬵�����Ϊ���ǵĳ��򴴽���һ��Instance(ʵ��)��*/
extern HGLRC hRC;	 // ������ɫ��������
extern HDC hDC;	 // OpenGL��Ⱦ��������
extern HWND hWnd;	 // �������ǵĴ��ھ��
extern HINSTANCE hInstance;	 // ��������ʵ��
							 /*����ĵ�һ������һ��������ؼ��̶��������顣����෽�����Լ�ؼ��̵Ķ�����������ķ����ܿɿ������ҿ��Դ�������ͬʱ���µ������
							 active ����������֪���򴰿��Ƿ�����С����״̬����������Ѿ���С���Ļ������ǿ���������ͣ����ִ�е��˳�������κ����顣��ϲ����ͣ������������ʹ�ó������ں�̨�������С�
							 fullscreen �����������൱���ԡ�������ǵĳ�����ȫ��״̬�����У� fullscreen ��ֵΪTRUE������ΪFALSE�����ȫ�ֱ���������ʮ����Ҫ������ÿ�����̶�֪�������Ƿ�������ȫ��״̬�¡�*/
extern bool	keys[256];	 // ������̰���������
extern bool	active;	 // ���ڵĻ��־��ȱʡΪTRUE
extern bool	fullscreen;	 // ȫ����־ȱʡ��ȱʡ�趨��ȫ��ģʽ
extern GLfloat	 rtri;	 // ���������εĽǶ�
extern GLfloat	 rquad;	 // �����ı��εĽǶ�
extern int width;	 //���ڿ��
extern int height;	 //���ڸ߶�
extern GLfloat	 xrot;	 // X ��ת��
extern GLfloat	 yrot;	 // Y ��ת��
extern GLfloat	 zrot;	 // Z ��ת��
extern GLuint	 texture[1];	 // �洢һ������
								 /*����������Ҫ�ȶ���WndProc()��
								 ������ô����ԭ����CreateGLWindow()�ж�WndProc()�����ã���WndProc()��CreateGLWindow()֮��ų��֡�*/
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	 // WndProc�Ķ���
														 /*�������Ĵ���δ������ǵ�OpenGL���ڡ�
														 �������������˹��̷��ز�������(TRUE �� FALSE)��
														 ��������5�����������ڵı����������ڵĿ�ȣ����ڵĸ߶ȣ�ɫ��λ��(16/24/32)����ȫ����־(TRUE --ȫ��ģʽ�� FALSE--����ģʽ )�����صĲ���ֵ�������Ǵ����Ƿ�ɹ�������*/
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag);
GLvoid KillGLWindow(GLvoid);	 // �������ٴ���
int DrawGLScene(bool[]);	 // �����￪ʼ�������еĻ���
int drawTriangleAndSquare();
int drawThreePyramid();
bool LoadTexture(LPTSTR szFileName, GLuint &texid);
int textureMapping();
//̰����
//int snake(bool[]);
int drawMap();
static LPTSTR szFileName = "D:\\net-ease-VisualStudio-workspace\\openGLDemo\\openGLDemo\\wefwefwef.bmp";
#endif