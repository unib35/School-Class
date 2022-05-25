#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int headX = 10, headY = 10, siz = 1, mode = 0, indexX = 0, indexY = 0, wormSiz = 0, feedX = 10, feedY = 10, speed;

vector<int> positionX;
vector<int> positionY;

class worm {
public: //지렁이 객체 선언부
	void drawHead(int x, int y);
	void headShape();
	void drawBody(int x, int y);
	void bodyShape();
};

class feed {
	float R, G, B; //먹이 색깔
public:
	void feedShape();
	void drawFeed(int x, int y);
};

worm x; feed f;


void worm :: bodyShape() {	//지렁이 몸통 조각 모양
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(1.0);
}

void worm :: drawBody(int x, int y) {	//지렁이 기본 몸통 1조각 그리기 구현부
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	bodyShape();
	glPopMatrix();
}

void worm :: headShape() {	//지렁이 머리 모양
	glColor3f(0.0, 1.0, 1.0);
	glutSolidCube(1.0);
}

void worm :: drawHead(int x, int y) {	//지렁이 머리 그리기
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	headShape();
	glPopMatrix();
}

void feed :: feedShape() {	//먹이 모양
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCube(1.0);
}

void feed :: drawFeed(int x, int y) {	//먹이 그리기
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	f.feedShape();
	glPopMatrix();
}

void drawEnd() {	//종료화면 그리기
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
}

void gameEnd() {	//게임 초기화
	drawEnd();
	headX = 10; headY = 10; siz = 1; indexX = 0; indexY = 0; wormSiz = 0; feedX = 12; feedY = 10;
	positionX.clear();
	positionY.clear();
}

void gameStart() {	//지렁이 키우기 시작
	x.drawHead(headX, headY);
	if (!positionX.empty())	//지렁이 몸통이 있을때만 실행
		for (int i = 0; i < wormSiz; i++) {	//지렁이 크기만큼 몸통 그리기
			x.drawBody(positionX.at(i), positionY.at(i));
		}
	f.drawFeed(feedX, feedY);	//지렁이 몸통크기로 먹이 한조각 그리기
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (mode == 0) gameEnd();
	else gameStart();
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)500;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 20.0 * WidthFactor, 0.0, 20.0 * HeightFactor, -1.0, 1.0);
	//gluLookAt(20, 20, 20, 0, 0, 0, 0, 0, 0);
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
	cout << "err" << endl;
	switch (entryID)
	{
	case 3:
		exit(0); //게임 종료
		break;
	case 11:
		speed = 400;
		break;
	case 12:
		speed = 200;
		break;
	case 13:
		speed = 50;
		break;
	}
	mode = 1;
	glutTimerFunc(speed, MyTimer, 1);
}

void MenuFunc() {	//게임 옵션 메뉴
	GLint MySubMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Easy", 11);
	glutAddMenuEntry("Hard", 12);
	glutAddMenuEntry("Impossible", 13);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Game Start", MySubMenuID);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("제목");
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
