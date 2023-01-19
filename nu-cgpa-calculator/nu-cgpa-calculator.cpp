#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class CGPA;

class GPA {
  string grade;
  float credit, total_course, semester_gpa, semester_credit = 0, semester_points = 0;

 public:
  float points(string grade);
  void calculate_gpa(int i);
  friend float final_cgpa(GPA, CGPA&);
};

class CGPA {
  float total_points = 0, total_credit = 0;

 public:
  friend float final_cgpa(GPA, CGPA&);
  void print_cgpa();
};

float GPA::points(string grade) {
  if (grade == "A+" || grade == "a+")
    return 4;
  else if (grade == "A" || grade == "a")
    return 3.75;
  else if (grade == "A-" || grade == "a-")
    return 3.5;
  else if (grade == "B+" || grade == "b+")
    return 3.25;
  else if (grade == "B" || grade == "b")
    return 3.0;
  else if (grade == "B-" || grade == "b-")
    return 2.75;
  else if (grade == "C+" || grade == "c+")
    return 2.5;
  else if (grade == "C" || grade == "c")
    return 2.25;
  else if (grade == "D" || grade == "d")
    return 2.0;
  return 0;
}

void GPA::calculate_gpa(int semester_number) {
  cin >> total_course;
  while (total_course--) {
    cin >> grade >> credit;
    semester_credit += credit;
    semester_points += points(grade) * credit;
  }
  semester_gpa = semester_points / semester_credit;
  cout << fixed << setprecision(2);
  cout << "Semester " << semester_number << ": " << semester_gpa << endl;
}

float final_cgpa(GPA gpa, CGPA& cgpa) {
  cgpa.total_credit += gpa.semester_credit;
  cgpa.total_points += gpa.semester_points;
}

void CGPA::print_cgpa() {
  cout << "CGPA: " << total_points / total_credit << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int total_semester, i, j;
  i = j = 0;
  cin >> total_semester;

  GPA* semester;
  semester = new GPA[total_semester];
  int x, y;
  x = y = total_semester;
  while (x--) {
    semester[i++].calculate_gpa(i);
  }

  CGPA cgpa;
  while (y--) {
    final_cgpa(semester[j++], cgpa);
  }
  cgpa.print_cgpa();

  return 0;
}