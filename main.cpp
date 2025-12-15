#include <iostream>
#include <string>
#include <limits>


class Student{
    private:
    std::string name;
    std::string course;
    int rollNo;
    float marks;
    int age;

    public:
    Student(): name(""),age(0),rollNo(0),course(""),marks(0.0){}
    Student( const std::string& name,int age,const std::string& course,int rollNo,float marks):name(name),age(age),rollNo(rollNo),marks(marks),course(course){}
    

    void setter(const std::string& name,int age,float marks,const std::string &course,int rollNo){
        this->name = name;
        this->marks = marks;
        this->course = course;
        this->rollNo = rollNo;
        this->age = age;
    }
    int getrollNo() const{
        return rollNo;
    }
    void display() const{
        std::cout<<"These are the details of the student:\n";
        std::cout<<"Name: "<<name<<"\n Age: "<<age<<"\n Course: "<<course<<"\n Marks: "<<marks<<"\n Roll no: "<<rollNo;
    }


};


void addStudents(Student students[],int& count){
    int n;
    std::string name,course;
    int age,rollNo;
    float marks;
    std::cout<<"Enter number of students to add: ";
    std::cin>>n;
    for(int i = 0;i<n;i++){
        if (count>=100){
            std::cout<<"Student limit reached";
            return;
        }
    
    std::cout<<"Student "<<count+1<<"\n";
    std::cout<<"Enter student name: ";
    std::cin>>name;
    std::cout<<"Enter age: ";
    std::cin>>age;
    std::cout<<"Enter course: ";
    std::cin>>course;
    std::cout<<"Enter marks: ";
    std::cin>>marks;
    std::cout<<"Enter roll no: ";
    std::cin>>rollNo;

    students[count].setter(name,age,marks,course,rollNo);
    count++;
}
std::cout<<"Student added successfully!\n";
    

}

void deleteStudents(Student students[],int& count){
    int n;
    std::cout<<"Enter student roll no to delete from record: ";
    std::cin>>n;

    for(int i =0;i<count;i++){
        if(students[i].getrollNo()==n){
            for(int j = i;j<count-1;j++){
                students[j]=students[j+1];
            }
            count--;
            std::cout<<"Student deleted from record successfully\n";
            return;

        }
    }


}

void showStudents(Student students[],int count){
    if(count==0){
        std::cout<<"No Students Exist!\n";
        return;
    }

    for(int i = 0;i<count;i++){
        std::cout<<"Student"<<i+1<<"\n";
        students[i].display();
        std::cout<<"\n------------\n";
    }

}

int main(){

   Student students[100];
   int count = 0;
   int choice;

   while(true){
    std::cout<<"-----Student Management System-------\n";
    std::cout<<"1.Show Students\n";
    std::cout<<"2.Add Students\n";
    std::cout<<"3.Delete Students\n";
    std::cout<<"4.Exit\n";
    std::cout<<"Enter your choice: ";
    std::cin>>choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        
    switch(choice){
        case 1: 
           showStudents(students, count);
           break;
        
        case 2:
            addStudents(students,count);
            break;

        case 3:
            deleteStudents(students,count);
            break;

        case 4:
            std::cout<<"Thanks for visiting!";
            return 0;
        
        
        default:
            std::cout<<"Invalid choice\n";
            break;
    }
   }
    
    return 0;
}
