#include "openglDemo.h"
HGLRC hRC = NULL;	 // ������ɫ��������
HDC hDC = NULL;	 // OpenGL��Ⱦ��������
HWND hWnd = NULL;	 // �������ǵĴ��ھ��
HINSTANCE hInstance;	 // ��������ʵ��
						 /*����ĵ�һ������һ��������ؼ��̶��������顣����෽�����Լ�ؼ��̵Ķ�����������ķ����ܿɿ������ҿ��Դ�������ͬʱ���µ������
						 active ����������֪���򴰿��Ƿ�����С����״̬����������Ѿ���С���Ļ������ǿ���������ͣ����ִ�е��˳�������κ����顣��ϲ����ͣ������������ʹ�ó������ں�̨�������С�
						 fullscreen �����������൱���ԡ�������ǵĳ�����ȫ��״̬�����У� fullscreen ��ֵΪTRUE������ΪFALSE�����ȫ�ֱ���������ʮ����Ҫ������ÿ�����̶�֪�������Ƿ�������ȫ��״̬�¡�*/
bool	keys[256];	 // ������̰���������
bool	active = TRUE;	 // ���ڵĻ��־��ȱʡΪTRUE
bool	fullscreen = FALSE;	 // ȫ����־ȱʡ��
GLfloat	 rtri = 0;	 // ���������εĽǶ�
GLfloat	 rquad;	 // �����ı��εĽǶ�
int width = 600;
int height = 480;
GLfloat	 xrot = 0;	 // X ��ת��
GLfloat	 yrot = 0;	 // Y ��ת��
GLfloat	 zrot = 0;	 // Z ��ת��
GLuint	 texture[1];	 // �洢һ������
						 /*���������ǵ�Windows�������ڡ�������ô��ڴ������̣���������Ϣ���������˻�������*/
int WINAPI WinMain(HINSTANCE	hInstance,	 // ��ǰ����ʵ��
	HINSTANCE	hPrevInstance,	 // ǰһ������ʵ��
	LPSTR	 lpCmdLine,	 // �����в���
	int	 nCmdShow)	 // ������ʾ״̬
{
	/*FILE *fs;
	AllocConsole();
	freopen_s(&fs, "conout$", "w", stdout);*/
	/*������������������msg ��������Ƿ�����Ϣ�ȴ�����
	done�ĳ�ʼֵ��ΪFALSE������ζ�����ǵĳ�����δ������С�
	ֻҪ����done����FALSE������������С�һ��done��ֵ�ı�ΪTRUE�������˳���*/
	MSG	msg;	 // Windowsx��Ϣ�ṹ
	BOOL done = FALSE;	 // �����˳�ѭ����Bool ����
						 /*���Ŵ���OpenGL���ڡ�
						 CreateGLWindow�����Ĳ�������Ϊ���⡢��ȡ��߶ȡ�ɫ����ȣ��Լ�ȫ����־��
						 ����ô�򵥣��Һ�������δ���ļ�ࡣ���δ�ܴ����ɹ�����������FALSE��
						 ���������˳���*/
						 // ����OpenGL����
	if (!CreateGLWindow("OpenGL Demo", width, height, 16, fullscreen))
	{
		return 0;	 // ʧ���˳�
	}
	/*������ѭ���Ŀ�ʼ��ֻҪdone����FALSE��ѭ��һֱ���С�*/
	while (!done)	 // ����ѭ��ֱ�� done=TRUE
	{
		/*����Ҫ���ĵ�һ�����Ǽ���Ƿ�����Ϣ�ڵȴ���
		ʹ��PeekMessage()�����ڲ���ס���ǵĳ����ǰ���¶���Ϣ���м�顣
		������ʹ��GetMessage()��Ҳ���ԺܺõĹ�����
		��ʹ��GetMessage()���������յ�paint��Ϣ���������ʲô������Ϣ֮ǰ�������κ��¡�*/
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	 // ����Ϣ�ڵȴ���?
		{
			/*����Ĵ���鿴�Ƿ�����˳���Ϣ��
			�����ǰ����Ϣ����PostQuitMessage(0)�����WM_QUIT��done��������ΪTRUE�������˳���*/
			if (msg.message == WM_QUIT)	 // �յ��˳���Ϣ?
			{
				done = TRUE;	 // �ǣ���done=TRUE
			}
			else	 // ���ǣ���������Ϣ
			{
				/*��������˳���Ϣ�����Ƿ�����Ϣ��Ȼ������Ϣ��ʹ��WndProc() �� Windows�ܹ��������ǡ�*/
				TranslateMessage(&msg);	 // ������Ϣ
				DispatchMessage(&msg);	 // ������Ϣ
			}
		}
		else	 // ���û����Ϣ
		{
			/*���û����Ϣ���������ǵ�OpenGL������
			����ĵ�һ�в鿴�����Ƿ񼤻�������ESC����done��������ΪTRUE�����򽫻��˳���*/
			// ���Ƴ���������ESC��������DrawGLScene()���˳���Ϣ
			if (active)	 // ���򼤻��ô?
			{
				if (keys[VK_ESCAPE])	 // ESC ������ô?
				{
					done = TRUE;	 // ESC �����˳��ź�
				}
				else	 // �����˳���ʱ��ˢ����Ļ
				{
					/*��������Ǽ������ESCû�а��£����ǻ��Ƴ�������������(ʹ��˫�������ʵ������˸�Ķ���)��
					����ʵ��������һ����������"��Ļ"�ϻ�ͼ��
					�����ǽ�����������ǵ�ǰ����Ļ�����أ����ڿ������Ǹղſ���������Ļ��
					��Ҳ�����ǿ������������ƹ��̵�ԭ�򡣳���ֻ�Ǽ�ʱ��ʾ��*/
					DrawGLScene(keys);	 // ���Ƴ���
					SwapBuffers(hDC);	 // �������� (˫����)
				}
			}
			/*�����һ�����������¼ӵ�(05-01-00)��
			�����û�����F1����ȫ��ģʽ�ʹ���ģʽ���л���*/
			if (keys[VK_F1])	 // F1��������ô?
			{
				keys[VK_F1] = FALSE;	 // ���ǣ�ʹ��Ӧ��Key�����е�ֵΪ FALSE
				KillGLWindow();	 // ���ٵ�ǰ�Ĵ���
				fullscreen = !fullscreen;	 // �л� ȫ�� / ���� ģʽ
											 // �ؽ� OpenGL ����
				if (!CreateGLWindow("OpenGl Demo", 640, 480, 16, fullscreen))
				{
					return 0;	 // �������δ�ܴ����������˳�
				}
			}
		}
	}
	/*���done����������FALSE�������˳�����������OpenGL���ڣ������е��ڴ��ͷţ��˳�����	*/
	// �رճ���
	KillGLWindow();	 // ���ٴ���
					 //FreeConsole();
	return (msg.wParam);	 // �˳�����
}