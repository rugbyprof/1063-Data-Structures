/**
 * This program gives an example of a simple Class definition and usage.
 * 
 */

#include <iostream> // write to and read from stdin and stdout
#include <string>   //
#include <fstream>  // read a write files


using namespace std; 


/**
 * class Student
 * 
 * Description:
 *      This represents a student and thier grades. It allows a user to add grades and delete grades. 
 * 
 * Methods:
 *              Student()                               : default constructor
 *              Student(string, string, int , int[])    : constructor allows user to intialize each data member
 * 
 *      void    addGrade(int)                           : add a grade to container (array in this case)
 *      float   avgGrade(void)                          : average the students grades
 * 
 *  I ADDED THESE AFTER CLASS:
 *      void    getFname(string)                        : get students first name
 *      string  getLname(string)                        : get students last name
 * 
 * 
 *      string  setFname(string)                        : set students first name
 *      void    setLname(string)                        : set students last name
 *      int     removeGrade()                           : remove last grade from grade container
 */
class Student
{
// PRIVATE SECTION CANNOT BE ACCESS DIRECTLY
private:
    string fname;
    string lname;
    int numGrades;
    int grades[10];
    int maxGrades;

// PUBLIC SECTION IS HOW WE WANT USERS TO INTERACT WITH OUR DATA 
public:

    /**
     * Constructor: Student
     * 
     * Description:
     *      Default constructor
     * 
     */
    Student(){
        fname = "";
        lname = "";
        numGrades = 0;
        maxGrades = 10;
        for(int i=0;i<10;i++){
            grades[i] = 0;
        }
    }

    /**
     * Constructor: Student
     * 
     * Description:
     *      Overloaded constructor
     * 
     * Params:
     *      string  first       : first name of student
     *      string  last        : last name of student
     *      int     count       : size of new grades array
     *      int     new_grades  : array of grades
     * 
     */
    Student(string first,string last,int count,int new_grades[]){
        fname = first;
        lname = last;
        numGrades = count;
        for(int i=0;i<count;i++){
            grades[i] = new_grades[i];
        }

        for(int i=count;i<maxGrades ;i++){
            grades[i] = 0;
        }
    }

    /**
     * Function: addGrade
     * 
     * Description:
     *      Add new grade to student
     * 
     * Params:
     *      int grade : assignment grade
     * 
     * Returns:
     * 
     *      void
     */
    void addGrade(int grade){
        if(numGrades < maxGrades){
            grades[numGrades++] = grade;
        }else{
            cout<<"Error!! Too many grades!";
        }
    }

    /**
     * Function: avgGrade
     * 
     * Description:
     *      Avg the students grades
     * 
     * Params:
     *      void
     * 
     * Returns:
     * 
     *      float - average of grade array
     */
    float avgGrade(){
        int total = 0;  // variable to hold our total
                        // sum vars need initialized!

        // for loops great with arrays!
        for (int i = 0; i < numGrades; i++)
        {
            // keep our running total
            total = total + grades[i];
        }

        return (float)total / (float)numGrades;

    }

    /**
     * Function: getFname
     * 
     * Description:
     *      Gets the first name
     * 
     * Params:
     *      void
     * 
     * Returns:
     * 
     *      string - first name
     */
    string getFname(){
        return fname;
    }

    /**
     * Function: getLname
     * 
     * Description:
     *      Gets the last name
     * 
     * Params:
     *      void
     * 
     * Returns:
     * 
     *      string - last name
     */
    string getLname(){
        return lname;
    }

    /**
     * Function: setFname
     * 
     * Description:
     *      Sets the first name
     * 
     * Params:
     *      string val : first name
     * 
     * Returns:
     * 
     *      void
     */
    void setFname(string val){
        fname = val;
    }

    /**
     * Function: setLname
     * 
     * Description:
     *      Sets the last name
     * 
     * Params:
     *      string val : last name
     * 
     * Returns:
     * 
     *      void
     */
    void setLname(string val){
        lname = val;
    }

    /**
     * Function: removeGrade
     * 
     * Description:
     *      Removes last grade from container
     * 
     * Params:
     *      void
     * 
     * Returns:
     * 
     *      int - last grade removed
     */
    int removeGrade(){
        int last_grade = grades[--numGrades];
        grades[numGrades] = 0;

        return last_grade;
    }

};


/**
 * Function: main
 * 
 * Description:
 *      Drives this example of structs and arrays
 */
int main()
{

    int grades[] = {88,99,34,88,67};
    Student s("Harriet","Smith",5,grades);  

    cout<<s.getFname()<<" "<<s.getLname()<<" has an average grade of "<<s.avgGrade()<<endl;


    return 0;
} 