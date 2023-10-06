#include <iostream>
#include <cstdio> 
using namespace std;

int calculateSumOfMarks(int math, int eng, int sci);
double calculatePercentage(int totalMarks);

int main(void) {
    int std_1TotalMarks, std_1id, std_1math, std_1eng, std_1sci;
    int std_2TotalMarks, std_2id, std_2math, std_2eng, std_2sci;
    int std_3TotalMarks, std_3id, std_3math, std_3eng, std_3sci;
    double std_1Percentage;
    double std_2Percentage;
    double std_3Percentage;

    // Input marks of student #01
    printf("Enter Student #01:(studentId math eng sci)\n");
    scanf("%d %d %d %d", &std_1id, &std_1math, &std_1eng, &std_1sci);
    std_1TotalMarks = calculateSumOfMarks(std_1math, std_1eng, std_1sci);
    std_1Percentage = calculatePercentage(std_1TotalMarks);

    // Input marks of student #02
    printf("\nEnter Student #02:(studentId math eng sci)\n");
    scanf("%d %d %d %d", &std_2id, &std_2math, &std_2eng, &std_2sci);
    std_2TotalMarks = calculateSumOfMarks(std_2math, std_2eng, std_2sci);
    std_2Percentage = calculatePercentage(std_2TotalMarks);

    // Input marks of student #03w
    printf("\nEnter Student #03:(studentId math eng sci)\n");
    scanf("%d %d %d %d", &std_3id, &std_3math, &std_3eng, &std_3sci);
    std_3TotalMarks = calculateSumOfMarks(std_3math, std_3eng, std_3sci);
    std_3Percentage = calculatePercentage(std_3TotalMarks);

    // Display student #01 Info
    printf("\nStudent #01 Id: %d\nStudent #01 Math: %d\nStudent #01 Eng: %d\nStudent #01 Science: %d\nStudent #01 Total Marks: %d\nStudent #01 Percentage: %.2lf\n\n", std_1id, std_1math, std_1eng, std_1sci, std_1TotalMarks, std_1Percentage);

    // Display student #02 Info
    printf("Student #02 Id: %d\nStudent #02 Math: %d\nStudent #02 Eng: %d\nStudent #02 Science: %d\nStudent #02 Total Marks: %d\nStudent #02 Percentage: %.2lf\n\n", std_2id, std_2math, std_2eng, std_2sci, std_2TotalMarks, std_2Percentage);

    // Display student #03 Info
    printf("Student #03 Id: %d\nStudent #03 Math: %d\nStudent #03 Eng: %d\nStudent #03 Science: %d\nStudent #03 Total Marks: %d\nStudent #03 Percentage: %.2lf\n", std_3id, std_3math, std_3eng, std_3sci, std_3TotalMarks, std_3Percentage);

    return 0;
}

int calculateSumOfMarks(int math, int eng, int sci) {
    return math + eng + sci;
}

double calculatePercentage(int totalMarks) {
    return static_cast<double>(totalMarks) / 300.0 * 100.0;
}
