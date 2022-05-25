#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <cstdio>
#include <iostream>
#include <random>
#include <vector>

#define LENGTH 50

using namespace std;

class Laser {
public:
	float x, y;
	Laser(float x = 0, float y = 0) { this->x = x; this->y = y; }
};

int laserCnt = 0, laserIndex = 0, cnt = 0;
float index = 0.5;

Laser laser[100];

int randomNum() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, LENGTH - 1);
	return dis(gen);
}

void laserShape() {
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(3.0, 1.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glEnd();
}

void drawLaser(float x, float y) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	laserShape();
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < laserCnt; i++) {
		drawLaser(laser[i].x, laser[i].y);
	}
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, LENGTH, 0, LENGTH, 0, LENGTH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {

}

void MySpecial(int key, int X, int Y) {

}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

}

void MyMouseMove(GLint X, GLint Y) {

}

void Myidle() {

}

void MyTimer(int Value) {
	for (int i = 0; i < laserCnt; i++) {
		laser[i].x += index;
	}
	glutPostRedisplay();
	glutTimerFunc(40, MyTimer, 1);
}

void MyTimer2(int Value) {
	laser[laserIndex].y = randomNum();
	laserCnt++;
	laserIndex = laserCnt;
	glutPostRedisplay();
	glutTimerFunc(50, MyTimer2, 1);
}

void MenuProc(int entryID) {

}

void MenuFunc() {

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500); //윈도우 창 크기(전역좌표)
	glutInitWindowPosition(0, 0); //윈도우 창 시작 위치(화면좌표)
	glutCreateWindow("제목");
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glutDisplayFunc(MyDisplay); //등록시 바로 호출
	glutReshapeFunc(MyReshape); //Reshape : 화면 균형 유지, 등록시 바로 호출, 창 크기 변경시 호출
	//glutKeyboardFunc(MyKeyboard); //Keyboard : 키보드
	//glutSpecialFunc(MySpecial); //Special : 특수키
	//glutMouseFunc(MyMouseClick); //Mouse : 마우스
	//glutMotionFunc(MyMouseMove); //Motion : 마우스 이동
	//glutIdleFunc(Myidle); //Idle : 애니매이션
	glutTimerFunc(0, MyTimer, 1);
	glutTimerFunc(0, MyTimer2, 1);
	//MenuFunc(); //Menu : 메뉴

	glutMainLoop();
	return 0;
}
