#include "openglDemo.h"
/*����Ĵ������������������OpenGL�����Ĵ�С�������ܴ��ڵĴ�С�Ƿ��Ѿ��ı�(�ٶ���û��ʹ��ȫ��ģʽ)��
�������޷��ı䴰�ڵĴ�Сʱ(��������ȫ��ģʽ��)���������Խ�����һ��--�ڳ���ʼʱ�������ǵ�͸��ͼ��
OpenGL�����ĳߴ罫�����ó�����ʾʱ���ڴ��ڵĴ�С��*/
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)	 // ����OpenGL���ڴ�С
{
	if (height == 0)	 // ��ֹ�����
	{
		height = 1;	 // ��Height��Ϊ1
	}
	glViewport(0, 0, width, height);	 // ���õ�ǰ���ӿ�
										 /*���漸��Ϊ͸��ͼ������Ļ����ζ��ԽԶ�Ķ���������ԽС��
										 ��ô��������һ����ʵ��۵ĳ������˴�͸�Ӱ��ջ��ڴ��ڿ�Ⱥ͸߶ȵ�45���ӽ������㡣
										 0.1f��100.0f�������ڳ��������ܻ�����ȵ������յ㡣
										 glMatrixMode(GL_PROJECTION)ָ�������������д��뽫Ӱ��projection matrix(ͶӰ����)��
										 ͶӰ������Ϊ���ǵĳ�������͸�ӡ� glLoadIdentity()���������á�
										 ������ѡ�ľ���״̬�ָ�����ԭʼ״̬������ glLoadIdentity()֮������Ϊ��������͸��ͼ��
										 glMatrixMode(GL_MODELVIEW)ָ���κ��µı任����Ӱ�� modelview matrix(ģ�͹۲����)��
										 ģ�͹۲�����д�������ǵ�����ѶϢ�������������ģ�͹۲����
										 ����������������Щ����ĺ��壬����ż������Ժ�Ľ̳���һ����ҽ��͡�
										 ֻҪ֪�����������һ�����ʵ�͸�ӳ����Ļ���������ô����*/
	glMatrixMode(GL_PROJECTION);	 // ѡ��ͶӰ����
	glLoadIdentity();	 // ����ͶӰ����
						 // �����ӿڵĴ�С
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);	 // ѡ��ģ�͹۲����
	glLoadIdentity();	 // ����ģ�͹۲����
}
/*���µĴ�����У����ǽ���OpenGL�������е����á�
���ǽ����������Ļ���õ���ɫ������Ȼ��棬����smooth shading(��Ӱƽ��)���ȵȡ�
�������ֱ��OpenGL���ڴ���֮��Żᱻ���á��˹��̽��з���ֵ��
�����Ǵ˴��ĳ�ʼ��û��ô���ӣ����ڻ��ò��ŵ����������ֵ��*/
int InitGL(GLvoid)	 // �˴���ʼ��OpenGL������������
{
	if (!LoadTexture(szFileName, texture[0]))	 // ������������������
	{
		return FALSE;	 // ���δ�����룬����FALSE
	}
	glEnable(GL_TEXTURE_2D);	 // ��������ӳ��
								 /*��һ������smooth shading(��Ӱƽ��)����Ӱƽ��ͨ������ξ�ϸ�Ļ��ɫ�ʣ������ⲿ�����ƽ����
								 �ҽ�����һ���̳��и���ϸ�Ľ�����Ӱƽ����*/
	glShadeModel(GL_SMOOTH);	 // ������Ӱƽ��
								 /*��һ�����������Ļʱ���õ���ɫ���������ɫ�ʵĹ���ԭ������Ļ����ҿ��ٽ���һ�¡�ɫ��ֵ�ķ�Χ��0.0f��1.0f��0.0f������ڵ������1.0f���������������glClearColor ��ĵ�һ��������Red Intensity(��ɫ����),�ڶ�������ɫ������������ɫ�����ֵҲ��1.0f�������ض���ɫ������������������һ��������Alphaֵ���������������Ļ��ʱ�����ǲ��ù��ĵ��ĸ����֡���������Ϊ0.0f���һ�����һ���̳����������������
								 ͨ���������ԭɫ(�졢�̡���)�������Եõ���ͬ��ɫ�ʡ�ϣ������ѧУ��ѧ����Щ����ˣ�����ʹ��glClearColor(0.0f,0.0f,1.0f,0.0f)������������ɫ�������Ļ��������� glClearColor(0.5f,0.0f,0.0f,0.0f)�Ļ�������ʹ���к�ɫ�������Ļ����������(1.0f)��Ҳ����� (0.0f)��Ҫ�õ���ɫ��������Ӧ�ý����е���ɫ�������(1.0f)��Ҫ��ɫ�����Ļ������ý����е���ɫ��Ϊ�(0.0f)��*/
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	 // ��ɫ����
											 /*�����������б��������ǹ���depth buffer(��Ȼ���)�ġ�����Ȼ�������Ϊ��Ļ����Ĳ㡣��Ȼ��治�ϵĶ����������Ļ�ڲ��ж�����и��١����Ǳ��ڵĳ�����ʵû������ʹ����Ȼ��棬��������������Ļ����ʾ3D����OpenGL����ʹ����Ȼ��档������������Ǹ������Ȼ����������Ͳ��Ὣһ��Բ�κ���������λ���Բ����������Ȼ�����OpenGLʮ����Ҫ�Ĳ��֡�*/
	glClearDepth(1.0f);	 // ������Ȼ���
	glEnable(GL_DEPTH_TEST);	 // ������Ȳ���
	glDepthFunc(GL_LEQUAL);	 // ������Ȳ��Ե�����
							 /*���Ÿ���OpenGL����ϣ��������õ�͸�����������ʮ����΢��Ӱ�����ܡ���ʹ��͸��ͼ��������һ�㡣*/
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	 // ����ϵͳ��͸�ӽ�������
														 /*������Ƿ���TRUE���������ϣ������ʼ���Ƿ�OK�����ǿ��Բ鿴���ص� TRUE��FALSE��ֵ������д������Ļ��������Լ������Լ��Ĵ��뷵��FALSE��Ŀǰ�����ǲ�������*/
	return TRUE;	 // ��ʼ�� OK
}
/*��һ�ΰ��������еĻ�ͼ���롣�κ�����������Ļ����ʾ�Ķ��������ڴ˶δ����г��֡�
�Ժ��ÿ���̳����Ҷ��������̵Ĵ˴������µĴ��롣
�������OpenGL�Ѿ������˽�Ļ����������� glLoadIdentity()����֮�󣬷���TRUEֵ֮ǰ���������һЩOpenGL�����������������Ρ��������OpenGL���֣������ҵ��¸��̡̳�Ŀǰ����������ȫ�����ǽ���Ļ���������ǰ������������ɫ�������Ȼ��沢�����ó�����������û�л����κζ�����
����TRUEֵ��֪���ǵĳ���û�г������⡣�����ϣ��������ΪĳЩԭ�����ֹ���У��ڷ���TRUEֵ֮ǰ���ӷ���FALSE�Ĵ����֪���ǵĳ����ͼ����������򼴽��˳���*/
int DrawGLScene(bool keys[])	 // �����￪ʼ�������еĻ���
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	 // �����Ļ����Ȼ���
	glLoadIdentity();	 // ���õ�ǰ��ģ�͹۲����
						 //drawTriangleAndSquare();
						 //drawThreePyramid();
						 //textureMapping();
	drawMap();
	return TRUE;	 // һ�� OK
}
/*��һ�δ���ֻ�ڳ����˳�֮ǰ���á�KillGLWindow() �������������ͷ���ɫ�������豸������ʹ��ھ����
���Ѿ��������������顣��������޷����ٴ��ڵ����ⲿ�֣����ᵯ������Ӧ������Ϣ��ѶϢ���ڣ�������ʲô�����ˡ�
ʹ�������Ĵ����в���ø�����Щ��*/
GLvoid KillGLWindow(GLvoid)	 // �������ٴ���
{
	/*������KillGLWindow()�������ĵ�һ�����Ǽ�������Ƿ���ȫ��ģʽ������ǣ�����Ҫ�л������档���Ǳ�Ӧ�ڽ���ȫ��ģʽǰ�����ٴ��ڣ�����ĳЩ�Կ�����ô�����ܻ�ʹ������������������ǻ����Ƚ���ȫ��ģʽ���⽫��ֹ������ֱ���������Nvidia��3dfx�Կ��϶������ĺܺã�*/
	if (fullscreen)	 // ���Ǵ���ȫ��ģʽ��?
	{
		/*����ʹ��ChangeDisplaySettings(NULL,0)�ص�ԭʼ���档��NULL��Ϊ��һ��������0��Ϊ�ڶ�����������ǿ��Windowsʹ�õ�ǰ�����ע����е�ֵ(ȱʡ�ķֱ��ʡ�ɫ����ȡ�ˢ��Ƶ�ʣ��ȵ�)����Ч�Ļָ����ǵ�ԭʼ���档�л�����������ǻ�Ҫʹ�����ָ�����¿ɼ���*/
		ChangeDisplaySettings(NULL, 0);	 // �ǵĻ����л�������
		ShowCursor(TRUE);	 // ��ʾ���ָ��
	}
	/*�������Ĵ���鿴�����Ƿ�ӵ����ɫ������(hRC)�����û�У�������ת������Ĵ���鿴�Ƿ�ӵ���豸������*/
	if (hRC)	 // ����ӵ��OpenGL��Ⱦ��������?
	{
		/*���������ɫ������Ļ�������Ĵ��뽫�鿴�����ܷ��ͷ���(�� hRC��hDC�ֿ�)��������ע����ʹ�õĵĲ��������������ֻ���ó������ͷ���ɫ������(ͨ������wglMakeCurrent(NULL,NULL)��Ȼ�����ٲ鿴�ͷ��Ƿ�ɹ�������Ľ����д����ϵ���һ�С�*/
		if (!wglMakeCurrent(NULL, NULL))	 // �����ܷ��ͷ�DC��RC������?
		{
			/*��������ͷ�DC��RC������Ļ���MessageBox()������������Ϣ����֪����DC��RC�޷����ͷš�NULL��ζ����Ϣ����û�и����ڡ����ҵ����ֽ�����Ϣ�����ϳ��֡�"SHUTDOWN ERROR"�����ڴ��ڵı������ϡ�MB_OK����˼��Ϣ�����ϴ���һ��д��OK�����İ�ť��
			MB_ICONINFORMATION������Ϣ��������ʾһ����Ȧ��Сд��i(����ȥ����ʽһЩ)��*/
			MessageBox(NULL, "�ͷ�DC��RCʧ�ܡ�", "�رմ���", MB_OK | MB_ICONINFORMATION);
		}
		/*��һ����������ɾ����ɫ������������ɹ��Ļ�����������Ϣ��*/
		if (!wglDeleteContext(hRC))	 // �����ܷ�ɾ��RC?
		{
			/*����޷�ɾ����ɫ������Ļ���������������Ϣ��֪����RCδ�ܳɹ�ɾ����Ȼ��hRC����ΪNULL��*/
			MessageBox(NULL, "�ͷ�RCʧ�ܡ�", "�رմ���", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;	 // ��RC��Ϊ NULL
	}
	/*�������ǲ鿴�Ƿ�����豸����������г����ͷ�������������ͷ��豸����������������Ϣ��Ȼ��hDC��ΪNULL��*/
	if (hDC && !ReleaseDC(hWnd, hDC))	 // �����ܷ��ͷ� DC?
	{
		MessageBox(NULL, "�ͷ�DCʧ�ܡ�", "�رմ���", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;	 // �� DC ��Ϊ NULL
	}
	/*�����������鿴�Ƿ���ڴ��ھ�������ǵ��� DestroyWindow( hWnd )���������ٴ��ڡ�������ܵĻ��������󴰿ڣ�Ȼ��hWnd����ΪNULL��*/
	if (hWnd && !DestroyWindow(hWnd))	 // �ܷ����ٴ���?
	{
		MessageBox(NULL, "�ͷŴ��ھ��ʧ�ܡ�", "�رմ���", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;	 // �� hWnd ��Ϊ NULL
	}
	/*���Ҫ��������ע�����ǵĴ����ࡣ�����������������ٴ��ڣ������ڴ���������ʱ�������յ�����"Windows Class already registered"(��������ע��)�Ĵ�����Ϣ��*/
	if (!UnregisterClass("OpenG", hInstance))	 // �ܷ�ע����?
	{
		MessageBox(NULL, "����ע�������ࡣ", "�رմ���", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;	 // �� hInstance ��Ϊ NULL
	}
}
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	/*������Ҫ��WindowsΪ����Ѱ����ƥ������ظ�ʽʱ��WindowsѰ�ҽ�����ģʽֵ�����ڱ���PixelFormat�С�*/
	GLuint	 PixelFormat;	 // �������ƥ��Ľ��
							 /*wc�����������ǵĴ�����Ľṹ��������ṹ�б��������ǵĴ�����Ϣ��ͨ���ı���Ĳ�ͬ�ֶ����ǿ��Ըı䴰�ڵ���ۺ���Ϊ��ÿ�����ڶ�����һ�������ࡣ������������ʱ��������Ϊ����ע���ࡣ*/
	WNDCLASS	wc;	 // ������ṹ
					 /*dwExStyle��dwStyle�����չ��ͨ���Ĵ��ڷ����Ϣ����ʹ�ñ�������ŷ���Ŀ����Ϊ���ܹ���������Ҫ�����Ĵ�������(��ȫ��Ļ�µĵ������ڻ��Ǵ���ģʽ�µĴ��߿����ͨ����)�����ı䴰�ڵķ��*/
	DWORD	 dwExStyle;	 // ��չ���ڷ��
	DWORD	 dwStyle;	 // ���ڷ��
						 /*�����5�д���ȡ�þ��ε����ϽǺ����½ǵ�����ֵ�����ǽ�ʹ����Щֵ���������ǵĴ���ʹ�����ϵĻ�ͼ���Ĵ�Сǡ������������ķֱ��ʵ�ֵ��ͨ��������Ǵ���һ��640x480�Ĵ��ڣ����ڵı߿��ռ��һЩ�ֱ��ʵ�ֵ��*/
	RECT WindowRect;	 // ȡ�þ��ε����ϽǺ����½ǵ�����ֵ
	WindowRect.left = (long)0;	 // ��Left ��Ϊ 0
	WindowRect.right = (long)width;	 // ��Right ��ΪҪ��Ŀ��
	WindowRect.top = (long)0;	 // ��Top ��Ϊ 0
	WindowRect.bottom = (long)height;	 // ��Bottom ��ΪҪ��ĸ߶�
										 /*��һ�д���������ȫ�ֱ���fullscreen����fullscreenflag���������ϣ����ȫ��Ļ�����ж���fullscreenflag��ΪTRUE����û���ñ���fullscreen����fullscreenflag�Ļ���fullscreen����������ΪFALSE����������ȫ��Ļģʽ�����ٴ��ڵ�ʱ�򣬱���fullscreen��ֵȴ������ȷ��TRUEֵ�������������Ϊ�Ѿ���������ģʽ���޷��л������档�ϵ۰�����Ը��һ�ж������塣����һ�仰��fullscreen��ֵ������Զfullscreenflag��ֵ������ͻ������⡣*/
	fullscreen = fullscreenflag;	 // ����ȫ��ȫ����־
									 /*��һ���ֵĴ����У�����ȡ�ô��ڵ�ʵ����Ȼ���崰���ࡣCS_HREDRAW �� CS_VREDRAW ����˼�����ۺ�ʱ��ֻҪ���ڷ����仯ʱ��ǿ���ػ���CS_OWNDCΪ���ڴ���һ��˽�е�DC������ζ��DC�����ڳ���乲��WndProc�����ǳ������Ϣ������̡�����û��ʹ�ö���Ĵ������ݣ��������ֶ���Ϊ�㡣Ȼ������ʵ�����������ǽ�hIcon��ΪNULL����Ϊ���ǲ������������ͼ�ꡣ���ָ����Ϊ��׼�ļ�ͷ������ɫ����ν(������GL������)������Ҳ����Ҫ���ڲ˵������Խ�����ΪNULL��������ֿ�������Ҫ���κ����֡����ڼ򵥣��ҽ�ʹ��"OpenG"��*/
	hInstance = GetModuleHandle(NULL);	 // ȡ�����Ǵ��ڵ�ʵ��
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	 // �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
	wc.lpfnWndProc = (WNDPROC)WndProc;	 // WndProc������Ϣ
	wc.cbClsExtra = 0;	 // �޶��ⴰ������
	wc.cbWndExtra = 0;	 // �޶��ⴰ������
	wc.hInstance = hInstance;	 // ����ʵ��
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);	 // װ��ȱʡͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	 // װ�����ָ��
	wc.hbrBackground = NULL;	 // GL����Ҫ����
	wc.lpszMenuName = NULL;	 // ����Ҫ�˵�
	wc.lpszClassName = "OpenG";	 // �趨������
								 /*����ע�������֡�����д�����������������Ϣ���ڡ����������OK��ť�󣬳����˳�*/
	if (!RegisterClass(&wc))	 // ����ע�ᴰ����
	{
		MessageBox(NULL, "ע�ᴰ��ʧ��", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // �˳�������FALSE
	}
	/*�鿴����Ӧ����ȫ��ģʽ���Ǵ���ģʽ�����С����Ӧ����ȫ��ģʽ�Ļ������ǽ���������ȫ��ģʽ��*/
	if (fullscreen)	 // Ҫ����ȫ��ģʽ��?
	{
		/*��һ���ֵĴ��뿴���ܶ��˶���������Ҫ�ʹ���.......�л���ȫ��ģʽ�����л���ȫ��ģʽʱ���м���ʮ����Ҫ�����������μǡ�����ȷ������ȫ��ģʽ�����õĿ�Ⱥ͸߶ȵ�ͬ�ڴ���ģʽ�µĿ�Ⱥ͸߶ȡ�������Ҫ����Ҫ�ڴ�������֮ǰ����ȫ��ģʽ������Ĵ����У��������ٵ��Ŀ�Ⱥ͸߶ȣ������ѱ����ó�����ʾģʽ����Ӧ�Ĵ�С��*/
		DEVMODE dmScreenSettings;	 // �豸ģʽ
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	 // ȷ���ڴ����Ϊ��
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);	 // Devmode �ṹ�Ĵ�С
		dmScreenSettings.dmPelsWidth = width;	 // ��ѡ��Ļ���
		dmScreenSettings.dmPelsHeight = height;	 // ��ѡ��Ļ�߶�
		dmScreenSettings.dmBitsPerPel = bits;	 // ÿ������ѡ��ɫ�����
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		/*����Ĵ����У����Ƿ��������ڴ洢��Ƶ���õĿռ䡣�趨����Ļ�Ŀ��ߣ�ɫ����ȡ�����Ĵ������ǳ�������ȫ��ģʽ��������dmScreenSettings�б��������еĿ��ߣ�ɫ�����ѶϢ����һ��ʹ��ChangeDisplaySettings�������л�����dmScreenSettings��ƥ��ģʽ����ʹ�ò���CDS_FULLSCREEN���л���ʾģʽ����Ϊ������������ȥ����Ļ�ײ���״̬�����������������л�ʱ��û���ƶ���ı����������ϵĴ��ڡ�*/
		// ����������ʾģʽ�����ؽ����ע: CDS_FULLSCREEN ��ȥ��״̬����
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			/*���ģʽδ�����óɹ������ǽ��������µĴ��롣�������ƥ��ȫ��ģʽ��������Ϣ���ڣ��ṩ����ѡ��ڴ���ģʽ�����л��˳���*/
			// ��ģʽʧ�ܣ��ṩ����ѡ��˳����ڴ��������С�
			if (MessageBox(NULL, "ȫ��ģʽ�ڵ�ǰ�Կ�������ʧ�ܣ�\nʹ�ô���ģʽ��", "NeHe G", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				/*����û�ѡ�񴰿�ģʽ������fullscreen ��ֵ��ΪFALSE,����������С�*/
				fullscreen = FALSE;	 // ѡ�񴰿�ģʽ(Fullscreen=FALSE)
			}
			else
			{
				/*����û�ѡ���˳���������Ϣ���ڸ�֪�û����򽫽�����������FALSE���߳��򴰿�δ�ܳɹ������������˳���*/
				// ����һ���Ի��򣬸����û��������
				MessageBox(NULL, "���򽫱��ر�", "����", MB_OK | MB_ICONSTOP);
				return FALSE;	 // �˳������� FALSE
			}
		}
	}
	/*����ȫ��ģʽ����ʧ�ܣ��û����ܾ����ڴ��������У�������Ҫ��������Ļ/����֮ǰ���ٴμ��fullscreen��ֵ��TRUE��FALSE��*/
	if (fullscreen)	 // �Դ���ȫ��ģʽ��?
	{
		/*
		��������Դ���ȫ��ģʽ��������չ������ΪWS_EX_APPWINDOW���⽫ǿ�����ǵĴ���ɼ�ʱ������ǰ�档�ٽ�����ķ����ΪWS_POPUP��������͵Ĵ���û�б߿�ʹ���ǵ�ȫ��ģʽ����������ʾ��
		������ǽ������ָ�롣�����ĳ����ǽ���ʽ��ʱ����ȫ��ģʽ�½������ָ��ͨ���Ǹ������⡣
		*/
		dwExStyle = WS_EX_APPWINDOW;	 // ��չ������
		dwStyle = WS_POPUP;	 // ������
		ShowCursor(FALSE);	 // �������ָ��
	}
	else
	{
		/*�������ʹ�ô��ڶ�����ȫ��ģʽ����������չ�������������� WS_EX_WINDOWEDGE����ǿ�����3D�йۡ���������� WS_OVERLAPPEDWINDOW������һ�������������ɱ��С�ı߿򡢲˵������/��С����ť�Ĵ��塣*/
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	 // ��չ������
		dwStyle = WS_OVERLAPPEDWINDOW;	 // ������
	}
	/*��һ�д�����ݴ����Ĵ������͵������ڡ�������Ŀ����ʹ�ô��ڴ�С���õ�������Ҫ��ķֱ��ʡ�ͨ���߿��ռ�ô��ڵ�һ���֡�ʹ��AdjustWindowRectEx �����ǵ�OpenGL�����Ͳ��ᱻ�߿��ס��ʵ���ϴ��ڱ�ø����Ա���Ʊ߿�ȫ��ģʽ�£���������Ч��*/
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);	 // �������ڴﵽ����Ҫ��Ĵ�С
																 /*	��һ�δ��뿪ʼ�������ڲ���鴰���Ƿ�ɹ����������ǽ�����CreateWindowEx()��������в���������չ���������(������ע�ᴰ����ʱ���õ�������ͬ)�����ڱ��⡢�����񡢴�������Ͻ�����(0,0 �Ǹ���ȫ��ѡ��)������Ŀ�͸ߡ�����û�и����ڣ�Ҳ����Ҫ�˵�����Щ��������ΪNULL���������˴��ڵ�ʵ�������һ����������ΪNULL��
																 ע�������ڴ������а����� WS_CLIPSIBLINGS �� WS_CLIPCHILDREN��Ҫ��OpenGL�������У������������Ǳ���ġ�������ֹ��Ĵ��������ǵĴ�����/�ϻ�ͼ��*/
	if (!(hWnd = CreateWindowEx(dwExStyle,	 // ��չ������
		"OpenG",	 // ������
		title,	 // ���ڱ���
		WS_CLIPSIBLINGS |	 // ����Ĵ���������
		WS_CLIPCHILDREN |	 // ����Ĵ���������
		dwStyle,	 // ѡ��Ĵ�������
		0, 0,	 // ����λ��
		WindowRect.right - WindowRect.left,	// ��������õĴ��ڿ��
		WindowRect.bottom - WindowRect.top,	// ��������õĴ��ڸ߶�
		NULL,	 // �޸�����
		NULL,	 // �޲˵�
		hInstance,	 // ʵ��
		NULL)))	 // ����WM_CREATE�����κζ���
				 /*�������Ǽ�鿴�����Ƿ���������������ɹ��� hWnd���洰�ڵľ�������ʧ�ܣ�������Ϣ���ڣ����˳�����*/
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "���ܴ���һ�������豸������", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*����Ĵ����������ظ�ʽ������ѡ����ͨ��RGBA(�졢�̡�����alphaͨ��)֧��OpenGL��˫����ĸ�ʽ��������ͼ�ҵ�ƥ������ѡ����ɫ�����(16λ��24λ��32λ)�����ظ�ʽ���������16λZ-���档����Ĳ���Ҫôδʹ��Ҫô����Ҫ(stencil bufferģ�建���accumulation buffer�ۼ��������)��*/
	static	PIXELFORMATDESCRIPTOR pfd =	 // /pfd ���ߴ���������ϣ���Ķ�����������ʹ�õ����ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR),	 // ������ʽ�������Ĵ�С
		1,	 // �汾��
		PFD_DRAW_TO_WINDOW |	 // ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |	 // ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,	 // ����֧��˫����
		PFD_TYPE_RGBA,	 // ���� RGBA ��ʽ
		bits,	 // ѡ��ɫ�����
		0, 0, 0, 0, 0, 0,	 // ���Ե�ɫ��λ
		0,	 // ��Alpha����
		0,	 // ����Shift Bit
		0,	 // ���ۼӻ���
		0, 0, 0, 0,	 // ���Ծۼ�λ
		16,	 // 16λ Z-���� (��Ȼ���)
		0,	 // ���ɰ建��
		0,	 // �޸�������
		PFD_MAIN_PLANE,	 // ����ͼ��
		0,	 // Reserved
		0, 0, 0	 // ���Բ�����
	};
	/*���ǰ�洴������ʱû�д����������ǽ��ų���ȡ��OpenGL�豸���������޷�ȡ��DC������������Ϣ�����˳�(����FALSE)��*/
	if (!(hDC = GetDC(hWnd)))	 // ȡ���豸��������ô?
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "���ܴ���һ����ƥ������ظ�ʽ", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*�跨ΪOpenGL����ȡ���豸����������ǳ����ҵ���Ӧ���ǰ����ѡ�������ظ�ʽ�����ظ�ʽ�����Windows�����ҵ��Ļ�������������Ϣ�����˳�����(����FALSE)��*/
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	 // Windows �ҵ���Ӧ�����ظ�ʽ����?
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "�����������ظ�ʽ", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*Windows �ҵ���Ӧ�����ظ�ʽ�󣬳����������ظ�ʽ������޷����ã�����������Ϣ�����˳�����(����FALSE)��*/
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))	 // �ܹ��������ظ�ʽô?
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "�����������ظ�ʽ", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*�����������ظ�ʽ�󣬳���ȡ����ɫ�������������ȡ����ɫ������Ļ�������������Ϣ�����˳�����(����FALSE)��*/
	if (!(hRC = wglCreateContext(hDC)))	 // �ܷ�ȡ����ɫ������?
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "���ܴ���OpenGL��Ⱦ������", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*�����������δ���ִ���Ļ��������Ѿ��跨ȡ�����豸���������ɫ����������Ҫ�����Ǽ�����ɫ����������޷��������������Ϣ�����˳�����(����FALSE)��*/
	if (!wglMakeCurrent(hDC, hRC))	 // ���Լ�����ɫ������
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "���ܼ��ǰ��OpenGL��Ȼ������", "����", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*һ��˳���Ļ���OpenGL�����Ѿ�������ɣ����ſ�����ʾ������������Ϊǰ�˴���(�������ߵ����ȼ�)���������������˴��ڡ�Ȼ�����ReSizeGLScene ����Ļ�Ŀ�Ⱥ͸߶����ø�͸��OpenGL��Ļ��*/
	ShowWindow(hWnd, SW_SHOW);	 // ��ʾ����
	SetForegroundWindow(hWnd);	 // ����������ȼ�
	SetFocus(hWnd);	 // ���ü��̵Ľ������˴���
	ReSizeGLScene(width, height);	 // ����͸�� GL ��Ļ
									 /*��ת�� InitGL()������������ù��ա������ȵ��κ���Ҫ���õĶ������������� InitGL()�ڲ����ж�������飬������ TRUE (һ������)��FALSE (��ʲô����)�����磬�������InitGL()��װ���������ִ���������ϣ������ֹͣ����������� FALSE�Ļ�������Ĵ���ᵯ��������Ϣ�����˳�����*/
	if (!InitGL())	 // ��ʼ���½���GL����
	{
		KillGLWindow();	 // ������ʾ��
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;	 // ���� FALSE
	}
	/*��������԰�ȫ���ƶ����������Ѿ��ɹ��ˡ�������WinMain()����TRUE����֪WinMain()û�д����Է�ֹ�����˳���*/
	return TRUE;	 // �ɹ�
}
/*����Ĵ��봦�����еĴ�����Ϣ��������ע��ô�����֮�󣬳�����ת���ⲿ�ִ��봦������Ϣ��*/
LRESULT CALLBACK WndProc(HWND	hWnd,	 // ���ڵľ��
	UINT	uMsg,	 // ���ڵ���Ϣ
	WPARAM	wParam,	 // ���ӵ���Ϣ����
	LPARAM	lParam)	 // ���ӵ���Ϣ����
{
	/*����Ĵ���ȶ�uMsg��ֵ��Ȼ��ת��case����uMsg �б���������Ҫ�������Ϣ���֡�*/
	switch (uMsg)	 // ���Windows��Ϣ
	{
		/*���uMsg����WM_ACTIVE���鿴�����Ƿ���Ȼ���ڼ���״̬����������ѱ���С����������active��ΪFALSE����������ѱ��������active��ֵΪTRUE��*/
	case WM_ACTIVATE:	 // ���Ӵ��ڼ�����Ϣ
	{
		if (!HIWORD(wParam))	 // �����С��״̬
		{
			active = TRUE;	 // �����ڼ���״̬
		}
		else
		{
			active = FALSE;	 // �����ټ���
		}
		return 0;	 // ������Ϣѭ��
	}
	/*�����Ϣ��WM_SYSCOMMAND(ϵͳ����)���ٴαȶ�wParam�����wParam �� SC_SCREENSAVE �� SC_MONITORPOWER�Ļ�����������Ļ����Ҫ���У�������ʾ�������ڵ�ģʽ������0������ֹ�������·�����*/
	case WM_SYSCOMMAND:	 // ϵͳ�ж�����
	{
		switch (wParam)	 // ���ϵͳ����
		{
		case SC_SCREENSAVE:	 // ����Ҫ����?
		case SC_MONITORPOWER:	 // ��ʾ��Ҫ����ڵ�ģʽ?
			return 0;	 // ��ֹ����
		}
		break;	 // �˳�
	}
	/*��� uMsg��WM_CLOSE�����ڽ����رա����Ƿ����˳���Ϣ����ѭ�������жϡ�����done����ΪTRUE��WinMain()����ѭ����ֹ������رա�*/
	case WM_CLOSE:	 // �յ�Close��Ϣ?
	{
		PostQuitMessage(0);	 // �����˳���Ϣ
		return 0;	 // ����
	}
	/*��������м����£�ͨ����ȡwParam����Ϣ�����ҳ���ֵ���ҽ���������keys[ ]��Ӧ���������Ա��ֵ��ΪTRUE�������Ժ�Ϳ��Բ���key[ ]����֪ʲô�������¡�����ͬʱ���¶������*/
	case WM_KEYDOWN:	 // �м�����ô?
	{
		keys[wParam] = TRUE;	 // ����ǣ���ΪTRUE
		return 0;	 // ����
	}
	/*ͬ������������м��ͷţ�ͨ����ȡwParam����Ϣ�����ҳ���ֵ��Ȼ�󽫼�������keys[ ]��Ӧ���������Ա��ֵ��ΪFALSE����������key[ ]����֪ʲô�������£�ʲô�����ͷ��ˡ������ϵ�ÿ������������0-255֮���һ����������������˵�������ǰ���40������ļ�ʱ��keys[40]��ֵ������ΪTRUE���ſ��Ļ������ͱ���ΪFALSE����Ҳ��key�����ԭ��*/
	case WM_KEYUP:	 // �м��ſ�ô?
	{
		keys[wParam] = FALSE;	 // ����ǣ���ΪFALSE
		return 0;	 // ����
	}
	/*����������ʱ��uMsg ��������ϢWM_SIZE����ȡlParam��LOWORD ��HIWORD���Եõ������µĿ�Ⱥ͸߶ȡ������Ǵ��ݸ�ReSizeGLScene()��OpenGL����������Ϊ�µĿ�Ⱥ͸߶ȡ�*/
	case WM_SIZE:	 // ����OpenGL���ڴ�С
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));	 // LoWord=Width,HiWord=Height
		return 0;	 // ����
	}
	}
	/*�����޹ص���Ϣ�����ݸ�DefWindowProc����Windows���д���*/
	// �� DefWindowProc��������δ�������Ϣ��
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
bool LoadTexture(LPTSTR szFileName, GLuint &texid) // ��λͼ��������
{
	HBITMAP hBMP; // λͼ���
	BITMAP BMP; // λͼ�ṹ
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	if (!hBMP) return FALSE; //���λͼ�Ƿ����
							 /*����ʹ���� TextureImage[0] �����ݴ�������
							 ��һ�� glGenTextures(1, &texture[0]) ����OpenGL����������һ����������(������������������Ӵ�����)��
							 ֵ��ע����ǣ���ʼ����ʹ�� GLuint texture[1] ������һ������Ĵ洢�ռ䣬
							 ��Ҳ�����Ϊ��һ��������Ǵ���� &texture[1] �еģ������Ǵ�ġ���ȷ�ĵ�ַӦ���� &texture[0] ��
							 ͬ�����ʹ�� GLuint texture[2] �Ļ����ڶ����������� texture[1] �С�������ע��ѧC�ģ�������Ӧ��û���ϰ���������Ǵ��㿪ʼ�����*/
	glGenTextures(1, &texid); // ��������
							  // hBMP: ͼ�������
							  // sizeof(BMP): ������Ϣ��������С
							  // &BMP: ������Ϣ������
	GetObject(hBMP, sizeof(BMP), &BMP); // ��ȡ����
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // ���ش洢ģʽ(Word Alignment / 4 Bytes)�ֽڶ���
										   // Typical Texture Generation Using Data From The Bitmap
										   /*�ڶ��� glBindTexture(GL_TEXTURE_2D, texture[0])
										   ����OpenGL���������� texture[0] �󶨵�����Ŀ���ϡ�
										   2D����ֻ�и߶�(�� Y ����)�Ϳ��(�� X ����)��
										   ����������������ָ�ɸ��������ݡ�
										   ���������Ǹ�֪OpenGL�� &texture[0] �����ڴ��Ѿ����á�
										   ���Ǵ����������洢�� &texture[0] �� ָ����ڴ�����*/
	glBindTexture(GL_TEXTURE_2D, texid); // ʹ������λͼ�������� �ĵ�������
										 /*��������и���OpenGL����ʾͼ��ʱ��
										 �����ȷŴ��ԭʼ�������(GL_TEXTURE_MAG_FILTER)����С�ñ�ԭʼ������С(GL_TEXTURE_MIN_FILTER)ʱ
										 OpenGL���õ��˲���ʽ��ͨ��������������Ҷ����� GL_LINEAR ��
										 ��ʹ������Ӻ�Զ��������Ļ�ܽ�ʱ��ƽ����ʾ��
										 ʹ�� GL_LINEAR ��ҪCPU���Կ�����������㡣������Ļ�����������Ҳ��Ӧ�ò��� GL_NEAREST ��
										 ���˵������ڷŴ��ʱ�򣬿������߲��ĺܡ�����ע��������������
										 ��Ҳ���Խ���������˲���ʽ���ڽ���ʱʹ�� GL_LINEAR ��Զ��ʱ GL_NEAREST ��*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // �����˲�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // �����˲�
																	  /*�������Ǵ�����������������һ�и���OpenGL��������һ��2D����(GL_TEXTURE_2D)��
																	  ������0������ͼ�����ϸ�̶ȣ�ͨ��������Ϊ��ȥ�ˡ�
																	  �����������ݵĳɷ�������Ϊͼ�����ɺ�ɫ���ݣ���ɫ���ݣ���ɫ�������������ɡ�
																	  TextureImage[0]->sizeX ������Ŀ�ȡ������֪����ȣ����������������룬����������Ժ����׵�Ϊ��ָ����ֵ��
																	  TextureImage[0]->sizey ������ĸ߶ȡ�
																	  �������Ǳ߿��ֵ��һ����ǡ�0���� GL_RGB ����OpenGLͼ�������ɺ졢�̡�����ɫ������ɡ�
																	  GL_UNSIGNED_BYTE ��ζ�����ͼ����������޷����ֽ����͵ġ�
																	  ���... TextureImage[0]->data ����OpenGL�������ݵ���Դ��
																	  ������ָ������ TextureImage[0] ��¼�е����ݡ�*/
	glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
	DeleteObject(hBMP); // ɾ������
	return TRUE; // ���سɹ�
}