#include "openglDemo.h"
HGLRC hRC = NULL;	 // 窗口着色描述表句柄
HDC hDC = NULL;	 // OpenGL渲染描述表句柄
HWND hWnd = NULL;	 // 保存我们的窗口句柄
HINSTANCE hInstance;	 // 保存程序的实例
						 /*下面的第一行设置一个用来监控键盘动作的数组。有许多方法可以监控键盘的动作，但这里的方法很可靠，并且可以处理多个键同时按下的情况。
						 active 变量用来告知程序窗口是否处于最小化的状态。如果窗口已经最小化的话，我们可以做从暂停代码执行到退出程序的任何事情。我喜欢暂停程序。这样可以使得程序不用在后台保持运行。
						 fullscreen 变量的作用相当明显。如果我们的程序在全屏状态下运行， fullscreen 的值为TRUE，否则为FALSE。这个全局变量的设置十分重要，它让每个过程都知道程序是否运行在全屏状态下。*/
bool	keys[256];	 // 保存键盘按键的数组
bool	active = TRUE;	 // 窗口的活动标志，缺省为TRUE
bool	fullscreen = FALSE;	 // 全屏标志缺省，
GLfloat	 rtri = 0;	 // 用于三角形的角度
GLfloat	 rquad;	 // 用于四边形的角度
int width = 600;
int height = 480;
GLfloat	 xrot = 0;	 // X 旋转量
GLfloat	 yrot = 0;	 // Y 旋转量
GLfloat	 zrot = 0;	 // Z 旋转量
GLuint	 texture[1];	 // 存储一个纹理
						 /*下面是我们的Windows程序的入口。将会调用窗口创建例程，处理窗口消息，并监视人机交互。*/
int WINAPI WinMain(HINSTANCE	hInstance,	 // 当前窗口实例
	HINSTANCE	hPrevInstance,	 // 前一个窗口实例
	LPSTR	 lpCmdLine,	 // 命令行参数
	int	 nCmdShow)	 // 窗口显示状态
{
	/*FILE *fs;
	AllocConsole();
	freopen_s(&fs, "conout$", "w", stdout);*/
	/*我们设置两个变量。msg 用来检查是否有消息等待处理。
	done的初始值设为FALSE。这意味着我们的程序仍未完成运行。
	只要程序done保持FALSE，程序继续运行。一旦done的值改变为TRUE，程序退出。*/
	MSG	msg;	 // Windowsx消息结构
	BOOL done = FALSE;	 // 用来退出循环的Bool 变量
						 /*接着创建OpenGL窗口。
						 CreateGLWindow函数的参数依次为标题、宽度、高度、色彩深度，以及全屏标志。
						 就这么简单！我很欣赏这段代码的简洁。如果未能创建成功，函数返回FALSE。
						 程序立即退出。*/
						 // 创建OpenGL窗口
	if (!CreateGLWindow("OpenGL Demo", width, height, 16, fullscreen))
	{
		return 0;	 // 失败退出
	}
	/*下面是循环的开始。只要done保持FALSE，循环一直进行。*/
	while (!done)	 // 保持循环直到 done=TRUE
	{
		/*我们要做的第一件事是检查是否有消息在等待。
		使用PeekMessage()可以在不锁住我们的程序的前提下对消息进行检查。
		许多程序使用GetMessage()，也可以很好的工作。
		但使用GetMessage()，程序在收到paint消息或其他别的什么窗口消息之前不会做任何事。*/
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	 // 有消息在等待吗?
		{
			/*下面的代码查看是否出现退出消息。
			如果当前的消息是由PostQuitMessage(0)引起的WM_QUIT，done变量被设为TRUE，程序将退出。*/
			if (msg.message == WM_QUIT)	 // 收到退出消息?
			{
				done = TRUE;	 // 是，则done=TRUE
			}
			else	 // 不是，处理窗口消息
			{
				/*如果不是退出消息，我们翻译消息，然后发送消息，使得WndProc() 或 Windows能够处理他们。*/
				TranslateMessage(&msg);	 // 翻译消息
				DispatchMessage(&msg);	 // 发送消息
			}
		}
		else	 // 如果没有消息
		{
			/*如果没有消息，绘制我们的OpenGL场景。
			代码的第一行查看窗口是否激活。如果按下ESC键，done变量被设为TRUE，程序将会退出。*/
			// 绘制场景。监视ESC键和来自DrawGLScene()的退出消息
			if (active)	 // 程序激活的么?
			{
				if (keys[VK_ESCAPE])	 // ESC 按下了么?
				{
					done = TRUE;	 // ESC 发出退出信号
				}
				else	 // 不是退出的时候，刷新屏幕
				{
					/*如果程序是激活的且ESC没有按下，我们绘制场景并交换缓存(使用双缓存可以实现无闪烁的动画)。
					我们实际上在另一个看不见的"屏幕"上绘图。
					当我们交换缓存后，我们当前的屏幕被隐藏，现在看到的是刚才看不到的屏幕。
					这也是我们看不到场景绘制过程的原因。场景只是即时显示。*/
					DrawGLScene(keys);	 // 绘制场景
					SwapBuffers(hDC);	 // 交换缓存 (双缓存)
				}
			}
			/*下面的一点代码是最近新加的(05-01-00)。
			允许用户按下F1键在全屏模式和窗口模式间切换。*/
			if (keys[VK_F1])	 // F1键按下了么?
			{
				keys[VK_F1] = FALSE;	 // 若是，使对应的Key数组中的值为 FALSE
				KillGLWindow();	 // 销毁当前的窗口
				fullscreen = !fullscreen;	 // 切换 全屏 / 窗口 模式
											 // 重建 OpenGL 窗口
				if (!CreateGLWindow("OpenGl Demo", 640, 480, 16, fullscreen))
				{
					return 0;	 // 如果窗口未能创建，程序退出
				}
			}
		}
	}
	/*如果done变量不再是FALSE，程序退出。正常销毁OpenGL窗口，将所有的内存释放，退出程序。	*/
	// 关闭程序
	KillGLWindow();	 // 销毁窗口
					 //FreeConsole();
	return (msg.wParam);	 // 退出程序
}