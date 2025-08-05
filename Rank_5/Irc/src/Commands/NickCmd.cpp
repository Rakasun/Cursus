#include "../../inc/Server.hpp"

/**
 * @brief This handles the user giving themselves a nickname and checks if the nickname is already in use for authentication purposes.
 * 
 * @param user 
 */
void Server::NickCmd(User &user)
{
	std::string response = "";

	if (user.getMessage().getArgs().size() != 1 || user.getMessage().getArgs()[0] == "NICK")
		//ERR_NONICKNAMEGIVEN
		response = ":" + user.getHostname() + " 431 " + user.getNickname() + " :No nickname given\r\n";

	if (response.empty())
		for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); ++it)
			if (it->second.getNickname() == user.getMessage().getArgs()[0])
				//ERR_NICKNAMEINUSE
				response = ":" + user.getHostname() + " 433 " + user.getNickname() + " " + user.getMessage().getArgs()[0] + " :Nickname is already in use\r\n";
	if (response.empty())
	{
		user.setNickname(user.getMessage().getArgs()[0]);
		response = ":" + user.getNickname() + "!@" + user.getHostname() + " NICK :" + user.getNickname() + "\r\n";
	}
	send(user.getFd(), response.c_str(), response.size(), 0);
	std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " )" << response;
}