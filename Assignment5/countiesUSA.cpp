/// May 28 2020
/// This program demonstrates how to draw a polygon and fill it in using OpenGL and GLUT

#include <windows.h>
#include <iostream> // needed for cin & cout
#include <fstream> // needed to read a file
#include <sstream> // needed for string stream
#include <vector> // needed for vectors

#include <GL/glut.h>

using namespace std;

struct point
{
    double x;
    double y;
};

vector <point> data;
double leftt=-1, rightt=1, bottom=-1, top=1;
char c;
ifstream InFile("countiesUSA.txt");//File
ifstream InFile2("countiesUSA.txt");

void display()
{
    glClearColor(1.0,1.0,1.0,1.0); // white background
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity (); // default identity matrix - not doing any transformations
    glOrtho(leftt, rightt, bottom, top,-1,1);// set the boundaries of the window

    if(c=='y') // fill the shape it
    {
        glColor3f(1.0,1.0,0.0); // fill colour is yellow - red + green - all colours are specified with R,G,B values
        glBegin(GL_POLYGON);// draw a polygon - start here

        for(unsigned i=0; i<data.size(); i++) // for each point that was input
        {
            glVertex2f(data.at(i).x,data.at(i).y);// define a vertex at each point
        }
        glEnd(); // end here
    }

    // show where the origin (0,0) is with a red dot
    glPointSize(3);
    glColor3f(1,0,0); //red centre
    glBegin(GL_POINTS);
    glVertex2f(0,0); // the origin
    glEnd();

    // draw the border in black
    glColor3f(0.0,0.0,0.0); // lines are black
    glBegin(GL_LINE_STRIP);// draw connected line segments - start here

    for(unsigned i=0; i<data.size(); i++) // for each point that was input
    {
        glVertex2f(data.at(i).x,data.at(i).y);// define a vertex at each point
    }
    glVertex2f(data.at(0).x,data.at(0).y); // back to the first point
    glEnd(); // end here

    glFlush(); // display the result by flushing the buffer to the screen
}
void init()
{
    if (!InFile.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(0);
    }
    int pointnum;
    int n;
    /// set the boundaries of the window
    InFile>>leftt>>rightt>>bottom>>top>>n;
    cout<<"left: ";
    cout<<leftt<<endl;
    cout<<"right: ";
    cout<<rightt<<endl;
    cout<<"bottom: ";
    cout<<bottom<<endl;
    cout<<"top: ";
    cout<<top<<endl;
    cout<<"How many shapes: ";
    cout<<n<<endl;
    data.resize(999999);
    string State;
    string County;
    string space;
    int point=0;
    while(!InFile.eof())
    {
        InFile >> County;
        getline(InFile,County);
        InFile >> State;
        InFile >> pointnum;
        for(int j=0; j<pointnum; j++)
        {
            InFile>>data.at(point).x>>data.at(point).y;
 //           cout<<"X: "<<data.at(point).x;
 //           cout<<"  Y: "<<data.at(point).y<<endl;
            point++;
        }
//        cout<<"-------------------------------------------------"<<endl;
//        cout << point;
    }

    cout<<"Colour it in? (y/n) ";
    cin>>c;
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    init();
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize( 600, 600 );
    glutCreateWindow( "Display a Polygon and its boundary" );
    glutDisplayFunc(display); // define the function that draws the window - display
    glutMainLoop();
    return 0;
}