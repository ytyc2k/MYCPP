#include  <string>
#include  <iostream>
#include  <fstream> 
#include <vector>
using namespace std;
struct course
{
    string CourseName;
    int mark;
};
struct student
{
    string name;
    int number;
    string id;
    vector<course> ks;
};
vector<student> Class;
int main()
{
    struct student stu0;
    stu0.name="yang";
    stu0.number=3;
    stu0.id="A0001";
    stu0.ks.push_back({"English",98});
    {
        /* data */
    };
    
    Class.push_back(stu0);   
    cout << Class[0].ks[0].CourseName<<endl;

    Class[0].ks.push_back({"math",90});
    cout << Class[0].ks[1].CourseName<<endl;
    cout << Class[0].number<<endl;
    
    // {
    //     /* data */
    // };
//     int n = 0;
//     ifstream FF("a.txt", ios::in);
//     if(!FF.is_open())
//     {
//         cout << "Error: opening file fail" << endl;
//         exit(1);
//     }
//     while(!FF.eof() && n < 2)
//     {
//         FF >> stu[n].name >> stu[n].age >> stu[n].id >> stu[n].ks[0].CourseName >> stu[n].cj.mathmark >> stu[n].cj.phsicmark ;
//         Class.push_back(stu[n]);
//         n++;
//     }
 
//     //test
//     for (int i = 0; i < n; ++i)
//         cout << stu[i].name;
// //        cout << "name:" << stu[i].name << " age:" << stu[i].age << " id:" << stu[i].id  << stu[i].coursename[0] << stu[i].tt[0] << " math:" << stu[i].tt[1] << " physic:" << stu[i].tt[2] << endl;
         
//     FF.close();

    return 0;
}