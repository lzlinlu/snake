#include <windows.h>	 // Windows的头文件
#include <stdio.h>	 // 标准输入/输出库的头文件
#include "glew.h"	 // 包含最新的gl.h,glu.h库
#include "glut.h"	 // 包含OpenGL实用库
#ifndef OPENGL_DEMO_H
#define OPENGL_DEMO_H
/*
第一行设置的变量是Rendering Context(着色描述表)。
每一个OpenGL都被连接到一个着色描述表上。
着色描述表将所有的OpenGL调用命令连接到Device Context(设备描述表)上。
我将OpenGL的着色描述表定义为 hRC 。
要让您的程序能够绘制窗口的话，还需要创建一个设备描述表，也就是第二行的内容。
Windows的设备描述表被定义为 hDC 。
DC将窗口连接到GDI(Graphics Device Interface图形设备接口)。
而RC将OpenGL连接到DC。
第三行的变量 hWnd 将保存由Windows给我们的窗口指派的句柄。
最后，第四行为我们的程序创建了一个Instance(实例)。*/
extern HGLRC hRC;	 // 窗口着色描述表句柄
extern HDC hDC;	 // OpenGL渲染描述表句柄
extern HWND hWnd;	 // 保存我们的窗口句柄
extern HINSTANCE hInstance;	 // 保存程序的实例
							 /*下面的第一行设置一个用来监控键盘动作的数组。有许多方法可以监控键盘的动作，但这里的方法很可靠，并且可以处理多个键同时按下的情况。
							 active 变量用来告知程序窗口是否处于最小化的状态。如果窗口已经最小化的话，我们可以做从暂停代码执行到退出程序的任何事情。我喜欢暂停程序。这样可以使得程序不用在后台保持运行。
							 fullscreen 变量的作用相当明显。如果我们的程序在全屏状态下运行， fullscreen 的值为TRUE，否则为FALSE。这个全局变量的设置十分重要，它让每个过程都知道程序是否运行在全屏状态下。*/
extern bool	keys[256];	 // 保存键盘按键的数组
extern bool	active;	 // 窗口的活动标志，缺省为TRUE
extern bool	fullscreen;	 // 全屏标志缺省，缺省设定成全屏模式
extern GLfloat	 rtri;	 // 用于三角形的角度
extern GLfloat	 rquad;	 // 用于四边形的角度
extern int width;	 //窗口宽度
extern int height;	 //窗口高度
extern GLfloat	 xrot;	 // X 旋转量
extern GLfloat	 yrot;	 // Y 旋转量
extern GLfloat	 zrot;	 // Z 旋转量
extern GLuint	 texture[1];	 // 存储一个纹理
								 /*现在我们需要先定义WndProc()。
								 必须这么做的原因是CreateGLWindow()有对WndProc()的引用，但WndProc()在CreateGLWindow()之后才出现。*/
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	 // WndProc的定义
														 /*接下来的代码段创建我们的OpenGL窗口。
														 正如您所见，此过程返回布尔变量(TRUE 或 FALSE)。
														 他还带有5个参数：窗口的标题栏，窗口的宽度，窗口的高度，色彩位数(16/24/32)，和全屏标志(TRUE --全屏模式， FALSE--窗口模式 )。返回的布尔值告诉我们窗口是否成功创建。*/
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag);
GLvoid KillGLWindow(GLvoid);	 // 正常销毁窗口
int DrawGLScene(bool[]);	 // 从这里开始进行所有的绘制
int drawTriangleAndSquare();
int drawThreePyramid();
bool LoadTexture(LPTSTR szFileName, GLuint &texid);
int textureMapping();
//贪吃蛇
//int snake(bool[]);
int drawMap();
static LPTSTR szFileName = "D:\\net-ease-VisualStudio-workspace\\openGLDemo\\openGLDemo\\wefwefwef.bmp";
#endif