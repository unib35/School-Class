#include <glut.h>
#include <glu.h>
#include <gl.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <random>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <Digitalv.h>

MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openCoinSound;
MCI_PLAY_PARMS playCoinSound;



#define BGM "..\\smp.wav"
#define EATING "..\\coin2.wav"

#define L 0
#define R 1
#define U 2
#define D 3

#define _C 1975.533


using namespace std;

int headX = 10, headY = 10, mode = 0, indexX = 0, indexY = 0, wormSiz = 0, feedX = 12, feedY = 10, speed, direction = R, score = 0;

GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lightPos[] = { 20, 0, -15, 1.0f };
GLfloat polished[] = { 1.5f };

void Light();

class Position {
	float x, y;
	int direction;
public:
	Position(float x, float y, int direction) { this->x = x; this->y = y; this->direction = direction; }
	float getX() { return x; }
	float getY() { return y; }
	int getDirection() { return direction; }
};

vector<Position> position;

void jointShape(GLUquadricObj* wormObj) {	//지렁이 관절 모양
	glColor3f(0.6, 0.6, 1.0);
	gluSphere(wormObj, 0.6, 50, 50);
}

void drawJoint(GLUquadricObj* wormObj, int x, int y, int dir) {	//지렁이 기본 몸통 1조각 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	jointShape(wormObj);
	glPopMatrix();
}

void bodyShape(GLUquadricObj* wormObj) {	//지렁이 몸통 조각 모양
	glColor3f(0.6, 0.6, 1.0);
	glScalef(1, 2, 1);
	gluSphere(wormObj, 0.5, 50, 50);
}

void drawBody(GLUquadricObj* wormObj, int x, int y, int dir) {	//지렁이 기본 몸통 1조각 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	switch (dir)
	{
	case L:
		glRotatef(-90, 0, 0, 1);
		break;
	case R:
		glRotatef(90, 0, 0, 1);
		break;
	case U:
		break;
	case D:
		glRotatef(180, 0, 0, 1);
		break;
	}
	bodyShape(wormObj);
	glPopMatrix();
}

void headShape(GLUquadricObj* wormObj) {	//지렁이 머리 모양
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);


	glColor3f(.6, 0.6, 1);	//대가리
	glScalef(1, 1.5, 1);
	gluSphere(wormObj, 0.5, 50, 50);

	glColor3f(0.0, 0.0, 0.0);	//눈깔
	glTranslatef(0.3, 0.3, -0.15);
	gluSphere(wormObj, 0.15, 50, 50);

	glTranslatef(-0.6, 0.0, 0.0);	//좌눈깔
	gluSphere(wormObj, 0.15, 50, 50);


}

void drawHead(GLUquadricObj* wormObj, int x, int y, int dir) {	//지렁이 머리 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);

	switch (dir)
	{
	case L:
		glRotatef(90, 0, 0, 1);
		break;
	case R:
		glRotatef(-90, 0, 0, 1);
		break;
	case U:
		break;
	case D:
		glRotatef(180, 0, 0, 1);
		break;
	}

	headShape(wormObj);
	glPopMatrix();
}

void feedShape() {	//먹이 모양
	glColor3f(1.0, 1.0, 0.6);
	glutSolidTorus(0.2, 0.3, 50, 50);

}

void drawFeed(int x, int y) {	//먹이 그리기
	glPushMatrix();
	glTranslatef(x, y, 0);
	feedShape();
	glPopMatrix();
}

void drawIsland() {	//지렁이 지나다니는 땅 그리기
	glColor3f(0.8, 0.6, 0.4);
	glPushMatrix();
	glTranslatef(10, 10, 25.5);
	glScalef(21, 21, 50);
	glutSolidCube(1);
	glPopMatrix();
}

void drawEnd() {	//종료화면
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
	drawHead(gluNewQuadric(), headX, headY, U);
	glTranslatef(2, 2, 0);
	drawHead(gluNewQuadric(), headX, headY, U);
	glTranslatef(-4, 0, 0);
	drawHead(gluNewQuadric(), headX, headY, U);
	glTranslatef(0, -4, 0);
	drawHead(gluNewQuadric(), headX, headY, U);
	glTranslatef(4, 0, 0);
	drawHead(gluNewQuadric(), headX, headY, U);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void gameEnd() {	//게임 초기화
	headX = 10; headY = 10; indexX = 0; indexY = 0; wormSiz = 0; feedX = 12; feedY = 10;
	direction = R; score = 0;
	position.clear();
	drawEnd();
}

void gameStart() {	//지렁이 키우기 시작
	GLUquadricObj* wormObj;
	wormObj = gluNewQuadric();
	gluQuadricNormals(wormObj, GLU_SMOOTH);
	glPushMatrix();
	glRotatef(30, 1, 0, 0);
	glTranslatef(-(headX - 10), -(headY - 10) + 2, 5);
	drawIsland();
	drawFeed(feedX, feedY);	//지렁이 몸통크기로 먹이 한조각 그리기
	drawHead(wormObj, headX, headY, direction);
	if (!position.empty())	//지렁이 몸통이 있을때만 실행
		for (int i = 0; i < wormSiz; i++) {	//지렁이 길이만큼 몸통 그리기
			if (i + 1 != wormSiz && position.at(i).getDirection() != position.at(i + 1).getDirection())
				drawJoint(wormObj, position.at(i).getX(), position.at(i).getY(), position.at(i).getDirection());
			else
				drawBody(wormObj, position.at(i).getX(), position.at(i).getY(), position.at(i).getDirection());
		}
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glShadeModel(GL_SMOOTH);
	if (mode == 0) gameEnd();
	else gameStart();
	glutSwapBuffers();
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
		direction = L;
		break;
	case GLUT_KEY_UP:
		indexY = 1.0;
		direction = U;
		break;
	case GLUT_KEY_DOWN:
		indexY = -1.0;
		direction = D;
		break;
	case GLUT_KEY_RIGHT:
		indexX = 1.0;
		direction = R;
		break;
	}
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	cout << "Button : " << Button << endl;
	cout << "State : " << State << endl;
	cout << "X : " << X << endl;
	cout << "Y : " << Y << endl;
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
		Beep(_C, 80);
		cout << score << endl;
		wormSiz += 2;
		feedX = randNum();
		feedY = randNum();

		if (!position.empty())
			for (int i = 0; i < wormSiz; i++)
				if (feedX == position.at(i).getX() && feedY == position.at(i).getY()) {
					feedX = randNum();
					feedY = randNum();
				}
		score += 10;
		speed -= 15;
	}
}

void savePosition() {	//지렁이가 지나간 위치들 저장
	Position* p = new Position(headX, headY, direction);
	position.emplace(position.begin(), *p);
	delete p;
}

void die() {	//지렁이 사망조건
	if (!position.empty())
		for (int i = 0; i < wormSiz; i++)
			if (headX == position.at(i).getX() && headY == position.at(i).getY()) { Beep(_C, 1000); mode = 0; }
	if (headX == 21 || headY == 21 || headX == -1 || headY == -1) { Beep(_C, 1000); mode = 0; }
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
		speed = 300;
		break;
	}
	mode = 1;
	glutTimerFunc(speed, MyTimer, 1);
}

void MenuFunc() {	//게임 옵션 메뉴
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("GameStart", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Light() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);

	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialfv(GL_FRONT, GL_SHININESS, polished);

	glClearColor(1.0, 1.0, 0.8, 1.0);
}

//배경음악 재생
void MusicPlay() {
	PlaySound(TEXT(BGM), 0, SND_ASYNC | SND_LOOP);
}


int dwID;

void playingBgm() {
	openBgm.lpstrElementName = TEXT(BGM);
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);
}

void playingCoinSound() {
	openCoinSound.lpstrElementName = TEXT(EATING);//파일 오픈
	openCoinSound.lpstrDeviceType = TEXT("mpegvideo");//mp3 형식   
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openCoinSound);//음악을 한 번 재생 
	dwID = openCoinSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openCoinSound);
	Sleep(1800); //효과음이 재생될 때까지 정지했다가
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
	//음원 재생 위치를 처음으로 초기화}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(950, 950);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("제목");
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	//glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouseClick);
	//glutMotionFunc(MyMouseMove);
	//glutIdleFunc(Myidle);
	MenuFunc();
	Light();
	MusicPlay();
	glutMainLoop();
	return 0;
}


