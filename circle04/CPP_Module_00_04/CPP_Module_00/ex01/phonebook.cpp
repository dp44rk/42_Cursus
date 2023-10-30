#include "phonebook.hpp"

std::string get_line()
{
	std::string rtn;
	while (!std::cin.eof())
	{
		getline(std::cin, rtn);
		if (std::cin.eof())
			break;
		if (rtn == "")
			std::cout << "\033[1;32mInvalid input format, try again\033[0m" << std::endl;
		else
		{
			std::cin.clear();
			std::clearerr(stdin);
			return rtn;
		}
	}
	exit(0);
}

void Phonebook::add(const int idx)
{
	std::string cmd[5] = {"\033[0;32mfirst name: \033[0m", \
		"\033[0;32mlast name: \033[0m", "\033[0;32mnickname: \033[0m", \
		"\033[0;32mphonenumber: \033[0m", "\033[0;32mDarkestSecret: \033[0m"};

	std::cout << "\033[1;32mAdd a contact to my phonebook ...\033[0m" << std::endl;
	std::cout << cmd[0] << std::endl;
	contacts[idx].setFirstName(get_line());
	std::cout << cmd[1] << std::endl;
	contacts[idx].setLastName(get_line());
	std::cout << cmd[2] << std::endl;
	contacts[idx].setNicknName(get_line());
	std::cout << cmd[3] << std::endl;
	std::string phonenum_inpt = get_line();
	while (phonenum_inpt.find_first_not_of("0123456789") != std::string::npos) //digit이 아닐경우, npos는 -1 rtn
	{
		std::cout << "\033[1;32mInvalid input format, try again\033[0m" << std::endl;
		phonenum_inpt = get_line();
	}
	contacts[idx].setPhoneNumber(phonenum_inpt);
	std::cout << cmd[4] << std::endl;
	contacts[idx].setDarkestSecret(get_line());
	std::cout << "\033[1;32mAdded successfully!\033[0m" << std::endl;
}

void Phonebook::displayall(void)
{
	std::cout << "|  Index   |First Name|Last Name | Nickname |" << std::endl;
	std::cout << std::setw(46) << std::setfill('-') << '\0' << std::endl;
	for(int i = 0; i < 8 && contacts[i].getPhoneNumber(); i++)
	{
		std::cout<< "|" << std::setw(10) << std::setfill(' ') << std::to_string(i);
		contacts[i].display();
	}
}

void	Phonebook::search(const int i)
{
	if (!contacts[0].getPhoneNumber())
	{
		std::cout << "\033[0;32mContact does not exist\033[0m" << std::endl;
		return ;
	}
	displayall();
	std::cout << "\033[0;32mPlease enter a valid index number.\033[0m" << std::endl;
	int idx;
	while(1)
	{
		try
		{
			idx = std::stoi(get_line());
			throw idx;
		}
		catch(std::invalid_argument const& ex)
		{
			std::cout << "\033[0;31mError: invalid_argument\033[0m" << std::endl;
		}
		catch(std::out_of_range const& ex)
		{
			std::cout << "\033[0;31mError: out_of_range \033[0m" << std::endl;
		}
		catch (int idx)
		{
			if (idx > 7 || !contacts[idx].getPhoneNumber())
				std::cout << "\033[0;31mError: Wrong index number\033[0m" << std::endl;
			else
				break;
		}
	}
	std::cout << "\033[0;32mphone number: \033[0m" << contacts[idx].getPhoneNumber() << std::endl;
}


int main()
{
	Phonebook phonebook;
	std::string cmd;
	int idx = 0;

	while (cmd != "EXIT")
	{
		cmd = get_line();
		if (cmd == "ADD")
		{
			phonebook.add(idx);
			idx++;
			if (idx == 8)
				idx = 0;
		}
		else if(cmd == "SEARCH")
		{
			phonebook.search(idx);
		}
		else if(cmd != "EXIT")
		{
			std::cout << "\033[1;32mInvalid input format, try again\033[0m" << std::endl;
		}
	}
	std::cout << "bye" << std::endl;
	return 0;
}