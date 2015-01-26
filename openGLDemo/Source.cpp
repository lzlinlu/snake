#include "openglDemo.h"
/*下面的代码的作用是重新设置OpenGL场景的大小，而不管窗口的大小是否已经改变(假定您没有使用全屏模式)。
甚至您无法改变窗口的大小时(例如您在全屏模式下)，它至少仍将运行一次--在程序开始时设置我们的透视图。
OpenGL场景的尺寸将被设置成它显示时所在窗口的大小。*/
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)	 // 重置OpenGL窗口大小
{
	if (height == 0)	 // 防止被零除
	{
		height = 1;	 // 将Height设为1
	}
	glViewport(0, 0, width, height);	 // 重置当前的视口
										 /*下面几行为透视图设置屏幕。意味着越远的东西看起来越小。
										 这么做创建了一个现实外观的场景。此处透视按照基于窗口宽度和高度的45度视角来计算。
										 0.1f，100.0f是我们在场景中所能绘制深度的起点和终点。
										 glMatrixMode(GL_PROJECTION)指明接下来的两行代码将影响projection matrix(投影矩阵)。
										 投影矩阵负责为我们的场景增加透视。 glLoadIdentity()近似于重置。
										 它将所选的矩阵状态恢复成其原始状态。调用 glLoadIdentity()之后我们为场景设置透视图。
										 glMatrixMode(GL_MODELVIEW)指明任何新的变换将会影响 modelview matrix(模型观察矩阵)。
										 模型观察矩阵中存放了我们的物体讯息。最后我们重置模型观察矩阵。
										 如果您还不能理解这些术语的含义，请别着急。在以后的教程里，我会向大家解释。
										 只要知道如果您想获得一个精彩的透视场景的话，必须这么做。*/
	glMatrixMode(GL_PROJECTION);	 // 选择投影矩阵
	glLoadIdentity();	 // 重置投影矩阵
						 // 设置视口的大小
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);	 // 选择模型观察矩阵
	glLoadIdentity();	 // 重置模型观察矩阵
}
/*接下的代码段中，我们将对OpenGL进行所有的设置。
我们将设置清除屏幕所用的颜色，打开深度缓存，启用smooth shading(阴影平滑)，等等。
这个例程直到OpenGL窗口创建之后才会被调用。此过程将有返回值。
但我们此处的初始化没那么复杂，现在还用不着担心这个返回值。*/
int InitGL(GLvoid)	 // 此处开始对OpenGL进行所有设置
{
	if (!LoadTexture(szFileName, texture[0]))	 // 调用纹理载入子例程
	{
		return FALSE;	 // 如果未能载入，返回FALSE
	}
	glEnable(GL_TEXTURE_2D);	 // 启用纹理映射
								 /*下一行启用smooth shading(阴影平滑)。阴影平滑通过多边形精细的混合色彩，并对外部光进行平滑。
								 我将在另一个教程中更详细的解释阴影平滑。*/
	glShadeModel(GL_SMOOTH);	 // 启用阴影平滑
								 /*下一行设置清除屏幕时所用的颜色。如果您对色彩的工作原理不清楚的话，我快速解释一下。色彩值的范围从0.0f到1.0f。0.0f代表最黑的情况，1.0f就是最亮的情况。glClearColor 后的第一个参数是Red Intensity(红色分量),第二个是绿色，第三个是蓝色。最大值也是1.0f，代表特定颜色分量的最亮情况。最后一个参数是Alpha值。当它用来清除屏幕的时候，我们不用关心第四个数字。现在让它为0.0f。我会用另一个教程来解释这个参数。
								 通过混合三种原色(红、绿、蓝)，您可以得到不同的色彩。希望您在学校里学过这些。因此，当您使用glClearColor(0.0f,0.0f,1.0f,0.0f)，您将用亮蓝色来清除屏幕。如果您用 glClearColor(0.5f,0.0f,0.0f,0.0f)的话，您将使用中红色来清除屏幕。不是最亮(1.0f)，也不是最暗 (0.0f)。要得到白色背景，您应该将所有的颜色设成最亮(1.0f)。要黑色背景的话，您该将所有的颜色设为最暗(0.0f)。*/
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	 // 黑色背景
											 /*接下来的三行必须做的是关于depth buffer(深度缓存)的。将深度缓存设想为屏幕后面的层。深度缓存不断的对物体进入屏幕内部有多深进行跟踪。我们本节的程序其实没有真正使用深度缓存，但几乎所有在屏幕上显示3D场景OpenGL程序都使用深度缓存。它的排序决定那个物体先画。这样您就不会将一个圆形后面的正方形画到圆形上来。深度缓存是OpenGL十分重要的部分。*/
	glClearDepth(1.0f);	 // 设置深度缓存
	glEnable(GL_DEPTH_TEST);	 // 启用深度测试
	glDepthFunc(GL_LEQUAL);	 // 所作深度测试的类型
							 /*接着告诉OpenGL我们希望进行最好的透视修正。这会十分轻微的影响性能。但使得透视图看起来好一点。*/
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	 // 告诉系统对透视进行修正
														 /*最后，我们返回TRUE。如果我们希望检查初始化是否OK，我们可以查看返回的 TRUE或FALSE的值。如果有错误发生的话，您可以加上您自己的代码返回FALSE。目前，我们不管它。*/
	return TRUE;	 // 初始化 OK
}
/*下一段包括了所有的绘图代码。任何您所想在屏幕上显示的东东都将在此段代码中出现。
以后的每个教程中我都会在例程的此处增加新的代码。
如果您对OpenGL已经有所了解的话，您可以在 glLoadIdentity()调用之后，返回TRUE值之前，试着添加一些OpenGL代码来创建基本的形。如果您是OpenGL新手，等着我的下个教程。目前我们所作的全部就是将屏幕清除成我们前面所决定的颜色，清除深度缓存并且重置场景。我们仍没有绘制任何东东。
返回TRUE值告知我们的程序没有出现问题。如果您希望程序因为某些原因而中止运行，在返回TRUE值之前增加返回FALSE的代码告知我们的程序绘图代码出错。程序即将退出。*/
int DrawGLScene(bool keys[])	 // 从这里开始进行所有的绘制
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	 // 清除屏幕和深度缓存
	glLoadIdentity();	 // 重置当前的模型观察矩阵
						 //drawTriangleAndSquare();
						 //drawThreePyramid();
						 //textureMapping();
	drawMap();
	return TRUE;	 // 一切 OK
}
/*下一段代码只在程序退出之前调用。KillGLWindow() 的作用是依次释放着色描述表，设备描述表和窗口句柄。
我已经加入了许多错误检查。如果程序无法销毁窗口的任意部分，都会弹出带相应错误消息的讯息窗口，告诉您什么出错了。
使您在您的代码中查错变得更容易些。*/
GLvoid KillGLWindow(GLvoid)	 // 正常销毁窗口
{
	/*我们在KillGLWindow()中所作的第一件事是检查我们是否处于全屏模式。如果是，我们要切换回桌面。我们本应在禁用全屏模式前先销毁窗口，但在某些显卡上这么做可能会使得桌面崩溃。所以我们还是先禁用全屏模式。这将防止桌面出现崩溃，并在Nvidia和3dfx显卡上都工作的很好！*/
	if (fullscreen)	 // 我们处于全屏模式吗?
	{
		/*我们使用ChangeDisplaySettings(NULL,0)回到原始桌面。将NULL作为第一个参数，0作为第二个参数传递强制Windows使用当前存放在注册表中的值(缺省的分辨率、色彩深度、刷新频率，等等)来有效的恢复我们的原始桌面。切换回桌面后，我们还要使得鼠标指针重新可见。*/
		ChangeDisplaySettings(NULL, 0);	 // 是的话，切换回桌面
		ShowCursor(TRUE);	 // 显示鼠标指针
	}
	/*接下来的代码查看我们是否拥有着色描述表(hRC)。如果没有，程序将跳转至后面的代码查看是否拥有设备描述表。*/
	if (hRC)	 // 我们拥有OpenGL渲染描述表吗?
	{
		/*如果存在着色描述表的话，下面的代码将查看我们能否释放它(将 hRC从hDC分开)。这里请注意我使用的的查错方法。基本上我只是让程序尝试释放着色描述表(通过调用wglMakeCurrent(NULL,NULL)，然后我再查看释放是否成功。巧妙的将数行代码结合到了一行。*/
		if (!wglMakeCurrent(NULL, NULL))	 // 我们能否释放DC和RC描述表?
		{
			/*如果不能释放DC和RC描述表的话，MessageBox()将弹出错误消息，告知我们DC和RC无法被释放。NULL意味着消息窗口没有父窗口。其右的文字将在消息窗口上出现。"SHUTDOWN ERROR"出现在窗口的标题栏上。MB_OK的意思消息窗口上带有一个写着OK字样的按钮。
			MB_ICONINFORMATION将在消息窗口中显示一个带圈的小写的i(看上去更正式一些)。*/
			MessageBox(NULL, "释放DC或RC失败。", "关闭错误", MB_OK | MB_ICONINFORMATION);
		}
		/*下一步我们试着删除着色描述表。如果不成功的话弹出错误消息。*/
		if (!wglDeleteContext(hRC))	 // 我们能否删除RC?
		{
			/*如果无法删除着色描述表的话，将弹出错误消息告知我们RC未能成功删除。然后hRC被设为NULL。*/
			MessageBox(NULL, "释放RC失败。", "关闭错误", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;	 // 将RC设为 NULL
	}
	/*现在我们查看是否存在设备描述表，如果有尝试释放它。如果不能释放设备描述表将弹出错误消息，然后hDC设为NULL。*/
	if (hDC && !ReleaseDC(hWnd, hDC))	 // 我们能否释放 DC?
	{
		MessageBox(NULL, "释放DC失败。", "关闭错误", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;	 // 将 DC 设为 NULL
	}
	/*现在我们来查看是否存在窗口句柄，我们调用 DestroyWindow( hWnd )来尝试销毁窗口。如果不能的话弹出错误窗口，然后hWnd被设为NULL。*/
	if (hWnd && !DestroyWindow(hWnd))	 // 能否销毁窗口?
	{
		MessageBox(NULL, "释放窗口句柄失败。", "关闭错误", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;	 // 将 hWnd 设为 NULL
	}
	/*最后要做的事是注销我们的窗口类。这允许我们正常销毁窗口，接着在打开其他窗口时，不会收到诸如"Windows Class already registered"(窗口类已注册)的错误消息。*/
	if (!UnregisterClass("OpenG", hInstance))	 // 能否注销类?
	{
		MessageBox(NULL, "不能注销窗口类。", "关闭错误", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;	 // 将 hInstance 设为 NULL
	}
}
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	/*当我们要求Windows为我们寻找相匹配的象素格式时，Windows寻找结束后将模式值保存在变量PixelFormat中。*/
	GLuint	 PixelFormat;	 // 保存查找匹配的结果
							 /*wc用来保存我们的窗口类的结构。窗口类结构中保存着我们的窗口信息。通过改变类的不同字段我们可以改变窗口的外观和行为。每个窗口都属于一个窗口类。当您创建窗口时，您必须为窗口注册类。*/
	WNDCLASS	wc;	 // 窗口类结构
					 /*dwExStyle和dwStyle存放扩展和通常的窗口风格信息。我使用变量来存放风格的目的是为了能够根据我需要创建的窗口类型(是全屏幕下的弹出窗口还是窗口模式下的带边框的普通窗口)；来改变窗口的风格。*/
	DWORD	 dwExStyle;	 // 扩展窗口风格
	DWORD	 dwStyle;	 // 窗口风格
						 /*下面的5行代码取得矩形的左上角和右下角的坐标值。我们将使用这些值来调整我们的窗口使得其上的绘图区的大小恰好是我们所需的分辨率的值。通常如果我们创建一个640x480的窗口，窗口的边框会占掉一些分辨率的值。*/
	RECT WindowRect;	 // 取得矩形的左上角和右下角的坐标值
	WindowRect.left = (long)0;	 // 将Left 设为 0
	WindowRect.right = (long)width;	 // 将Right 设为要求的宽度
	WindowRect.top = (long)0;	 // 将Top 设为 0
	WindowRect.bottom = (long)height;	 // 将Bottom 设为要求的高度
										 /*下一行代码我们让全局变量fullscreen等于fullscreenflag。如果我们希望在全屏幕下运行而将fullscreenflag设为TRUE，但没有让变量fullscreen等于fullscreenflag的话，fullscreen变量将保持为FALSE。当我们在全屏幕模式下销毁窗口的时候，变量fullscreen的值却不是正确的TRUE值，计算机将误以为已经处于桌面模式而无法切换回桌面。上帝啊，但愿这一切都有意义。就是一句话，fullscreen的值必须永远fullscreenflag的值，否则就会有问题。*/
	fullscreen = fullscreenflag;	 // 设置全局全屏标志
									 /*下一部分的代码中，我们取得窗口的实例，然后定义窗口类。CS_HREDRAW 和 CS_VREDRAW 的意思是无论何时，只要窗口发生变化时就强制重画。CS_OWNDC为窗口创建一个私有的DC。这意味着DC不能在程序间共享。WndProc是我们程序的消息处理过程。由于没有使用额外的窗口数据，后两个字段设为零。然后设置实例。接着我们将hIcon设为NULL，因为我们不想给窗口来个图标。鼠标指针设为标准的箭头。背景色无所谓(我们在GL中设置)。我们也不想要窗口菜单，所以将其设为NULL。类的名字可以您想要的任何名字。出于简单，我将使用"OpenG"。*/
	hInstance = GetModuleHandle(NULL);	 // 取得我们窗口的实例
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	 // 移动时重画，并为窗口取得DC
	wc.lpfnWndProc = (WNDPROC)WndProc;	 // WndProc处理消息
	wc.cbClsExtra = 0;	 // 无额外窗口数据
	wc.cbWndExtra = 0;	 // 无额外窗口数据
	wc.hInstance = hInstance;	 // 设置实例
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);	 // 装入缺省图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	 // 装入鼠标指针
	wc.hbrBackground = NULL;	 // GL不需要背景
	wc.lpszMenuName = NULL;	 // 不需要菜单
	wc.lpszClassName = "OpenG";	 // 设定类名字
								 /*现在注册类名字。如果有错误发生，弹出错误消息窗口。按下上面的OK按钮后，程序退出*/
	if (!RegisterClass(&wc))	 // 尝试注册窗口类
	{
		MessageBox(NULL, "注册窗口失败", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 退出并返回FALSE
	}
	/*查看程序应该在全屏模式还是窗口模式下运行。如果应该是全屏模式的话，我们将尝试设置全屏模式。*/
	if (fullscreen)	 // 要尝试全屏模式吗?
	{
		/*下一部分的代码看来很多人都会有问题要问关于.......切换到全屏模式。在切换到全屏模式时，有几件十分重要的事您必须牢记。必须确保您在全屏模式下所用的宽度和高度等同于窗口模式下的宽度和高度。最最重要的是要在创建窗口之前设置全屏模式。这里的代码中，您无需再担心宽度和高度，它们已被设置成与显示模式所对应的大小。*/
		DEVMODE dmScreenSettings;	 // 设备模式
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	 // 确保内存清空为零
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);	 // Devmode 结构的大小
		dmScreenSettings.dmPelsWidth = width;	 // 所选屏幕宽度
		dmScreenSettings.dmPelsHeight = height;	 // 所选屏幕高度
		dmScreenSettings.dmBitsPerPel = bits;	 // 每象素所选的色彩深度
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		/*上面的代码中，我们分配了用于存储视频设置的空间。设定了屏幕的宽，高，色彩深度。下面的代码我们尝试设置全屏模式。我们在dmScreenSettings中保存了所有的宽，高，色彩深度讯息。下一行使用ChangeDisplaySettings来尝试切换成与dmScreenSettings所匹配模式。我使用参数CDS_FULLSCREEN来切换显示模式，因为这样做不仅移去了屏幕底部的状态条，而且它在来回切换时，没有移动或改变您在桌面上的窗口。*/
		// 尝试设置显示模式并返回结果。注: CDS_FULLSCREEN 移去了状态条。
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			/*如果模式未能设置成功，我们将进入以下的代码。如果不能匹配全屏模式，弹出消息窗口，提供两个选项：在窗口模式下运行或退出。*/
			// 若模式失败，提供两个选项：退出或在窗口内运行。
			if (MessageBox(NULL, "全屏模式在当前显卡上设置失败！\n使用窗口模式？", "NeHe G", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				/*如果用户选择窗口模式，变量fullscreen 的值变为FALSE,程序继续运行。*/
				fullscreen = FALSE;	 // 选择窗口模式(Fullscreen=FALSE)
			}
			else
			{
				/*如果用户选择退出，弹出消息窗口告知用户程序将结束。并返回FALSE告诉程序窗口未能成功创建。程序退出。*/
				// 弹出一个对话框，告诉用户程序结束
				MessageBox(NULL, "程序将被关闭", "错误", MB_OK | MB_ICONSTOP);
				return FALSE;	 // 退出并返回 FALSE
			}
		}
	}
	/*由于全屏模式可能失败，用户可能决定在窗口下运行，我们需要在设置屏幕/窗口之前，再次检查fullscreen的值是TRUE或FALSE。*/
	if (fullscreen)	 // 仍处于全屏模式吗?
	{
		/*
		如果我们仍处于全屏模式，设置扩展窗体风格为WS_EX_APPWINDOW，这将强制我们的窗体可见时处于最前面。再将窗体的风格设为WS_POPUP。这个类型的窗体没有边框，使我们的全屏模式得以完美显示。
		最后我们禁用鼠标指针。当您的程序不是交互式的时候，在全屏模式下禁用鼠标指针通常是个好主意。
		*/
		dwExStyle = WS_EX_APPWINDOW;	 // 扩展窗体风格
		dwStyle = WS_POPUP;	 // 窗体风格
		ShowCursor(FALSE);	 // 隐藏鼠标指针
	}
	else
	{
		/*如果我们使用窗口而不是全屏模式，我们在扩展窗体风格中增加了 WS_EX_WINDOWEDGE，增强窗体的3D感观。窗体风格改用 WS_OVERLAPPEDWINDOW，创建一个带标题栏、可变大小的边框、菜单和最大化/最小化按钮的窗体。*/
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	 // 扩展窗体风格
		dwStyle = WS_OVERLAPPEDWINDOW;	 // 窗体风格
	}
	/*下一行代码根据创建的窗体类型调整窗口。调整的目的是使得窗口大小正好等于我们要求的分辨率。通常边框会占用窗口的一部分。使用AdjustWindowRectEx 后，我们的OpenGL场景就不会被边框盖住。实际上窗口变得更大以便绘制边框。全屏模式下，此命令无效。*/
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	 // 调整窗口达到真正要求的大小
																 /*	下一段代码开始创建窗口并检查窗口是否成功创建。我们将传递CreateWindowEx()所需的所有参数。如扩展风格、类名字(与您在注册窗口类时所用的名字相同)、窗口标题、窗体风格、窗体的左上角坐标(0,0 是个安全的选择)、窗体的宽和高。我们没有父窗口，也不想要菜单，这些参数被设为NULL。还传递了窗口的实例，最后一个参数被设为NULL。
																 注意我们在窗体风格中包括了 WS_CLIPSIBLINGS 和 WS_CLIPCHILDREN。要让OpenGL正常运行，这两个属性是必须的。他们阻止别的窗体在我们的窗体内/上绘图。*/
	if (!(hWnd = CreateWindowEx(dwExStyle,	 // 扩展窗体风格
		"OpenG",	 // 类名字
		title,	 // 窗口标题
		WS_CLIPSIBLINGS |	 // 必须的窗体风格属性
		WS_CLIPCHILDREN |	 // 必须的窗体风格属性
		dwStyle,	 // 选择的窗体属性
		0, 0,	 // 窗口位置
		WindowRect.right - WindowRect.left,	// 计算调整好的窗口宽度
		WindowRect.bottom - WindowRect.top,	// 计算调整好的窗口高度
		NULL,	 // 无父窗口
		NULL,	 // 无菜单
		hInstance,	 // 实例
		NULL)))	 // 不向WM_CREATE传递任何东东
				 /*下来我们检查看窗口是否正常创建。如果成功， hWnd保存窗口的句柄。如果失败，弹出消息窗口，并退出程序。*/
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能创建一个窗口设备描述表", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*下面的代码描述象素格式。我们选择了通过RGBA(红、绿、蓝、alpha通道)支持OpenGL和双缓存的格式。我们试图找到匹配我们选定的色彩深度(16位、24位、32位)的象素格式。最后设置16位Z-缓存。其余的参数要么未使用要么不重要(stencil buffer模板缓存和accumulation buffer聚集缓存除外)。*/
	static	PIXELFORMATDESCRIPTOR pfd =	 // /pfd 告诉窗口我们所希望的东东，即窗口使用的像素格式
	{
		sizeof(PIXELFORMATDESCRIPTOR),	 // 上述格式描述符的大小
		1,	 // 版本号
		PFD_DRAW_TO_WINDOW |	 // 格式支持窗口
		PFD_SUPPORT_OPENGL |	 // 格式必须支持OpenGL
		PFD_DOUBLEBUFFER,	 // 必须支持双缓冲
		PFD_TYPE_RGBA,	 // 申请 RGBA 格式
		bits,	 // 选定色彩深度
		0, 0, 0, 0, 0, 0,	 // 忽略的色彩位
		0,	 // 无Alpha缓存
		0,	 // 忽略Shift Bit
		0,	 // 无累加缓存
		0, 0, 0, 0,	 // 忽略聚集位
		16,	 // 16位 Z-缓存 (深度缓存)
		0,	 // 无蒙板缓存
		0,	 // 无辅助缓存
		PFD_MAIN_PLANE,	 // 主绘图层
		0,	 // Reserved
		0, 0, 0	 // 忽略层遮罩
	};
	/*如果前面创建窗口时没有错误发生，我们接着尝试取得OpenGL设备描述表。若无法取得DC，弹出错误消息程序退出(返回FALSE)。*/
	if (!(hDC = GetDC(hWnd)))	 // 取得设备描述表了么?
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能创建一种相匹配的像素格式", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*设法为OpenGL窗口取得设备描述表后，我们尝试找到对应与此前我们选定的象素格式的象素格式。如果Windows不能找到的话，弹出错误消息，并退出程序(返回FALSE)。*/
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	 // Windows 找到相应的象素格式了吗?
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能设置像素格式", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*Windows 找到相应的象素格式后，尝试设置象素格式。如果无法设置，弹出错误消息，并退出程序(返回FALSE)。*/
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))	 // 能够设置象素格式么?
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能设置像素格式", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*正常设置象素格式后，尝试取得着色描述表。如果不能取得着色描述表的话，弹出错误消息，并退出程序(返回FALSE)。*/
	if (!(hRC = wglCreateContext(hDC)))	 // 能否取得着色描述表?
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能创建OpenGL渲染描述表", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*如果到现在仍未出现错误的话，我们已经设法取得了设备描述表和着色描述表。接着要做的是激活着色描述表。如果无法激活，弹出错误消息，并退出程序(返回FALSE)。*/
	if (!wglMakeCurrent(hDC, hRC))	 // 尝试激活着色描述表
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "不能激活当前的OpenGL渲然描述表", "错误", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*一切顺利的话，OpenGL窗口已经创建完成，接着可以显示它啦。将它设为前端窗口(给它更高的优先级)，并将焦点移至此窗口。然后调用ReSizeGLScene 将屏幕的宽度和高度设置给透视OpenGL屏幕。*/
	ShowWindow(hWnd, SW_SHOW);	 // 显示窗口
	SetForegroundWindow(hWnd);	 // 略略提高优先级
	SetFocus(hWnd);	 // 设置键盘的焦点至此窗口
	ReSizeGLScene(width, height);	 // 设置透视 GL 屏幕
									 /*跳转至 InitGL()，这里可以设置光照、纹理、等等任何需要设置的东东。您可以在 InitGL()内部自行定义错误检查，并返回 TRUE (一切正常)或FALSE (有什么不对)。例如，如果您在InitGL()内装载纹理并出现错误，您可能希望程序停止。如果您返回 FALSE的话，下面的代码会弹出错误消息，并退出程序。*/
	if (!InitGL())	 // 初始化新建的GL窗口
	{
		KillGLWindow();	 // 重置显示区
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // 返回 FALSE
	}
	/*到这里可以安全的推定创建窗口已经成功了。我们向WinMain()返回TRUE，告知WinMain()没有错误，以防止程序退出。*/
	return TRUE;	 // 成功
}
/*下面的代码处理所有的窗口消息。当我们注册好窗口类之后，程序跳转到这部分代码处理窗口消息。*/
LRESULT CALLBACK WndProc(HWND	hWnd,	 // 窗口的句柄
	UINT	uMsg,	 // 窗口的消息
	WPARAM	wParam,	 // 附加的消息内容
	LPARAM	lParam)	 // 附加的消息内容
{
	/*下面的代码比对uMsg的值，然后转入case处理，uMsg 中保存了我们要处理的消息名字。*/
	switch (uMsg)	 // 检查Windows消息
	{
		/*如果uMsg等于WM_ACTIVE，查看窗口是否仍然处于激活状态。如果窗口已被最小化，将变量active设为FALSE。如果窗口已被激活，变量active的值为TRUE。*/
	case WM_ACTIVATE:	 // 监视窗口激活消息
	{
		if (!HIWORD(wParam))	 // 检查最小化状态
		{
			active = TRUE;	 // 程序处于激活状态
		}
		else
		{
			active = FALSE;	 // 程序不再激活
		}
		return 0;	 // 返回消息循环
	}
	/*如果消息是WM_SYSCOMMAND(系统命令)，再次比对wParam。如果wParam 是 SC_SCREENSAVE 或 SC_MONITORPOWER的话，不是有屏幕保护要运行，就是显示器想进入节电模式。返回0可以阻止这两件事发生。*/
	case WM_SYSCOMMAND:	 // 系统中断命令
	{
		switch (wParam)	 // 检查系统调用
		{
		case SC_SCREENSAVE:	 // 屏保要运行?
		case SC_MONITORPOWER:	 // 显示器要进入节电模式?
			return 0;	 // 阻止发生
		}
		break;	 // 退出
	}
	/*如果 uMsg是WM_CLOSE，窗口将被关闭。我们发出退出消息，主循环将被中断。变量done被设为TRUE，WinMain()的主循环中止，程序关闭。*/
	case WM_CLOSE:	 // 收到Close消息?
	{
		PostQuitMessage(0);	 // 发出退出消息
		return 0;	 // 返回
	}
	/*如果键盘有键按下，通过读取wParam的信息可以找出键值。我将键盘数组keys[ ]相应的数组组成员的值设为TRUE。这样以后就可以查找key[ ]来得知什么键被按下。允许同时按下多个键。*/
	case WM_KEYDOWN:	 // 有键按下么?
	{
		keys[wParam] = TRUE;	 // 如果是，设为TRUE
		return 0;	 // 返回
	}
	/*同样，如果键盘有键释放，通过读取wParam的信息可以找出键值。然后将键盘数组keys[ ]相应的数组组成员的值设为FALSE。这样查找key[ ]来得知什么键被按下，什么键被释放了。键盘上的每个键都可以用0-255之间的一个数来代表。举例来说，当我们按下40所代表的键时，keys[40]的值将被设为TRUE。放开的话，它就被设为FALSE。这也是key数组的原理。*/
	case WM_KEYUP:	 // 有键放开么?
	{
		keys[wParam] = FALSE;	 // 如果是，设为FALSE
		return 0;	 // 返回
	}
	/*当调整窗口时，uMsg 最后等于消息WM_SIZE。读取lParam的LOWORD 和HIWORD可以得到窗口新的宽度和高度。将他们传递给ReSizeGLScene()，OpenGL场景将调整为新的宽度和高度。*/
	case WM_SIZE:	 // 调整OpenGL窗口大小
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));	 // LoWord=Width,HiWord=Height
		return 0;	 // 返回
	}
	}
	/*其余无关的消息被传递给DefWindowProc，让Windows自行处理。*/
	// 向 DefWindowProc传递所有未处理的消息。
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
bool LoadTexture(LPTSTR szFileName, GLuint &texid) // 从位图创建文理
{
	HBITMAP hBMP; // 位图句柄
	BITMAP BMP; // 位图结构
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	if (!hBMP) return FALSE; //检查位图是否存在
							 /*现在使用中 TextureImage[0] 的数据创建纹理。
							 第一行 glGenTextures(1, &texture[0]) 告诉OpenGL我们想生成一个纹理名字(如果您想载入多个纹理，加大数字)。
							 值得注意的是，开始我们使用 GLuint texture[1] 来创建一个纹理的存储空间，
							 您也许会认为第一个纹理就是存放在 &texture[1] 中的，但这是错的。正确的地址应该是 &texture[0] 。
							 同样如果使用 GLuint texture[2] 的话，第二个纹理存放在 texture[1] 中。『译者注：学C的，在这里应该没有障碍，数组就是从零开始的嘛。』*/
	glGenTextures(1, &texid); // 创建文理
							  // hBMP: 图像对象句柄
							  // sizeof(BMP): 对象信息缓冲区大小
							  // &BMP: 对象信息缓冲区
	GetObject(hBMP, sizeof(BMP), &BMP); // 获取对象
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // 像素存储模式(Word Alignment / 4 Bytes)字节对齐
										   // Typical Texture Generation Using Data From The Bitmap
										   /*第二行 glBindTexture(GL_TEXTURE_2D, texture[0])
										   告诉OpenGL将纹理名字 texture[0] 绑定到纹理目标上。
										   2D纹理只有高度(在 Y 轴上)和宽度(在 X 轴上)。
										   主函数将纹理名字指派给纹理数据。
										   本例中我们告知OpenGL， &texture[0] 处的内存已经可用。
										   我们创建的纹理将存储在 &texture[0] 的 指向的内存区域。*/
	glBindTexture(GL_TEXTURE_2D, texid); // 使用来自位图数据生成 的典型纹理
										 /*下面的两行告诉OpenGL在显示图像时，
										 当它比放大得原始的纹理大(GL_TEXTURE_MAG_FILTER)或缩小得比原始得纹理小(GL_TEXTURE_MIN_FILTER)时
										 OpenGL采用的滤波方式。通常这两种情况下我都采用 GL_LINEAR 。
										 这使得纹理从很远处到离屏幕很近时都平滑显示。
										 使用 GL_LINEAR 需要CPU和显卡做更多的运算。如果您的机器很慢，您也许应该采用 GL_NEAREST 。
										 过滤的纹理在放大的时候，看起来斑驳的很『译者注：马赛克啦』。
										 您也可以结合这两种滤波方式。在近处时使用 GL_LINEAR ，远处时 GL_NEAREST 。*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
																	  /*下来我们创建真正的纹理。下面一行告诉OpenGL此纹理是一个2D纹理(GL_TEXTURE_2D)。
																	  参数“0”代表图像的详细程度，通常就由它为零去了。
																	  参数三是数据的成分数。因为图像是由红色数据，绿色数据，蓝色数据三种组分组成。
																	  TextureImage[0]->sizeX 是纹理的宽度。如果您知道宽度，您可以在这里填入，但计算机可以很容易的为您指出此值。
																	  TextureImage[0]->sizey 是纹理的高度。
																	  参数零是边框的值，一般就是“0”。 GL_RGB 告诉OpenGL图像数据由红、绿、蓝三色数据组成。
																	  GL_UNSIGNED_BYTE 意味着组成图像的数据是无符号字节类型的。
																	  最后... TextureImage[0]->data 告诉OpenGL纹理数据的来源。
																	  此例中指向存放在 TextureImage[0] 记录中的数据。*/
	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	DeleteObject(hBMP); // 删除对象
	return TRUE; // 返回成功
}