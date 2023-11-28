// Class Person, which has the following attributes: first name, surname and home address. Define necessary constructors as well as the following methods for it:
// search() method, which receives first name and surname as arguments and returns a pointer of type Person in case the given first name or surname matches the first name or surname of the Person object and otherwise it returns NULL.
// Class Profession, which has the following attributes: title, years of experience and latest salary. Define necessary constructors as well as the following methods for it:
// get_latest_salary() method, which receives the profession title as an argument and returns the latest salary or zero in case of no match.
// set_experience() method, which receives the years of experience as an argument and sets the relevant attribute.
// get_experience() method, which returns the years of experience.   vale pointer of type Person in case the given first name or surname matches the first name or surname of the Person object and otherwise it returns NULL.
// Class Employee, which inherits classes Person and Profession and has the following attributes: id, salary and tax_rate as instance variables as well as firm as a static attribute. Define necessary constructors as well as the following functions:
// set_firm() static method, which receives the name of the firm and sets it.
// get_firm() static method, which returns the name of the firm.
// get_net_salary(), which calculates and returns the net salary of the employee.
// print() method, which prints out all the data of the object to the standard output device.


class Person{
private:
    std::string name_last;
    std::string name_first;
    std::string address;

public:
    //methods

};

class Profession{

};

class Employee : public Person, public Profession{

};