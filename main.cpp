#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory> 

class Student 
{
    protected:
      std::string first_name;
      std::string last_name;
      double gpa;
      int graduation_year;
      std::string graduation_semester;
      int enrolled_year;
      std::string enrolled_semester;
      std::string undergrad_or_grad;

    public:
      Student()
        : first_name("Unknown"), last_name("Unknown"), gpa(0.0), graduation_year(0),
          graduation_semester("Unknown"), enrolled_year(0), enrolled_semester("Unknown"),
          undergrad_or_grad("Undergraduate") {}

   
    virtual ~Student() {}

    
    void setName(const std::string& first, const std::string& last) 
    {
        first_name = first;
        last_name = last;
    }

    void setGPA(double g) { gpa = g; }
    void setGraduationYear(int year) { graduation_year = year; }
    void setGraduationSemester(const std::string& semester) { graduation_semester = semester; }
    void setEnrolledYear(int year) { enrolled_year = year; }
    void setEnrolledSemester(const std::string& semester) { enrolled_semester = semester; }
    void setUndergradOrGrad(const std::string& status) { undergrad_or_grad = status; }
         std::string getFullName() const { return first_name + " " + last_name; }
    
    double getGPA() const { return gpa; }
 
    int getGraduationYear() const { return graduation_year; }
         std::string getGraduationSemester() const { return graduation_semester; }
    
    int getEnrolledYear() const { return enrolled_year; }
         std::string getEnrolledSemester() const { return enrolled_semester; }
    	 std::string getUndergradOrGrad() const { return undergrad_or_grad; }

    
    virtual void printStudentInfo(std::ofstream& outFile) const 
    {
        outFile << "Name: " << getFullName() << "\n";
        outFile << "GPA: " << gpa << "\n";
        outFile << "Graduation Year: " << graduation_year << "\n";
        outFile << "Graduation Semester: " << graduation_semester << "\n";
        outFile << "Enrolled Year: " << enrolled_year << "\n";
        outFile << "Enrolled Semester: " << enrolled_semester << "\n";
        outFile << "Undergraduate or Graduate: " << undergrad_or_grad << "\n";
    }
};


class Art_Student : public Student 
{
    private:
      std::string art_emphasis;

    public:   
      Art_Student() : art_emphasis("Art Studio") {}

   
    void setArtEmphasis(const std::string& emphasis) { art_emphasis = emphasis; }
    	 std::string getArtEmphasis() const { return art_emphasis; }

    
    void printStudentInfo(std::ofstream& outFile) const override 
    {
        Student::printStudentInfo(outFile); 
        outFile << "Art Emphasis: " << art_emphasis << "\n";
    }
};


class Physics_Student : public Student 
{
    private:
      std::string concentration;

    public:   
      Physics_Student() : concentration("Biophysics") {}

   
    void setConcentration(const std::string& conc) { concentration = conc; }
	 std::string getConcentration() const { return concentration; }

   
    void printStudentInfo(std::ofstream& outFile) const override 
    {
        Student::printStudentInfo(outFile);
        outFile << "Concentration: " << concentration << "\n";
    }
};


int main() 
{
    std::vector<std::unique_ptr<Art_Student>> art_students;
    std::vector<std::unique_ptr<Physics_Student>> physics_students;

   
    std::unique_ptr<Art_Student> art1(new Art_Student());
      art1->setName("Alice", "Walker");
      art1->setGPA(3.8);
      art1->setGraduationYear(2025);
      art1->setGraduationSemester("Spring");
      art1->setEnrolledYear(2021);
      art1->setEnrolledSemester("Fall");
      art1->setUndergradOrGrad("Undergraduate");
      art1->setArtEmphasis("Art History");

  
    art_students.push_back(std::move(art1));

    
    std::unique_ptr<Art_Student> art2(new Art_Student());
      art2->setName("Bob", "Johnson");
      art2->setGPA(3.6);
      art2->setGraduationYear(2024);
      art2->setGraduationSemester("Fall");
      art2->setEnrolledYear(2020);
      art2->setEnrolledSemester("Spring");
      art2->setUndergradOrGrad("Undergraduate");
      art2->setArtEmphasis("Art Studio");

   
    art_students.push_back(std::move(art2));

    
    std::unique_ptr<Physics_Student> phys1(new Physics_Student());
      phys1->setName("Charlie", "Davis");
      phys1->setGPA(3.9);
      phys1->setGraduationYear(2026);
      phys1->setGraduationSemester("Spring");
      phys1->setEnrolledYear(2022);
      phys1->setEnrolledSemester("Fall");
      phys1->setUndergradOrGrad("Undergraduate");
      phys1->setConcentration("Earth and Planetary Sciences");

    
    physics_students.push_back(std::move(phys1));

   
    std::unique_ptr<Physics_Student> phys2(new Physics_Student());
      phys2->setName("Diana", "Martinez");
      phys2->setGPA(3.7);
      phys2->setGraduationYear(2025);
      phys2->setGraduationSemester("Fall");
      phys2->setEnrolledYear(2021);
      phys2->setEnrolledSemester("Spring");
      phys2->setUndergradOrGrad("Undergraduate");
      phys2->setConcentration("Biophysics");

   
    physics_students.push_back(std::move(phys2));

    
    std::ofstream outFile("student_info.dat");

   
    for (const auto& student : art_students) 
    {
        student->printStudentInfo(outFile);
        outFile << "\n";
    }

    
    for (const auto& student : physics_students) 
    {
        student->printStudentInfo(outFile);
        outFile << "\n";
    }

    
    outFile.close();

    return 0;
}

