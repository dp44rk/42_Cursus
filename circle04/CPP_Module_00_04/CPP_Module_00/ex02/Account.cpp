#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

Account::Account( int initial_deposit ) {
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;
    
}
	~Account( void );

void	Account::_displayTimestamp( void ){
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    std::stringstream timestamp;
    timestamp << "[" << std::put_time(now_tm, "%Y%m%d_%H%M%S") << "]";
    std::cout << timestamp.str();
    return ;
}

int	Account::getNbAccounts( void )
{return _nbAccounts;}

int	Account::getTotalAmount( void )
{return _totalAmount;}

int	Account::getNbDeposits( void )
{return _nbDeposits;}

int	Account::getNbWithdrawals( void )
{return _nbWithdrawals;}

void	Account::displayAccountsInfos( void ){
    _displayTimestamp();
}
