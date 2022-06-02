#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <random>

#define z 0

using namespace std;
int window_width = 640;
int window_height = 480;

const GLfloat red[] = { 0.8f, 0.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.2f, 1.0, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat move_y = 0.0;
GLfloat move_z = 0.0;
GLfloat const_att = 2.0;

int headX = 10, headY = 10, siz = 1, mode = 0, indexX = 0, indexY = 0, wormSiz = 0, feedX = 10, feedY = 10, speed;

vector<int> positionX;
vector<int> positionY;

void bodyShape() {	//지렁이 몸통 조각 모양
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(1);
}

void drawBody(int x, int y) {	//지렁이 기본 몸통 1조각 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	bodyShape();
	glPopMatrix();
}

void headShape() {	//지렁이 머리 모양
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(1);
}

void drawHead(int x, int y) {	//지렁이 머리 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, dull);
	headShape();
	glPopMatrix();
}

void feedShape() {	//먹이 모양
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCube(1);

}

void drawFeed(int x, int y) {	//먹이 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	feedShape();
	glPopMatrix();
}

void drawIsland() {	//지렁이 지나다니는 땅 그리기
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(10, 10, 0.5);
	glScalef(21, 21, 2);
	glutSolidCube(1);
	glPopMatrix();
}

void drawEnd() {	//종료화면
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
}

void gameEnd() {	//게임 초기화
	drawEnd();
	headX = 0.1; headY = 0.1; siz = 1; indexX = 0; indexY = 0; wormSiz = 0; feedX = 12; feedY = 10;
	positionX.clear();
	positionY.clear();
}

void gameStart() {	//지렁이 키우기 시작
	glPushMatrix();
	glRotatef(30, 1, 0, 0);
	glTranslatef(-(headX - 10), -(headY - 10) + 2, 5);
	drawIsland();
	drawHead(headX, headY);
	if (!positionX.empty())	//지렁이 몸통이 있을때만 실행
		for (int i = 0; i < wormSiz; i++) {	//지렁이 길이만큼 몸통 그리기
			drawBody(positionX.at(i), positionY.at(i));
		}
	drawFeed(feedX, feedY);	//지렁이 몸통크기로 먹이 한조각 그리기
	glPopMatrix();
}

void Sun() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glPushMatrix();
	glTranslatef(0.0, headX, headY);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glDisable(GL_LIGHTING);
	glColor3d(0.0, 0.0, 0.5);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSwapBuffers();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Sun();
	if (mode == 0) gameEnd();
	else gameStart();
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)NewWidth / (float)NewHeight, 0.1, 20);
	glOrtho(0.0, 20.0, 0.0, 20.0, 0, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {

}

void MySpecial(int key, int X, int Y) {	//키 누를때마다 X, Y 기존 진행 방향 초기화 및 지렁이 방향 설정
	indexX = 0.0;
	indexY = 0.0;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		indexX = -1.0;
		break;
	case GLUT_KEY_UP:
		indexY = 1.0;
		break;
	case GLUT_KEY_DOWN:
		indexY = -1.0;
		break;
	case GLUT_KEY_RIGHT:
		indexX = 1.0;
		break;
	}
}

void MyInit() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, black);
	glLightfv(GL_LIGHT0, GL_SPECULAR, black);

	glEnable(GL_DEPTH_TEST);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

}

void MyMouseMove(GLint X, GLint Y) {

}

void Myidle() {
}

int randNum() {	//1~19 랜덤값 생성
	random_device rd;	//랜덤 디바이스 생성
	mt19937 gen(rd());	//랜덤 엔진 초기화
	uniform_int_distribution<int> dis(1, 19);	//랜덤 수 범위 지정
	return dis(gen);
}

void feeding() {	//지렁이 먹이 생성
	if (headX == feedX && headY == feedY) {
		wormSiz++;
		feedX = randNum();
		feedY = randNum();
	}
}

void savePosition() {	//지렁이가 지나간 위치들 저장
	positionX.emplace(positionX.begin(), headX);
	positionY.emplace(positionY.begin(), headY);
}

void die() {	//지렁이 사망조건
	for (int i = 0; i < wormSiz; i++)
		if (headX == positionX.at(i) && headY == positionY.at(i)) mode = 0;
	if (headX == 20 || headY == 20 || headX == -1 || headY == -1) mode = 0;
}

void MyTimer(int Value) {
	savePosition();	//지렁이가 지나온 위치 기억

	headX += indexX;
	headY += indexY;

	feeding();	//먹이 생성
	die();	//지렁이 사망조건

	glutPostRedisplay();
	if (mode == 1) glutTimerFunc(speed, MyTimer, 1);
}

void MenuProc(int entryID) {

}
void MyMainMenu(int entryID) {	//게임 속도 설정
	switch (entryID)
	{
	case 1:
		speed = 500;
		break;
	case 2:
		speed = 125;
		break;
	case 3:
		speed = 50;
		break;
	}
	mode = 1;
	glutTimerFunc(speed, MyTimer, 1);
}

void MenuFunc() {	//게임 옵션 메뉴
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("EASY", 1);
	glutAddMenuEntry("HARD", 2);
	glutAddMenuEntry("IMPOSSIBLE", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("제목");
	MyInit();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	//glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	//glutMouseFunc(MyMouseClick);
	//glutMotionFunc(MyMouseMove);
	//glutIdleFunc(Myidle);
	MenuFunc();
	glutMainLoop();
	return 0;
}
