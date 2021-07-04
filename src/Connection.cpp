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
        return(true);
    }
    else
    {
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
                std::cout << "HTTP/1.1 204 No Content..." << std::endl;//или тут 200?
                file.close();
            }
            else
                std::cout << "HTTP/1.1 403 Forbidden" << std::endl;
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

void        Connection::DeleteRequestHandler(char *buf)
{
    std::string path = "/Users/kata/Desktop/42/";
    std::string filename = "exxx";
    std::string status_message;
    std::string body;
    int         status_code;
    int         res;

    filename = path+filename;
    if (if_file_exists(filename))
    {
        std::ifstream file(filename);

        if (file.good())
        {
            file >> body;
            if ((res = remove(filename.c_str())) == 0) {
                if (body.empty() == true)
                {
                    status_code = 204;
                    status_message = "No content";
                }
                else {
                    status_code = 200;
                    status_message = "Ok";
                }
            } else {
                status_code = 202;
                status_message = "Accepted";
            }
        }
        else
        {
            status_code = 403;
            status_message = "Forbidden";
        }
    }
    else{
        status_code = 404;
        status_message = "Not Found";
    }
    std::cout << "Status code " << status_code << " " << status_message << std::endl;
    if (status_code == 200)
        std::cout << "Body:\n" << body << std::endl;
}
void        Connection::PutRequestHandler(char *buf)
{
    //в реализации PUT почти не отличается от POST
    std::string location_request = "/post_body";

    std::string filename = "/Users/patutina/Desktop/Школа 21/new_boris_server/" + location_request;
    if (if_file_exists(filename) == true)
    {
        std::cout << "PUT" << std::endl;
        std::ofstream file(filename, std::ios::out | std::ios::in | std::ios::trunc);
        if (file.is_open())
        {
            file << "content xxxx";//body
            std::cout << "HTTP/1.1 204 No Content..." << std::endl;//или тут 200?
            file.close();
        }
    }
    else
    {
        std::cout << "PUT, file does not exist" << std::endl;
        std::ofstream file(filename, std::ios::out | std::ios::in | std::ios::trunc);
        if (file.is_open())
        {
            file << "content xxxx";
            std::cout << "HTTP/1.1 201 Created..." << std::endl;
            std::cout << "content xxxx" << std::endl;
            file.close();
        }
        else
            std::cout << "HTTP/1.1 403 Frobidden" << std::endl;
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
	} else {
		close(_socketFd);
		_status = CLOSE;
	}
	std::cout << "read return : " << readValue << " BUFF = " << BUFFER_SIZE << std::endl;
    if (buf[0] == 'P' & buf[1] == 'O' & buf[2] == 'S' & buf[3] == 'T')
    {
        // std::cout << "It's a Post request" << std::endl;
        // PostRequestHandler(buf);
        // std::cout << "It's a Post request" << std::endl;
        // PostRequestHandler(buf);
    }
    else if (buf[0] == 'D' & buf[1] == 'E' & buf[2] == 'L' & buf[3] == 'E')
    {
        std::cout << "It's a Delete request" << std::endl;
        DeleteRequestHandler(buf);
    }
    else if (buf[0] == 'P' & buf[1] == 'U' & buf[2] == 'T')
    {
        std::cout << "It's a Put request" << std::endl;
        PutRequestHandler(buf);
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
