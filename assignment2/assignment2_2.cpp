#include <iostream>
#include <cstring>
using namespace std;




const int NUM_OF_STUDENTS = 10;

struct StudentData {
    string StudentName;
    double StudentActiveness;
    bool WorkIsDone;
    double ExamPoints;
    unsigned CoursePassed: 1;
    int CourseGrade: 10;
};


int main(void){

StudentData *data[NUM_OF_STUDENTS];


for(int i=0;i<NUM_OF_STUDENTS;i++){                                         //get the stuff
    data[i] = new StudentData;


    cout << endl;

    cout << i << ". " <<"Student name: ";
    cin >> data[i]->StudentName;

    cout << i << ". " <<"Student activeness: ";
    cin >> data[i]->StudentActiveness;
    
    cout << i << ". " <<"Exam points: ";
    cin >> data[i]->ExamPoints;
    
    cout << i << ". " <<"Is the work done (0/1): ";
    cin >> data[i]->WorkIsDone;

    if((data[i]->ExamPoints > 0.40) && (data[i]->WorkIsDone == true)){
        data[i]->CoursePassed = true;
    }
    else{
        data[i]->CoursePassed = false;
    }
    

}



for(int i=0; i<NUM_OF_STUDENTS;i++){                                        //print the stuff           
    cout << endl << endl;                    
    if(data[i]->CoursePassed==false){
        cout << data[i]->StudentName << " failed" << endl;
    }
    else if(data[i]->CoursePassed==true){
         cout << data[i]->StudentName <<  " passed" << endl;
    }

    data[i]->CourseGrade = (data[i]->ExamPoints/0.12);

    if (data[i]->StudentActiveness>0.5){
        data[i]->CourseGrade += 1;
    }

    cout << "Grade is " << data[i]->CourseGrade << endl << endl;

}



return 0;
}


