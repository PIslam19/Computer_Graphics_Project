#include<cstdio>  ///Final Project ///Last Attempt
#include<GL/gl.h>
#include <GL/glut.h>
#include<Windows.h>
#define PI          3.141516
#include<math.h>
using namespace std;
float moveca=0.0f;
float movefir=0.0f;
float movefiy=0.0f;
float moveb=0.0f;
float movec1=0.0f;
float movec2=0.0f;
float speed = 0.0f;///Red car
float sr=133;///sky Color
float sg=204;
float sb=250;
float cr=255;///cloud Color
float cg=255;
float cb=255;
float str=133;///star Color
float stg=204;
float stb=250;
float mr=255;///moon and sun
float mg=255;
float mb=0;
float la=71;///car light red
float lb=72;
float lc=76;
float wr=75;///water color
float wg=182;
float wb=239;
float rr=71;///road color
float rg=72;
float rb=76;
float lr=128,lg=128,llb=128;///color of light
float gr=27,gg=142,gb=45; ///Island color
float angle1 = 0.0f;///Red car
int dcheck=0;

///DISPLAY START.......................................................................................................................................
void display()
{
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ///SKY START........................................................................................................................
    glBegin(GL_POLYGON);
    glColor3ub(sr, sg, sb);  ///Default(15,169,252)

    glVertex2f(1.00f,  0.09f);
    glVertex2f(1.00f, 1.00f);
    glVertex2f(-1.00f,1.00f);
    glVertex2f(-1.00f, 0.09f);
    glEnd();
///SKY FINISH........................................................................................................................


///STAR START........................................................................................................................
    glPointSize(3.0);
    glColor3ub(str,stg,stb);

    glBegin(GL_POINTS);
    glVertex2f(0.33,0.65);
    glVertex2f(-0.33,0.7);
    glVertex2f(-0.43,0.8);
    glVertex2f(0.6,0.88);
    glVertex2f(0.67,0.68);
    glVertex2f(-0.53,0.8);
    glVertex2f(-.41,0.65);
    glVertex2f(-0.19,0.78);
    glVertex2f(0.07,0.9);
    glVertex2f(0.23,0.96);
    glVertex2f(0.27,1.05);
    glVertex2f(0.13,1.1);
    glVertex2f(-0.75,0.75);
    glVertex2f(-0.56,0.90);
    glEnd();
///STAR FINISH........................................................................................................................

///SUN START..........................................................................................................................
    glPushMatrix();
    glTranslatef(0.787, 0.87, 0.0);
    glColor3ub(mr, mg, mb);  ///Default(252, 229, 112);
    glutSolidSphere(0.08, 50, 50);
    glPopMatrix();
    glEnd();
///SUN FINISH..........................................................................................................................


///ROAD START........................................................................................................................
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(rr, rg, rb);
    glVertex2f(1.00f, 0.05f);
    glVertex2f(1.00f, -0.30f);
    glVertex2f(-1.00f, -0.30f);
    glVertex2f(-1.00f, 0.05f);
    glEnd();
    glPopMatrix();

    ///ROAD WHITE STRIPS

    glPushMatrix();
    glColor3ub(255,255,255);

    for(float i=-1; i<1; i+=0.06)
    {
        glBegin(GL_POLYGON);
        glVertex2f(i, -0.12f);
        glVertex2f(i, -0.10f);
        glVertex2f(i+0.04f, -0.10f);
        glVertex2f(i+0.04f,-0.12f);
        glEnd();
    }
    glPopMatrix();

    ///Road 2 start..........................................
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(rr, rg, rb);
    glVertex2f( 0.0f,1.00f);
    glVertex2f(-0.22f,1.00f );
    glVertex2f( -0.22f,0.0f);
    glVertex2f( 0.0f,0.0f);
    glEnd();
    glPopMatrix();

    ///ROAD WHITE STRIPS

    glPushMatrix();
    glColor3ub(255,255,255);

    for(float i=-0.119; i<1; i+=0.12)
    {
        glBegin(GL_POLYGON);
        glVertex2f(-0.115f,i );
        glVertex2f( -0.105f,i);
        glVertex2f( -0.105f,i+0.08f);
        glVertex2f(-0.115f,i+0.08f);
        glEnd();
    }
    glPopMatrix();
    ///ROad 2 end............................................

    ///Upper part of the Road border green border // LEFT SIDE
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex2f(-.20f,0.05f);
    glVertex2f(-.20f,1.0f);
    glVertex2f(-.22,1.0f);
    glVertex2f(-.22,0.05f);
    glEnd();
    ///Upper part of the Road border green border // RIGHT SIDE
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex2f(0.0001f,0.05f);
    glVertex2f(0.0001f,1.0f);
    glVertex2f(0.02,1.0f);
    glVertex2f(0.02,0.05f);
    glEnd();
///ROAD FINISH............................................................................................................................................

///SECOND QUATENT ISLAND SCENE START.......................................................................................................................

    glBegin(GL_POLYGON);///ISLAND GROUND PART
    glColor3ub(gr,gg,gb);
    glVertex2f(-0.9,0.4);
    glVertex2f(-0.7,0.6);
    glVertex2f(-0.5,0.4);
    glVertex2f(-0.5,0.6);
    glVertex2f(-0.3,0.6);
    glVertex2f(-0.25,0.4);
    glEnd();

    glBegin(GL_POLYGON);///ISLAND GROUND PART
    glColor3ub(gr,gg,gb);
    glVertex2f(0.9,0.4);
    glVertex2f(0.7,0.6);
    glVertex2f(0.5,0.4);
    glVertex2f(0.5,0.6);
    glVertex2f(0.3,0.6);
    glVertex2f(0.25,0.4);
    glEnd();

    glBegin(GL_POLYGON);///ISLAND LOWER PART
    glColor3ub(wr,wg,wb);
    glVertex2f(-1.0,0.4);
    glVertex2f(-0.22,0.4);
    glVertex2f(-0.22,0.09);
    glVertex2f(-1.0,0.09);
    glEnd();

    glBegin(GL_POLYGON);/// side lake
    glColor3ub(wr,wg,wb);
    glVertex2f(1.0,0.4);
    glVertex2f(0.02,0.4);
    glVertex2f(0.02,0.09);
    glVertex2f(1.0,0.09);
    glEnd();

///HOUSE 1 START
    glBegin(GL_QUADS); ///House lower part
    glColor3ub(0,66,62);
    glVertex2f(-0.65,0.47);
    glVertex2f(-0.6,0.47);
    glVertex2f(-0.6,0.55);
    glVertex2f(-0.65,0.55);
    glEnd();

    glBegin(GL_QUADS); ///House window
    glColor3ub(255,255,255);
    glVertex2f(-0.62,0.5);
    glVertex2f(-0.61,0.5);
    glVertex2f(-0.61,0.52);
    glVertex2f(-0.62,0.52);
    glEnd();

    glBegin(GL_TRIANGLES); ///House top part
    glColor3ub(255,255,0);
    glVertex2f(-0.59,0.55);
    glVertex2f(-0.66,0.55);
    glVertex2f(-0.625,0.6);
    glEnd();
///HOUSE 1 FINISH....................................

///HOUSE 2 START
    glBegin(GL_QUADS); ///House lower part
    glColor3ub(0,66,62);
    glVertex2f(-0.55,0.47);
    glVertex2f(-0.5,0.47);
    glVertex2f(-0.5,0.55);
    glVertex2f(-0.55,0.55);
    glEnd();

    glBegin(GL_QUADS); ///House window
    glColor3ub(255,255,255);
    glVertex2f(-0.52,0.5);
    glVertex2f(-0.51,0.5);
    glVertex2f(-0.51,0.52);
    glVertex2f(-0.52,0.52);
    glEnd();

    glBegin(GL_TRIANGLES); ///House top part
    glColor3ub(255,255,0);
    glVertex2f(-0.49,0.55);
    glVertex2f(-0.56,0.55);
    glVertex2f(-0.525,0.6);
    glEnd();
///HOUSE 2 FINISH....................................
///HOUSE 3 START
    glBegin(GL_QUADS); ///House lower part
    glColor3ub(200,0,0);
    glVertex2f(-0.45,0.52);
    glVertex2f(-0.4,0.52);
    glVertex2f(-0.4,0.60);
    glVertex2f(-0.45,0.60);
    glEnd();

    glBegin(GL_QUADS); ///House window
    glColor3ub(255,255,255);
    glVertex2f(-0.42,0.55);
    glVertex2f(-0.41,0.55);
    glVertex2f(-0.41,0.57);
    glVertex2f(-0.42,0.57);
    glEnd();

    glBegin(GL_TRIANGLES); ///House top part
    glColor3ub(0,210,0);
    glVertex2f(-0.39,0.6);
    glVertex2f(-0.46,0.6);
    glVertex2f(-0.425,0.65);
    glEnd();
///HOUSE 3 FINISH....................................

///Trees start

    ///tree 1 Start
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(98,78,44);

    glVertex2f(-0.585,0.47);
    glVertex2f(-0.565,0.47);
    glVertex2f(-0.565,0.62);
    glVertex2f(-0.585,0.62);
    glEnd();
    glPopMatrix();
    ///tree up

    glBegin(GL_TRIANGLES); ///tree top part
    glColor3ub(0,255,0);
    glVertex2f(-0.53,0.62);
    glVertex2f(-0.62,0.62);
    glVertex2f(-0.56,0.7);
    glEnd();
    ///Tree 1 end
    ///tree 2 Start
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(98,78,44);

    glVertex2f(-0.485,0.47);
    glVertex2f(-0.465,0.47);
    glVertex2f(-0.465,0.62);
    glVertex2f(-0.485,0.62);
    glEnd();
    glPopMatrix();
    ///tree up

    glBegin(GL_TRIANGLES); ///tree top part
    glColor3ub(0,255,0);
    glVertex2f(-0.43,0.62);
    glVertex2f(-0.52,0.62);
    glVertex2f(-0.46,0.7);
    glEnd();
    ///Tree 2 end

    glBegin(GL_POLYGON);///ISLAND LOWER PART 1st quad
    glColor3ub(wr,wg,wb);
    glVertex2f(-1.0,0.4);
    glVertex2f(-0.22,0.4);
    glVertex2f(-0.22,0.09);
    glVertex2f(-1.0,0.09);
    glEnd();
    ///Trees start

    ///tree 1 Start
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(98,78,44);

    glVertex2f(0.585,0.47);
    glVertex2f(0.565,0.47);
    glVertex2f(0.565,0.62);
    glVertex2f(0.585,0.62);
    glEnd();
    glPopMatrix();
    ///tree up

    glBegin(GL_TRIANGLES); ///tree top part
    glColor3ub(0,255,0);
    glVertex2f(0.53,0.62);
    glVertex2f(0.62,0.62);
    glVertex2f(0.56,0.7);
    glEnd();
    ///Tree 1 end
    ///tree 2 Start
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(98,78,44);

    glVertex2f(0.485,0.47);
    glVertex2f(0.465,0.47);
    glVertex2f(0.465,0.62);
    glVertex2f(0.485,0.62);
    glEnd();
    glPopMatrix();
    ///tree up

    glBegin(GL_TRIANGLES); ///tree top part
    glColor3ub(0,255,0);
    glVertex2f(0.43,0.62);
    glVertex2f(0.52,0.62);
    glVertex2f(0.46,0.7);
    glEnd();
    ///Tree 2 end

///CLOUD 1 START..........................
    glPushMatrix();
    glTranslatef(movec1+0.2, 0.8, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
    glEnd();
    glPushMatrix();
    glTranslatef(movec1+0.28, 0.8, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.04, 50, 50);
    glPopMatrix();
    glEnd();
    glPushMatrix();
    glTranslatef(movec1+0.35, 0.8, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.04, 50, 50);
    glPopMatrix();
    glEnd();
///CLOUD 1 FINISH.........................

///CLOUD 2 START..........................
    glPushMatrix();
    glTranslatef(movec2-0.6, 0.85, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
    glEnd();
    glPushMatrix();
    glTranslatef(movec2-0.65, 0.85, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.04, 50, 50);
    glPopMatrix();
    glEnd();
    glPushMatrix();
    glTranslatef(movec2-.55, 0.85, 0.0);
    glColor3ub(cr,cg,cb);
    glutSolidSphere(0.04, 50, 50);
    glPopMatrix();
    glEnd();
///CLOUD 2 FINISH.........................




///SECOND QUATENT ISLAND SCENE FINISH.......................................................................................................................

/// LightHouse ////start
    glBegin(GL_POLYGON);
    glColor3ub(102, 101, 97);
    glVertex2f(0.04,0.14);
    glVertex2f(0.20,0.14);
    glVertex2f(0.18,0.60);
    glVertex2f(0.06,0.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(lr,lg,llb);
    glVertex2f(0.18,0.60);
    glVertex2f(0.06,0.6);
    glVertex2f(0.06,0.8);
    glVertex2f(0.18,0.80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(80, 87, 99);
    glVertex2f(0.04,0.8);
    glVertex2f(0.20,0.80);
    glVertex2f(0.12,0.90);
    glEnd();
/// LightHouse ////end



///LACK START........................................................................................................................
    glBegin(GL_QUADS);
    glColor3ub(wr,wg,wb);
    glVertex2f(1.00f,  -0.35);
    glVertex2f(1.00f, -1.0f);
    glVertex2f(-1.00f, -1.00f);
    glVertex2f(-1.00f, -0.35f);
    glEnd();
///LACK FINISH........................................................................................................................



///CAR START........................................................................................................................
///CAR 1
    glPushMatrix();
    glTranslatef(moveca, +0.20f,0.0f );
    glPushMatrix();
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3ub(la,lb,lc);
    glVertex2f(-0.72f, -0.35f);
    glVertex2f(-0.72f, -0.36f);
    glVertex2f(-0.64f, -0.40f);
    glVertex2f(-0.64f, -0.33f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(26,153,128);
    glVertex2f(-1.00f, -0.40f);
    glVertex2f(-0.99f, -0.34f);
    glVertex2f(-0.71f, -0.34f);
    glVertex2f(-0.70f, -0.40f);
    glEnd();
    glBegin(GL_POLYGON);
    ///UBody///
    glColor3ub(26,153,128);
    glVertex2f(-0.92f, -0.34f);
    glVertex2f(-0.880f, -0.29f);
    glVertex2f(-0.820f, -0.29f);
    glVertex2f(-0.78f, -0.34f);
    glEnd();
    ///BWin///
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.915f, -0.34f);
    glVertex2f(-0.875f, -0.295f);
    glVertex2f(-0.852f, -0.295f);
    glVertex2f(-0.852f, -0.34f);
    glEnd();
    ///MidLine///
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.851f, -0.34f);
    glVertex2f(-0.851f, -0.295f);
    glVertex2f(-0.848f, -0.295f);
    glVertex2f(-0.848f, -0.34f);
    glEnd();
    ///FWin///
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.785f, -0.34f);
    glVertex2f(-0.825f, -0.295f);
    glVertex2f(-0.847f, -0.295f);
    glVertex2f(-0.847f, -0.34f);
    glEnd();
    glPopMatrix();
    ///BWheal///
    glPushMatrix();
    glColor3ub(0.0,0,0);
    glTranslatef (-0.95, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
    glColor3ub(0.0,0,0);
    glTranslatef (-0.75, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();

///car2_Finish

/// CAR 2 START


///CarT1Uplane
    glPushMatrix();
    glTranslatef(angle1, 0.35f,0.0f );

    glPushMatrix();
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3ub(la,lb,lc);
    glVertex2f(-0.99f, -0.35f);
    glVertex2f(-0.99f, -0.36f);
    glVertex2f(-1.1f, -0.40f);
    glVertex2f(-1.1f, -0.33f);
    glEnd();
    ///LBody///
    glBegin(GL_POLYGON);
    glColor3ub(255,0.0,0.0);
    glVertex2f(-1.00f, -0.40f);
    glVertex2f(-0.99f, -0.34f);
    glVertex2f(-0.71f, -0.34f);
    glVertex2f(-0.70f, -0.40f);
    glEnd();
    glBegin(GL_POLYGON);
    ///UBody///
    glColor3ub(255,0.0,0.0);
    glVertex2f(-0.92f, -0.34f);
    glVertex2f(-0.88f, -0.29f);
    glVertex2f(-0.82f, -0.29f);
    glVertex2f(-0.78f, -0.34f);
    glEnd();
    ///BWin///
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.915f, -0.34f);
    glVertex2f(-0.875f, -0.295f);
    glVertex2f(-0.852f, -0.295f);
    glVertex2f(-0.852f, -0.34f);
    glEnd();
    ///MidLine///
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.851f, -0.34f);
    glVertex2f(-0.851f, -0.295f);
    glVertex2f(-0.848f, -0.295f);
    glVertex2f(-0.848f, -0.34f);
    glEnd();
    ///FWin///
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.785f, -0.34f);
    glVertex2f(-0.825f, -0.295f);
    glVertex2f(-0.847f, -0.295f);
    glVertex2f(-0.847f, -0.34f);
    glEnd();
    glPopMatrix();
    ///BWheal///
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef (-0.95, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef (-0.75, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();

/// CAR 2 START.........

///MiniBus_start
    glPushMatrix();
    glTranslatef(moveca, 0.21f,0.0f );

    ///LBody///
    glBegin(GL_POLYGON);
    glColor3ub(la,lb,lc);
    glVertex2f(0.59f, -0.35f);
    glVertex2f(0.59f, -0.36f);
    glVertex2f(0.7f, -0.40f);
    glVertex2f(0.7f, -0.34f);
    glEnd();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex2f(.3f, -0.40f);
    glVertex2f(.3f, -0.34f);
    glVertex2f(0.59f, -0.34f);
    glVertex2f(0.6f, -0.40f);
    glEnd();
    glBegin(GL_POLYGON);
    ///UBody///
    glColor3ub(255,0,0);
    glVertex2f(.3f, -0.34f);
    glVertex2f(.3f, -0.29f);
    glVertex2f(.505f, -0.29f);
    glVertex2f(.545f, -0.34f);
    glEnd();

    ///MidLine///
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(.47f, -0.34f);
    glVertex2f(.47f, -0.295f);
    glVertex2f(.48f, -0.295f);
    glVertex2f(.48f, -0.34f);
    glEnd();
    ///FWin///
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(.54f, -0.34f);
    glVertex2f(.5f, -0.295f);
    glVertex2f(.48f, -0.295f);
    glVertex2f(.48f, -0.34f);
    glEnd();
    glPopMatrix();
    ///BWheal///
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef (0.35f, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    ///FWheal///
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef (0.55f, -0.40f, 0.0f);
    glutSolidSphere(0.025, 50, 50);
    glPopMatrix();
    glPopMatrix();
///MiniBus_Finish

///CAR FINISH................................................................................................

///BOAT GHAT ::  START ............................................................
    glBegin(GL_POLYGON);
    glColor3ub(123, 96, 128);
    glVertex2f(-0.4f,-0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.5f, -0.35f);
    glVertex2f(-0.5f, -0.35f);
    glEnd();

///BOAT GHAT :: FINISH............................................................

///BOAT GHAT for village ::  START ............................................................
    glBegin(GL_POLYGON);
    glColor3ub(123, 96, 128);
    glVertex2f(-0.790f,0.40f);
    glVertex2f(-0.4f, 0.40f);
    glVertex2f(-0.5f, 0.33f);
    glVertex2f(-0.7f, 0.33f);
    glEnd();

///BOAT GHAT :: FINISH............................................................

///BOAT START........................................................................................................................
    ///Boat 1 Start
    glPushMatrix();
    glTranslatef(moveb, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2f(-0.53f, -0.76f);
    glVertex2f(-0.33f, -0.76f);
    glVertex2f(-0.25f, -0.68f);
    glVertex2f(-0.61f, -0.68f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(-0.53f, -0.68f);
    glVertex2f(-0.33f, -0.68f);
    glVertex2f(-0.33f, -0.65f);
    glVertex2f(-0.53f, -0.65f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,77);
    glVertex2f(-0.5f, -0.65f);
    glVertex2f(-0.36f, -0.65f);
    glVertex2f(-0.36f, -0.62f);
    glVertex2f(-0.5f, -0.62f);
    glEnd();
    glPopMatrix();
    ///Boat 1 FINISH....................

    ///Boat 2 START..........................
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64); ///boat lower part
    glVertex2f(-0.6f, -0.54f);
    glVertex2f(-0.4f, -0.54f);
    glVertex2f(-0.32f, -0.46f);
    glVertex2f(-0.68f, -0.46f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(-0.63f, -0.46f);
    glVertex2f(-0.43f, -0.46f);
    glVertex2f(-0.43f, -0.43f);
    glVertex2f(-0.63f, -0.43f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(186, 43, 146); //red
    glVertex2f(-0.6f, -0.43f);
    glVertex2f(-0.46f, -0.43f);
    glVertex2f(-0.46f, -0.40f);
    glVertex2f(-0.6f, -0.40f);
    glEnd();

    ///Boat 2 FINISH..........................

    ///Boat 3 START..........................
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64); //boat lower part
    glVertex2f(0.45f, -0.59f);
    glVertex2f(0.65f, -0.59f);
    glVertex2f(0.73f, -0.51f);
    glVertex2f(0.38f, -0.51f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(0.45f, -0.51f);
    glVertex2f(0.65f, -0.51f);
    glVertex2f(0.65f, -0.48f);
    glVertex2f(0.45f, -0.48f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(118, 184, 18); //red
    glVertex2f(0.48f, -0.48f);
    glVertex2f(0.62f, -0.48f);
    glVertex2f(0.62f, -0.45f);
    glVertex2f(0.48f, -0.45f);
    glEnd();

    ///Boat 3 FINISH..........................

    ///Boat 4 START -- UPPER in SECOND QUANTANT.................
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64); //lower part of boat 3
    glVertex2f(-0.53f, 0.1f);
    glVertex2f(-0.33f, 0.1f);
    glVertex2f(-0.25f, 0.18f);
    glVertex2f(-0.61f, 0.18f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(-0.53f, 0.18f);
    glVertex2f(-0.33f, 0.18f);
    glVertex2f(-0.33f, 0.21f);
    glVertex2f(-0.53f, 0.21f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,77);
    glVertex2f(-0.5f, 0.21f);
    glVertex2f(-0.36f,0.21f);
    glVertex2f(-0.36f, 0.24f);
    glVertex2f(-0.5f, 0.24f);
    glEnd();

    ///Boat 4 FINISH.............................................

    ///Small Boat 1 :: START :: upper second QUANTANT....................
    glBegin(GL_POLYGON);
    glColor3ub(64,64,64);
    glVertex2f(-0.5,0.35);
    glVertex2f(-0.35,0.35);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.45,0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(-0.4, 0.35);
    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.45f, 0.38f);
    glVertex2f(-0.4f, 0.38f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(173, 36, 173);
    glVertex2f(-0.44f, 0.38f);
    glVertex2f(-0.41f,0.38f);
    glVertex2f(-0.41f, 0.40f);
    glVertex2f(-0.44f, 0.40f);
    glEnd();
    ///Small Boat 1:: FINISH :: upper second QUANTANT....................

    ///Small Boat 2 :: START :: upper second QUANTANT....................
    glBegin(GL_POLYGON);
    glColor3ub(64,64,64);
    glVertex2f(-0.9,0.35);
    glVertex2f(-0.75,0.35);
    glVertex2f(-0.8,0.3);
    glVertex2f(-0.85,0.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(45, 250, 79);
    glVertex2f(-0.8, 0.35);
    glVertex2f(-0.85f, 0.35f);
    glVertex2f(-0.85f, 0.38f);
    glVertex2f(-0.8f, 0.38f);
    glEnd();


    ///Small Boat 2 :: FINISH :: upper second QUANTANT....................

///BOAT FINISH........................................................................................................................


///FISH START..............................................................................................................................................
    glPushMatrix();
    glTranslatef(movefiy, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 175, 175);
    glVertex2f(0.75f, -0.66f);
    glVertex2f(0.75f, -0.583f);
    glVertex2f(0.85f, -0.63f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 72, 72);//ruih fish
    glVertex2f(0.75f, -0.66f);
    glVertex2f(0.75f, -0.583f);
    glVertex2f(0.70f, -0.63f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 72, 72);
    glVertex2f(0.83f, -0.63f);
    glVertex2f(0.9f,-0.66f);
    glVertex2f(0.9f,-0.583f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 72, 72);
    glVertex2f(0.76f,-0.65f);
    glVertex2f(0.79f,-0.64f);
    glVertex2f(0.80f,-0.68f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 72, 72); //yellow
    glVertex2f(0.76f,-0.59f);
    glVertex2f(0.79f,-0.61f);
    glVertex2f(0.80f,-0.55f);
    glEnd();

    glColor3ub(0,0,0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(0.73f, -0.62f);
    glEnd();
    glPopMatrix();
///Fish1_finish ///


///FISH 2 START :: ///

    glPushMatrix();
    glTranslatef(movefir, 0.00f,0.0f ); ///xMove


    glBegin(GL_TRIANGLES);
    glColor3ub(157, 161, 158);
    glVertex2f(-0.77, -0.85);
    glVertex2f(-0.75, -0.89);
    glVertex2f(-0.77, -0.91);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(movefir, 0.00f,0.0f ); ///xMov


    glBegin(GL_POLYGON);
    glColor3ub(157, 161, 158); /// fish
    glVertex2f(-0.7, -0.93);
    glVertex2f(-0.75, -0.89);
    glVertex2f(-0.85,-0.93);
    glVertex2f(-0.75, -0.96);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(movefir, 0.0f,0.0f ); ///xMove
    glBegin(GL_POLYGON);
    glColor3ub(157, 161, 158);
    glVertex2f(-0.83, -0.93);
    glColor3ub(0.412, 0.412, 0.412);
    glVertex2f(-0.90, -0.97);
    glVertex2f(-0.87, -0.93);
    glVertex2f(-0.90, -0.89);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(movefir, 0.0f,0.0f ); ///xMove


    glBegin(GL_TRIANGLES);
    glColor3ub(15, 18, 16);
    glVertex2f(-0.75, -0.96);
    glVertex2f(-0.77, -0.955);
    glVertex2f(-0.763, -0.999);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(movefir, 0.0f,0.0f ); ///xMove

    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(-0.73, -0.93);
    glEnd();
    glPopMatrix();
///Fish2_finish Yellow and Red///
///FISH FINISH.........................................................................................................................................

    glFlush(); //Render Now
}


///DISPLAY FINISH.......................................................................................................................................


///MOVE ELEMENT...........START............................
void update(int value)
{

    moveca+= .008; ///  car
    if(moveca-1.1 > 1.0)
    {
        moveca = -1.5;

    }


    movefir += .001;/// fish
    if(movefir-1.3  > 1.0)
    {
        movefir = -1.0;
    }


    movefiy -= .002;  ///yellow fish
    if(movefiy+1.3 < -1.0)
    {
        movefiy = 1.0;

    }

    moveb += .005;///boat
    if(moveb-1.663  > 1.0)
    {
        moveb = -1.0;
    }

    movec1 += .001;///cloud1
    if(movec1-0.39 > 1.0)
    {
        movec1 = -1.4;
    }

    movec2 += .002;///cloud2
    if(movec2-0.79 > 1.0)
    {
        movec2 = -2.0;
    }


    glutPostRedisplay(); ///Notify GLUT that the display has changed

    glutTimerFunc(20, update, 0); ///Notify GLUT to call update again in 20 milliseconds
}
void update1(int value)
{


    if(speed>1 || speed<0)
    {

        speed = 0.0f;
    }
    angle1 -= speed;

    if (angle1 < -0.31)
    {
        angle1 += 2.31;

    }

    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 20 milliseconds
}



///MOVE ELEMENT...........START............................


///MOURSE AND KEYBOARD CONTROL START............................................................................................................................
void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 's':/// Red car
        speed+=0.01f;

        break;
    case 'c':
        speed-=0.01f;

        break;
    case 'd':///Day and night check
        if(dcheck==0)
        {
            dcheck=1;
            sr=25;///sky
            sg=25;
            sb=25;
            str=255;///star
            stg=255;
            stb=255;
            mr=255;///moon
            mg=255;
            mb=255;
            la=255;///car light red
            lb=255;
            lc=255;
            cr=25;///cloud red
            cg=25;
            cb=25;
            wr=63;///night water
            wg=87;
            wb=99;
            rr=41;///night road
            rg=42;
            rb=46;
            gr=61;
            gg=84;
            gb=61;
            lr=255;
            lg=255;
            llb=255;


        }

        else
        {
            dcheck=0;
            sr=133;///sky red
            sg=204;
            sb=250;
            cr=255;///cloud
            cg=255;
            cb=255;
            str=133;///star red
            stg=204;
            stb=250;
            mr=255;///moon and sun
            mg=255;
            mb=0;
            la=71;///car light red
            lb=72;
            lc=76;
            wr=75;
            wg=182;
            wb=239;//75, 182, 239
            rr=71;///day road
            rg=72;
            rb=76;
            gr=27;
            gg=142;
            gb=45;///ground in day

            lr=128;
            lg=128;
            llb=128;


        }
        break;



    }

}
void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        movefir += 0.1f;
        {
            movefiy -= 0.1f;
        }
        if (button == GLUT_RIGHT_BUTTON)
        {
            moveb-= 0.5f;
        }
        glutPostRedisplay();
    }
}
///MOURSE AND KEYBOARD CONTROL FINISH............................................................................................................................

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1440, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mithamoin Haor :: ISLAM SARDAR");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(handleMouse);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(20, update1, 0);

    glutMainLoop();
    return 0;
}

