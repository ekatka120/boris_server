#include "Connection.hpp"

Connection::Connection(int listenSocketFd, Server &server) :
	_status(READ),
	_addrlen(sizeof(_addr)),
	_requestHandler(new RequestHandler()),
	_alreadySent(0){
	int flags;

	_socketFd = accept(listenSocketFd,(sockaddr*)&_addr, &_addrlen);
	if (_socketFd == -1){
		throw Exceptions::AcceptException();
	}
	std::cout << "SUCCESS CONNECTION FROM IP " <<  inet_ntoa(_addr.sin_addr) << std::endl;//
	std::cout << "CREATE NEW FD = " << _socketFd << std::endl;

	_requestHandler->setServer(&server);
	//nonblocking mode
	if ((flags = fcntl(_socketFd, F_GETFL)) == -1)
		throw Exceptions::FcntlException();
	if ((fcntl(_socketFd, F_SETFL, flags | O_NONBLOCK) == -1))
		throw Exceptions::FcntlException();
}

Connection::Connection(const Connection &other){
	*this = other;
}

Connection::~Connection() {
}

Connection&	Connection::operator=( const Connection &other){
	if (this != &other) {
		_status = other._status;
		_socketFd = other._socketFd;
		_addr = other._addr;
		_addrlen = other._addrlen;
	}
	return (*this);
}

int			Connection::getStatus() const {
	return _status;
}

void		Connection::setStatus(int status) {
	_status = status;
}

int			Connection::getSocketFd() const {
	return _socketFd;
}

void		Connection::setSocketFd(int fd) {
	_socketFd = fd;
}

bool		Connection::if_file_exists(std::string file_name)
{
    struct stat buf;

    std::cout << file_name <<std::endl;
    if (stat(file_name.c_str(), &buf) != -1){
        std::cout << "return(true);" <<std::endl;
        return(true);
    }
    else
    {
        std::cout << "return(false);" <<std::endl;
        return(false);
    }
}

std::string		Connection::get_cwd_string()
{
    char dir[1024];
    getcwd(dir, 1024);
    std::string cwd(dir);
    return cwd;
}

//Точно ли тут нужен root?
void        Connection::PostRequestHandler(char *buf)
{
    //Info from config and request
    bool cgi_path = true;
    std::string root_config = "";
    std::string location_request = "/post_body";

    //Main part
    //std::string filename = get_cwd_string() + root_config + location_request;
    //Это раюочая. Но сервер надо запускать через терминал, иначе в пути текущей дериктории будет папка CMake
    std::string filename = "/Users/patutina/Desktop/Школа 21/new_boris_server/" + location_request;

    if (cgi_path == false)
    {
        if (if_file_exists(filename) == true)
        {
            std::cout << "Post, NO CGI, file exists" << std::endl;
            std::ofstream file(filename, std::ios::out | std::ios::in | std::ios::trunc);
            if (file.is_open())
            {
                file << "content xxxx";//body
                std::cout << "HTTP/1.1 204 No Content..." << std::endl;
                file.close();
            }
        }
        else
        {
            std::cout << "Post, NO CGI, file does not exist" << std::endl;
            std::ofstream file(filename, std::ios::out | std::ios::in | std::ios::trunc);
            if (file.is_open())
            {
                file << "content xxxx";
                std::cout << "HTTP/1.1 201 Created..." << std::endl;
                std::cout << "content xxxx" << std::endl;
                file.close();
            }
        }
    }
    else
    {
        std::cout << "Post, CGI" << std::endl;
        Cgi cgi_obj;
        cgi_obj.cgi_start();
    }
}


void		Connection::readFromSocket() {
	int readValue;
	char buf[BUFFER_SIZE];

	if ((readValue = read(_socketFd, buf, BUFFER_SIZE + 1)) == -1) {
		throw Exceptions::ReadException();
	}
	if (readValue > 0){
		if (_requestHandler->checkNewPartOfRequest(buf)){
			_status = WRITE;
		}
		//std::cout << _requestHandler->getRawRequest() << std::endl;//
	} else {
		close(_socketFd);
		_status = CLOSE;
	}
	std::cout << "read return : " << readValue << " BUFF = " << BUFFER_SIZE << std::endl;
    if (buf[0] == 'P' & buf[1] == 'O' & buf[2] == 'S' & buf[3] == 'T')
    {
        std::cout << "It's a Post request" << std::endl;
        PostRequestHandler(buf);
    }
}

void		Connection::writeToSocket(){
	std::string tmp;

	tmp = _requestHandler->getAnswer();
	_alreadySent += write(_socketFd, tmp.c_str() + _alreadySent, tmp.length() - _alreadySent);
	std::cout << tmp << std::endl;
	std::cout << _alreadySent << "//" << tmp.length() << std::endl;

	if (_alreadySent == _requestHandler->getBytesToSend()){
		close(_socketFd);
		_status = CLOSE;
	}
	   // stream used for the conversion
//	std::ifstream t("/home/enoelia/01_21school/webserv/www/index.html");
//	std::string str((std::istreambuf_iterator<char>(t)),
//					std::istreambuf_iterator<char>());
//	std::ostringstream convert;
//
//	std::string res = "";
//	res += "HTTP/1.1 200 OK\nContent-Length: ";
//	res += std::to_string(str.length());
//	res += "\r\n\r\n";
//	res += str;
//	//res += "<!DOCTYPE html>\n<html><title>40404</title><body>There was an error finding your error page</body></html>\n";
//	res +=  "\r\n\r\n";
//	std::cout << res << std::endl;
//	writeValue = write(_socketFd, res.c_str(), res.length());
//	std::cout << "write return : " <<writeValue << std::endl;
//	_status = CLOSE;
}