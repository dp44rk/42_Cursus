#ifndef _CONTACT_HPP
#define _CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	m_FirstName;
		std::string	m_LastName;
		std::string	m_Nickname;
		std::string	m_PhoneNumber;
		std::string	m_DarkestSecret;
	public:
		Contact( void );
		~Contact( void );
		int getPhoneNumber( void );
		std::string setWidth( std::string str );
		void display();
		void setFirstName( std::string inpt );
		void setLastName( std::string inpt );
		void setNicknName( std::string inpt );
		void setPhoneNumber( std::string inpt );
		void setDarkestSecret( std::string inpt );
};

#endif
