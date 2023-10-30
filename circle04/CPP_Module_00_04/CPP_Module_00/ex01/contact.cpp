#include "contact.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

void Contact::setFirstName( std::string inpt ) { m_FirstName = inpt;}

void Contact::setLastName( std::string inpt ) { m_LastName = inpt; }

void Contact::setNicknName( std::string inpt ) { m_Nickname = inpt; }

void Contact::setPhoneNumber( std::string inpt ) { m_PhoneNumber = inpt; }

void Contact::setDarkestSecret( std::string inpt ) { m_DarkestSecret = inpt; }

int Contact::getPhoneNumber()
{ return (m_PhoneNumber.empty()?0:stoi(m_PhoneNumber)); }

std::string Contact::setWidth( std::string str )
{
    if (str.length() > 10){
        str = str.substr(0, 10);
        str.replace(9, 1, ".");
    }
    return str;
}

void Contact::display()
{
	std::cout<< "|" << std::setw(10) << std::setfill(' ') << setWidth(m_FirstName);
	std::cout<< "|" << std::setw(10) << std::setfill(' ') << setWidth(m_LastName);
	std::cout<< "|" << std::setw(10) << std::setfill(' ') << setWidth(m_Nickname) << "|" << std::endl;

}
