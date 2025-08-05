# include "../../inc/Server.hpp"

/**
 * @brief This sends messages, either a private message to a user, or a message to a channel. 
 * 		Makes all the necessary checks to ensure the user is allowed to send the message and if it is a channel, that the user is connected to it and has permissions.
 *
 * @param user
 */
void Server::PrivMsgCmd(User &user)
{
	std::string response = "";
	if (user.getMessage().getArgs()[0] == "")
	{
		//ERR_NORECIPIENT
		response = ":" + user.getHostname() + " 411 " + user.getNickname() + " :No recipient given PRIVMSG\r\n";
		send(user.getFd(), response.c_str(), response.length(), 0);
		std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " ) - " << response;
		return ;
	}

	if (user.getMessage().getArgs().size() == 1 && user.getMessage().getMsg().empty())
	{
		//ERR_NOTEXTTOSEND
		response = ":" + user.getHostname() + " 412 " + user.getNickname() + " :No text to send\r\n";
		send(user.getFd(), response.c_str(), response.length(), 0);
		std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " ) - " << response;
		return ;
	}

	response = ":" + user.getNickname() + "!" + user.getUsername() + "@" + user.getHostname() + " PRIVMSG " + user.getMessage().getArgs()[0] + " :" + user.getMessage().getMsg() + "\r\n";


	bool found = false;
	if (user.getMessage().getArgs()[0][0] == '#')
	{
		for (std::map<std::string, Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it)
		{
			if (it->first == user.getMessage().getArgs()[0])
			{
				found = true;
				std::vector<User> chUsers = it->second.getUsers();
				bool connected = false;
				for (std::vector<User>::iterator it2 = chUsers.begin(); it2 != chUsers.end(); ++it2)
				{
					if (it2->getNickname() == user.getNickname())
						connected = true;
				}

				if (!connected)
				{
					//ERR_CANNOTSENDTOCHAN
					response = ":" + user.getHostname() + " 404 " + user.getNickname() + " " + user.getMessage().getArgs()[0] + " :Cannot send to channel\r\n";
					send(user.getFd(), response.c_str(), response.length(), 0);
					std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " ) - " << response;
					return ;
				}

				for (std::vector<User>::iterator ite = chUsers.begin(); ite != chUsers.end(); ++ite)
				{
					if (ite->getFd() != user.getFd())
					{
						send(ite->getFd(), response.c_str(), response.length(), 0);
						std::cout << "[ SERVER ] Message sent to client " << ite->getFd() << " ( " << ite->getHostname() << " ) - " << response;
					}
				}
				return ;
			}
		}

		if (!found)
		{
			//ERR_CANNOTSENDTOCHAN
			response = ":" + user.getHostname() + " 404 " + user.getNickname() + " " + user.getMessage().getArgs()[0] + " :No such channel\r\n";
			send(user.getFd(), response.c_str(), response.length(), 0);
			std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " ) - " << response;
			return ;
		}
	}
	else
	{
		bool found = false;
		for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); ++it)
		{
			if (it->second.getNickname() == user.getMessage().getArgs()[0])
			{
				found = true;
				send(it->second.getFd(), response.c_str(), response.length(), 0);
				std::cout << "[ SERVER ] Message sent to client " << it->second.getFd() << " ( " << it->second.getHostname() << " ) - " << response;
				return ;
			}
		}
		if (!found)
		{
			//ERR_NOSUCHNICK
			response = ":" + user.getHostname() + " 401 " + user.getNickname() + " " + user.getMessage().getArgs()[0] + " :No such nick/channel\r\n";
			send(user.getFd(), response.c_str(), response.length(), 0);
			std::cout << "[ SERVER ] Message sent to client " << user.getFd() << " ( " << user.getHostname() << " ) - " << response;
			return ;
		}
	}

}