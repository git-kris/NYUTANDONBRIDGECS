/*
 NYU Tandon Bridge Grade Calculator with Distinction™
 
 Values based from:
 https://engineering.nyu.edu/sites/default/files/2018-10/CS-GY%206003%20Foundations%20of%20CS.pdf
 
 Letter Grade   = Number Grade
    A           =   93-100
    A-          =   90 92
    B+          =   87-89
    B           =   83-86
    B-          =   80-82
    C+          =   77-79
    C           =   73-76
    C-          =   70-72
    F           =   0-69
 
 Tandon Bridge Summer 2022 Grade
 Homework   = 8% of total grade
 Exam 1     = 23% of total grade
 Exam 2     = 23% of total grade
 Exam 3     = 23% of total grade
 Exam 4     = 23% of total grade
 
 by: Kristoffer Aquino
 email: email@kristofferaquino.com
 version 3.71 8/12/2022
 */

#include <iostream>
#include <string>
using namespace std;

const int A_MINIMUM = 93, A_MINUS_MINIMUM = 90, B_PLUS_MINIMUM = 87;
const int B_MINIMUM = 83, B_MINUS_MINIMUM = 80, C_PLUS_MINIMUM = 77, C_MINIMUM = 73, C_MINUS_MINIMUM = 70;
const int F_MINIMUM = 0;
const int HOMEWORK_WEIGHT = 8;// Percent times 100.
const int EXAM_WEIGHT = 23;// Percent time 100.
const int HOMEWORK_MAX_NUMBER = 20;
const int EXAM_MAX_NUMBER = 4;
const double VERSION_NUMBER = 3.71;


int main() {
    double homeworkScore = 0, homeworkPoints = 0, homeworkMaxPoints = 0, homeworkTotalScore = 0, overallHomeworkGrade = 0, homeworkNumber = 1;
    double finalGrade = 0, examScore = 0, examPoints = 0, examMaxPoints = 0, examTotalScore = 0, overallExamGrade = 0, examNumber = 1;
    string letterGrade = "";
    
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"Welcome to Kris' unofficial NYU Tandon Bridge Grade Calculator with Distinction™ ver "<<VERSION_NUMBER<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"-------------------------- End by typing a negative number ------------------------------"<<endl;
    cout<<endl;
    
    while(homeworkPoints >= 0 && homeworkNumber <= HOMEWORK_MAX_NUMBER) {
        cout<<"Homework #"<<homeworkNumber<<endl;
        cout<<"Enter your homework points: ";cin>>homeworkPoints;
        if(homeworkPoints < 0) {
            break;
        }
        cout<<"Now enter the max points: ";cin>>homeworkMaxPoints;
        if(homeworkMaxPoints <= 0) {
            break;
        }
        homeworkScore = homeworkPoints / homeworkMaxPoints;
        cout<<"Your score for homework #"<<homeworkNumber<<" is "<<homeworkPoints<<"/"<<homeworkMaxPoints<<" which is "<<homeworkScore * 100<<"%."<<endl;
        homeworkNumber++;
        homeworkTotalScore += (homeworkScore * (1.0 / HOMEWORK_MAX_NUMBER));
    }
    overallHomeworkGrade = homeworkTotalScore * HOMEWORK_WEIGHT;
    cout<<endl;
    cout<<endl;
    
    while(examPoints >= 0 && examNumber <= EXAM_MAX_NUMBER) {
        cout<<"Exam #"<<examNumber<<endl;
        cout<<"Enter your exam points: ";cin>>examPoints;
        if(examPoints < 0) {
            break;
        }
        cout<<"Now enter the max exam points: ";cin>>examMaxPoints;
        if(examMaxPoints <= 0) {
            break;
        }
        examScore = examPoints / examMaxPoints;
        cout<<"Your score for exam #"<<examNumber<<" is "<<examPoints<<"/"<<examMaxPoints<<" which is "<<examScore * 100<<"%."<<endl;
        examNumber++;
        examTotalScore += examScore;
    }
    
    overallExamGrade = examTotalScore * EXAM_WEIGHT;//23% applied to total score.
    finalGrade = overallHomeworkGrade + overallExamGrade;
    cout<<endl;
    cout<<endl;
    
    int withDistinctionQualifier = 0;
    cout<<"What do you think is the miminum grade for a B+? (NOTE:It's usually 87.)"<<endl;
    cin>>withDistinctionQualifier;
    cout<<endl;
    
    if (finalGrade >= A_MINIMUM) {
        letterGrade = "A";
    }
    else if (finalGrade >= A_MINUS_MINIMUM) {
        letterGrade = "A-";
    }
    else if (finalGrade >= B_PLUS_MINIMUM) {
        letterGrade = "B+";
    }
    else if (finalGrade >= B_MINIMUM) {
        letterGrade = "B";
    }
    else if (finalGrade >= B_MINUS_MINIMUM) {
        letterGrade = "B-";
    }
    else if (finalGrade >= C_PLUS_MINIMUM) {
        letterGrade = "C+";
    }
    else if (finalGrade >= C_MINIMUM) {
        letterGrade = "C";
    }
    else if (finalGrade >= C_MINUS_MINIMUM) {
        letterGrade = "C-";
    }
    else if (finalGrade >= F_MINIMUM) {
        letterGrade = "F";
    }
    
    int homeworkLeft;
    homeworkLeft = HOMEWORK_MAX_NUMBER - (homeworkNumber - 1);
    cout<<"Your overall grade is "<<finalGrade<<" which is "<<letterGrade<<" in letter grade."<<endl;
    if(homeworkNumber - 1 < HOMEWORK_MAX_NUMBER) {
        if(homeworkNumber == HOMEWORK_MAX_NUMBER) {
            cout<<"There is only"<<homeworkLeft<<" homework left in the program!"<<endl;
        }
        else {
            cout<<"Take it easy. There are still "<<homeworkLeft<<" homeworks left in the program!"<<endl;
        }
    }
    
    int examRemaining;
    examRemaining = EXAM_MAX_NUMBER - (examNumber - 1);
    if(examNumber - 1 < EXAM_MAX_NUMBER) {
        if(examNumber == EXAM_MAX_NUMBER) {
            cout<<"You only have "<<examRemaining<<" exam remaining!"<<endl;
        }
        else {
            cout<<"Relax. You still have "<<examRemaining<<" exams remaining!"<<endl;
        }
    }
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<endl;
    cout<<endl;
    double scoreGap = withDistinctionQualifier - finalGrade;
    if(finalGrade >= withDistinctionQualifier) {
        cout<<"*****************************************************************************************"<<endl;
        cout<<"  Congratulations!! You have passed the NYU Tandon CS Bridge program with distinction™. "<<endl;
        cout<<"*****************************************************************************************"<<endl;
    }
    else {
        cout<<"*****************************************************************************************"<<endl;
        cout<<"              Follow the steps to get at least a B+ of "<<withDistinctionQualifier<<" with distinction!"<<endl;
        cout<<"*****************************************************************************************"<<endl;
        cout<<endl;
        cout<<"Option 1"<<endl;
        cout<<"You need to have an overall grade of at least "<<scoreGap<<" in order to achieve distinction."<<endl;
        cout<<"You can aim to get an exam grade of "<<scoreGap / examRemaining<<" which is equal to a score of "<<(scoreGap / examRemaining) / (EXAM_WEIGHT / 100.0)<<" in each of the remaining "<<examRemaining<<" exams."<<endl;
        cout<<endl;
        cout<<"Option 2"<<endl;
        cout<<"You can also get the overall grade of at least "<<scoreGap<<" in order to achieve distinction"<<endl;
        cout<<"with an overall homework grade of "<<HOMEWORK_WEIGHT - overallHomeworkGrade<<" which is equal to a grade of "<<(HOMEWORK_WEIGHT - overallHomeworkGrade) / (homeworkLeft)<<" or a score of "<<((HOMEWORK_WEIGHT - overallHomeworkGrade) / homeworkLeft) / (HOMEWORK_WEIGHT / 100.0) * HOMEWORK_MAX_NUMBER<<" in each of the "<<homeworkLeft<<" homeworks left"<<endl;
        cout<<"in addition to an exam grade of "<<(scoreGap - HOMEWORK_WEIGHT) / (examRemaining)<<" which is equal to a score of "<<((scoreGap - HOMEWORK_WEIGHT) / examRemaining) / (EXAM_WEIGHT / 100.0)<<" for each of the "<<examRemaining<<" exams remaining."<<endl;
    }
    return 0;
}

