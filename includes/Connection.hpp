#ifndef SERVER_CONNECTION_HPP
# define SERVER_CONNECTION_HPP
# define CLOSE 0
# define READ 1
# define WRITE 2
# define BUFFER_SIZE 65536
# include <netinet/in.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <unistd.h>
# include <fstream>
# include <iostream>

# include <streambuf>
# include <sstream>
# include "Exceptions.hpp"
# include "Server.hpp"
# include "Response.hpp"
# include "RequestHandler.hpp"
# include "Cgi.hpp"

class Server;
class RequestHandler;

class Connection {
private:
	int				_status;
	int				_socketFd;
	sockaddr_in		_addr;
	socklen_t		_addrlen;
	RequestHandler	*_requestHandler;
	unsigned long	_alreadySent;

public:
	Connection();
	Connection(int listenSocketFd, Server &server);
	Connection(const Connection &);
	virtual ~Connection();
	Connection		&operator=(const Connection &);

	int				getStatus() const;
	void			setStatus(int status);
	int				getSocketFd() const;
	void			setSocketFd(int fd);

	void			readFromSocket();
	void			writeToSocket();

public:
    void    PostRequestHandler(char *tmp);
private:
    bool		if_file_exists(std::string file_name);
    std::string get_cwd_string();
};


#endif //SERVER_CONNECTION_HPP
