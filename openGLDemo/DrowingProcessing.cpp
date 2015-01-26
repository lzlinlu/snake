#include "openglDemo.h"
int drawTriangleAndSquare() {
	//一条横线
	glTranslatef(0.0f, 0.0f, -1.0f);	 // 右移1.5单位,并移入屏幕 6.0
	glColor3f(1.0f, 0.0f, 0.0f);	 // 设置当前色为红色
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();
	glLoadIdentity();	 // 重置模型观察矩阵
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);	 // 绕Y轴旋转三角形
	glBegin(GL_TRIANGLES);	 // 绘制三角形
	glColor3f(1.0f, 0.0f, 0.0f);	 // 设置当前色为红色
	glVertex3f(0.0f, 1.0f, 0.0f);	 // 上顶点
	glColor3f(0.0f, 1.0f, 0.0f);	 // 设置当前色为绿色
	glVertex3f(-1.0f, -1.0f, 0.0f);	 // 左下
	glColor3f(0.0f, 0.0f, 1.0f);	 // 设置当前色为蓝色
	glVertex3f(1.0f, -1.0f, 0.0f);	 // 右下
	glEnd();
	glLoadIdentity();	 // 重置模型观察矩阵
	glTranslatef(1.5f, 0.0f, -6.0f);	 // 右移1.5单位,并移入屏幕 6.0
										 //glTranslatef(3.0f, 0.0f, 0.0f);	 // 右移3单位
	glRotatef(rquad, 1.0f, 0.0f, 0.0f);	 // 绕X轴旋转四边形
	glBegin(GL_QUADS);	 // 绘制正方形
	glVertex3f(-1.0f, 1.0f, 0.0f);	 // 左上
	glVertex3f(1.0f, 1.0f, 0.0f);	 // 右上
	glVertex3f(1.0f, -1.0f, 0.0f);	 // 左下
	glVertex3f(-1.0f, -1.0f, 0.0f);	 // 右下
	glEnd();	 // 正方形绘制结束
	rtri += 1.0f;	 // 增加三角形的旋转变量
	rquad -= 1.0f;	 // 减少四边形的旋转变量
	return NULL;
}
int drawThreePyramid() {
	glTranslatef(-1.5f, 0.0f, -6.0f);	 // 左移 1.5 单位，并移入屏幕 6.0
	glRotatef(rtri, 0.0f, 1.0f, 0.0f);	 // 绕Y轴旋转金字塔
	glBegin(GL_TRIANGLES);	 // 开始绘制金字塔的各个面
	glColor3f(1.0f, 0.0f, 0.0f);	 // 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	 // 三角形的上顶点 (前侧面)
	glColor3f(0.0f, 1.0f, 0.0f);	 // 绿色
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // 三角形的左下顶点 (前侧面)
	glColor3f(0.0f, 0.0f, 1.0f);	 // 蓝色
	glVertex3f(1.0f, -1.0f, 1.0f);	 // 三角形的右下顶点 (前侧面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	 // 三角形的上顶点 (右侧面)
	glColor3f(0.0f, 0.0f, 1.0f);	 // 蓝色
	glVertex3f(1.0f, -1.0f, 1.0f);	 // 三角形的左下顶点 (右侧面)
	glColor3f(0.0f, 1.0f, 0.0f);	 // 绿色
	glVertex3f(1.0f, -1.0f, -1.0f);	 // 三角形的右下顶点 (右侧面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	 // 三角形的上顶点 (后侧面)
	glColor3f(0.0f, 1.0f, 0.0f);	 // 绿色
	glVertex3f(1.0f, -1.0f, -1.0f);	 // 三角形的左下顶点 (后侧面)
	glColor3f(0.0f, 0.0f, 1.0f);	 // 蓝色
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // 三角形的右下顶点 (后侧面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 红色
	glVertex3f(0.0f, 1.0f, 0.0f);	 // 三角形的上顶点 (左侧面)
	glColor3f(0.0f, 0.0f, 1.0f);	 // 蓝色
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // 三角形的左下顶点 (左侧面)
	glColor3f(0.0f, 1.0f, 0.0f);	 // 绿色
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // 三角形的右下顶点 (左侧面)
	glEnd();	 // 金字塔绘制结束
	glLoadIdentity();
	glTranslatef(1.5f, 0.0f, -7.0f);	 // 先右移再移入屏幕
	glRotatef(rquad, 1.0f, 1.0f, 1.0f);	 // 在XYZ轴上旋转立方体
	glBegin(GL_QUADS);	 // 开始绘制立方体
	glColor3f(0.0f, 1.0f, 0.0f);	 // 颜色改为蓝色
	glVertex3f(1.0f, 1.0f, -1.0f);	 // 四边形的右上顶点 (顶面)
	glColor3f(1.0f, 1.0f, 0.0f);	 // 颜色改成黄色
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // 四边形的左上顶点 (顶面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 颜色改成红色
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // 四边形的左下顶点 (顶面)
	glColor3f(1.0f, 0.0f, 1.0f);	 // 颜色改成紫罗兰色
	glVertex3f(1.0f, 1.0f, 1.0f);	 // 四边形的右下顶点 (顶面)
	glColor3f(1.0f, 0.5f, 0.0f);	 // 颜色改成橙色
	glVertex3f(1.0f, -1.0f, 1.0f);	 // 四边形的右上顶点(底面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // 四边形的左上顶点(底面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // 四边形的左下顶点(底面)
	glVertex3f(1.0f, -1.0f, -1.0f);	 // 四边形的右下顶点(底面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 颜色改成红色
	glColor3f(1.0f, 0.0f, 1.0f);	 // 颜色改成紫罗兰色
	glVertex3f(1.0f, 1.0f, 1.0f);	 // 四边形的右上顶点(前面)
	glColor3f(1.0f, 0.0f, 0.0f);	 // 颜色改成红色
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // 四边形的左上顶点(前面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // 四边形的左下顶点(前面)
	glColor3f(1.0f, 0.5f, 0.0f);	 // 颜色改成橙色
	glVertex3f(1.0f, -1.0f, 1.0f);	 // 四边形的右下顶点(前面)
	glColor3f(1.0f, 1.0f, 0.0f);	 // 颜色改成黄色
	glVertex3f(1.0f, -1.0f, -1.0f);	 // 四边形的右上顶点(后面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // 四边形的左上顶点(后面)
	glColor3f(1.0f, 1.0f, 0.0f);	 // 颜色改成黄色
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // 四边形的左下顶点(后面)
	glColor3f(0.0f, 1.0f, 0.0f);	 // 颜色改为蓝色
	glVertex3f(1.0f, 1.0f, -1.0f);	 // 四边形的右下顶点(后面)
	glColor3f(0.0f, 0.0f, 1.0f);	 // 颜色改成蓝色
	glColor3f(1.0f, 0.0f, 0.0f);	 // 颜色改成红色
	glVertex3f(-1.0f, 1.0f, 1.0f);	 // 四边形的右上顶点(左面)
	glColor3f(1.0f, 1.0f, 0.0f);	 // 颜色改成黄色
	glVertex3f(-1.0f, 1.0f, -1.0f);	 // 四边形的左上顶点(左面)
	glVertex3f(-1.0f, -1.0f, -1.0f);	 // 四边形的左下顶点(左面)
	glVertex3f(-1.0f, -1.0f, 1.0f);	 // 四边形的右下顶点(左面)
	glColor3f(1.0f, 0.0f, 1.0f);	 // 颜色改成紫罗兰色
	glColor3f(0.0f, 1.0f, 0.0f);	 // 颜色改为蓝色
	glVertex3f(1.0f, 1.0f, -1.0f);	 // 四边形的右上顶点(右面)
	glVertex3f(1.0f, 1.0f, 1.0f);	 // 四边形的左上顶点(右面)
	glColor3f(1.0f, 0.5f, 0.0f);	 // 颜色改成橙色
	glVertex3f(1.0f, -1.0f, 1.0f);	 // 四边形的左下顶点(右面)
	glVertex3f(1.0f, -1.0f, -1.0f);	 // 四边形的右下顶点(右面)
	glEnd();	 // 立方体绘制结束
	rtri += 1.0f;	 // 增加三角形的旋转变量
	rquad -= 1.0f;	 // 减少四边形的旋转变量
	return NULL;
}
int textureMapping() {
	glLoadIdentity();	 // 重置当前的模型观察矩阵
	glTranslatef(0.0f, 0.0f, -5.0f);	 // 移入屏幕 5 个单位
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);	 // 绕X轴旋转
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);	 // 绕Y轴旋转
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);	 // 绕Z轴旋转
	glBindTexture(GL_TEXTURE_2D, texture[0]);	 // 选择纹理
												 /*	为了将纹理正确的映射到四边形上，您必须将纹理的右上角映射到四边形的右上角，纹理的左上角映射到四边形的左上角，纹理的右下角映射到四边形的右下角，纹理的左下角映射到四边形的左下角。如果映射错误的话，图像显示时可能上下颠倒，侧向一边或者什么都不是。
												 glTexCoord2f 的第一个参数是X坐标。 0.0f 是纹理的左侧。 0.5f 是纹理的中点， 1.0f 是纹理的右侧。 glTexCoord2f 的第二个参数是Y坐标。 0.0f 是纹理的底部。 0.5f 是纹理的中点， 1.0f 是纹理的顶部。
												 所以纹理的左上坐标是 X：0.0f，Y：1.0f ，四边形的左上顶点是 X： -1.0f，Y：1.0f 。其余三点依此类推。
												 试着玩玩 glTexCoord2f 的X，Y坐标参数。把 1.0f 改为 0.5f 将只显示纹理的左半部分，把 0.0f 改为 0.5f 将只显示纹理的右半部分。*/
	glBegin(GL_QUADS);
	// 前面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// 纹理和四边形的左上
																// 后面
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// 纹理和四边形的左下
																// 顶面
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// 纹理和四边形的右上
																// 底面
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// 纹理和四边形的右下
																// 右面
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);	// 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);	// 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// 纹理和四边形的左上
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// 纹理和四边形的左下
																// 左面
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// 纹理和四边形的左下
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// 纹理和四边形的右下
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// 纹理和四边形的右上
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);	// 纹理和四边形的左上
	glEnd();
	/*现在增加 xrot, yrot 和 zrot 的值。尝试变化每次各变量的改变值来调节立方体的旋转速度，或改变 + / -号来调节立方体的旋转方向。*/
	xrot += 0.3f;	 // X 轴旋转
	yrot += 0.2f;	 // Y 轴旋转
	zrot += 0.4f;	 // Z 轴旋转
	return true;	 // 继续运行
}
