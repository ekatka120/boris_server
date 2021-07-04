//
// Created by enoelia on 08.06.2021.
//

#include "RequestHandler.hpp"

std::string		get_cwd_string()
{
    char dir[1024];
    getcwd(dir, 1024);
    //Exception
    std::string cwd(dir);
    return cwd;
}

RequestHandler::RequestHandler(){
	_response = new Response();
}

RequestHandler::RequestHandler(const RequestHandler &other){
	*this = other;
}

RequestHandler::~RequestHandler() {
	delete _response;
}

RequestHandler&	RequestHandler::operator=( const RequestHandler &other){
	if (this != &other) {
		;
	}
	return (*this);
}

int					RequestHandler::getMethod() const {
	return _method;
}

void				RequestHandler::setMethod(int method) {
	_method = method;
}

Server*				RequestHandler::getServer() const {
	return _server;
}

void				RequestHandler::setServer(Server *server) {
	_server = server;
}

const std::string&	RequestHandler::getRawRequest() const {
	return _rawRequest;
}

void				RequestHandler::setRawRequest(const std::string &rawRequest) {
	_rawRequest = rawRequest;
}

const std::string &RequestHandler::getAnswer() const {
	return _answer;
}

unsigned long RequestHandler::getBytesToSend() const {
	return _bytesToSend;
}

int					RequestHandler::checkNewPartOfRequest(char *partOfRequest){
	_rawRequest += partOfRequest;
	if (!parseRequest()){//парсинг запроса на готовность к обработке(наличие \n\r\n\r) + заполнение полей
		return 0;
	} else {
		//POST/DELETE/PUT Execution
		prepareResponse();
		return 1;
	}
}

int					RequestHandler::parseRequest(){
	//<Заглушка>
	_method = GET;
	_url = "/index3.html";
	_headers.insert( std::pair<std::string, std::string>("Content-Length","555"));
	return (1);
	//</Заглушка>
}

void	RequestHandler::autoindex_execution()
{
    std::string current_dir;
    std::string directory;
    std::string path;
    std::list<char *> files;

    current_dir = get_cwd_string();
	current_dir = "/Users/patutina/Desktop/42/my_boris_server/";
    if (current_dir.back() != '/')
        current_dir = current_dir + "/";
    directory = "www/";
    path = current_dir + directory;
    std::cout << path;
    //___________________
    DIR *d;
    struct dirent *dir;
    d = opendir(path.c_str());
    if (d)
    {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            files.push_back(dir->d_name);
        }
        closedir(d);
        //if closedir() == -1, throw Exception
    }
    //else Exception

    std::string response;
	std::string line;

    response = "";
    response = response + "<html>\n"
                          + "<head><title>Index of /</title></head>\n"
                          + "<body bgcolor=\"white\">\n"
                          + "<h1>Index of /test/</h1><hr><pre>";
	for (std::list<char *>::iterator it = files.begin(); it != files.end(); it++)
	{
		line = "<a href=\"";
		line = line + *it;
		line = line + "\">";
		line = line + *it;
		line = line + "</a>\n";
        response = response + line;
	}			  

						//   + "<a href=\"../\">../</a>\n"
                        //   + "<a href=\"test.txt\">test.txt</a>                 19-May-2012 10:43            0\n"

    response = response + "</pre><hr></body>\n"
                          "</html>";
    std::cout << response << std::endl;
	std::stringstream buffer(response);
	_response->setServerAnswer("HTTP/1.1 200 OK\n");
	_response->setUpBody(buffer);
	_response->setUpHeaders();
	//return(&buffer);
}

void				RequestHandler::prepareResponse(){
	urlToPath();
	std::ifstream file(_filePath.c_str());
	std::stringstream buffer;
	bool	_autoindex = true;

	std::cout << _filePath.c_str() << std::endl;
	//std::cout << buffer.str() << std::endl << std::endl;
	buffer << file.rdbuf();
	if (_method == GET && _autoindex == true)
		autoindex_execution();
	else if (!file){
		response404();
	} else {
		//цикл по локейшном для определения соотвсевующего
		// если урл не указывает на файл смотерть в индекс, если нет индекса, искать файл индекс.хтмл если файла нет, смотреть autoindex, если и его нет то ошибка 403
		// елси файла нет, вернуть 404
		// если метод не соответвует доступном ошибку 405 и указать досутпные в заголовке Allow
		if (_method == GET && _autoindex == false) {
			_response->setServerAnswer("HTTP/1.1 200 OK\n");
			_response->setUpBody(buffer);
			_response->setUpHeaders();
		}
	}
	_answer = _response->receiveAnswer();
	_bytesToSend = _answer.length();
}

void				RequestHandler::urlToPath(){
	//<Заглушка>
	_filePath = "/home/enoelia/01_21school/webserv/www" + _url;
	//</Заглушка>
}

void				RequestHandler::response404(){
	std::ifstream file(_server->get404Path().c_str());
	std::stringstream buffer;

	_response->setServerAnswer("HTTP/1.1 404 Not Found\n");
	if (!file) {
		buffer << "<!DOCTYPE html>\n<html><title>404</title><body>Error 404 Not Found</body></html>\n";
		_response->setUpBody(buffer);
		_response->setUpHeaders();
	} else {
		buffer << file.rdbuf();
	}
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
