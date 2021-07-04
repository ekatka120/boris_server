//
// Created by enoelia on 08.06.2021.
//

#include "RequestHandler.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <list>

static	int		sent_len(char const *s, char c)
{
    int			word;
    int			i;

    word = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            word++;
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }
    return (word);
}

static	char	**free_function(char **result, int main_count)
{
    while (main_count > 0)
    {
        free(result[main_count]);
        main_count--;
    }
    free(result);
    return (0);
}

static	char	**fill_word(char const *s, char c, char **result)
{
    int			main_count;
    int			i;
    int			first;

    i = 0;
    main_count = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            first = i;
            while (s[i] != c && s[i])
                i++;
            result[main_count] = (char*)malloc(i - first + 1);
            if (result[main_count] == 0)
                return (free_function(result, main_count));
            strlcpy(result[main_count], &s[first], i - first + 1);
            main_count++;
        }
        else
            i++;
    }
    result[main_count] = 0;
    return (result);
}

char			**ft_split(char const *s, char c)
{
    int		len_sent;
    char	**result;

    if (s == 0)
        return (0);
    len_sent = sent_len(s, c);
    result = (char **)malloc(sizeof(char *) * (len_sent + 1));
    if (result == 0)
        return (0);
    return (fill_word(s, c, result));
}

typedef struct t_time
{
    char    *weekday;
    char    *month;
    char    *day;
    char    *time_no_seconds;
    char    *year;
} t_time;

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
    std::string location;
    std::list<std::string> files;
    std::list<std::string> times;
    std::list<std::string> sizes;

    current_dir = "/Users/dskittri/Desktop/my_boris_server";
    if (current_dir.back() != '/')
        current_dir = current_dir + "/";
    directory = "www/";
    location = current_dir + directory;
    std::cout << "current location: " << location << std::endl;


    DIR *d;
    struct dirent   *dir;
    struct stat     filestat;
    char no_seconds[10];
    char year[10];
    std::string tmp;
    t_time   my_time;
    char **array;
    std::string time;
    std::string name;
    char file_path[1024];


    d = opendir(location.c_str());
    files.clear();
    sizes.clear();
    times.clear();
    if (d)
    {
        dir = readdir(d);
        while ((dir = readdir(d)) != NULL)
        {
            tmp = location + dir->d_name;
            strcpy(file_path, tmp.c_str());
            stat(file_path, &filestat);
            //free(file_path);
            name = dir->d_name;
            if (filestat.st_mode == 16877 & dir->d_name[0] != '.')
                name = name + "/";
            //Спросить у Бориса, как это сделать нормально
            array = ft_split(ctime(&filestat.st_mtime), ' ');
            strcpy(no_seconds, array[3]);
            strcpy(year, array[4]);

            no_seconds[5] = '\0';
            year[4] = '\0';
            my_time.weekday = array[0];
            my_time.month = array[1];
            my_time.day = array[2];
            my_time.time_no_seconds = no_seconds;
            my_time.year = year;

            time = my_time.day;
            if (my_time.day[1] == '\0')
                time = "0" + time;
            time = time + "-";
            time = time + my_time.month;
            time = time + "-";
            time = time + my_time.year;
            time = time + " ";
            time = time + my_time.time_no_seconds;

            if (filestat.st_mode == 16877)
                tmp = "-";
            else
                tmp = std::to_string(filestat.st_size);
            sizes.push_back(tmp);
            times.push_back(time);
            files.push_back(name);
            for (int i = 0; array[i] != NULL;)
                free(array[i++]);
            free(array);
        }
        closedir(d);
        //if closedir() == -1, throw Exception
    }
    //else Exception

    std::string response;
	std::string line;

    response = "";
    response = response + "<html>\n"
                          + "<head><title>Index of " + directory + "</title></head>\n"
                          + "<body bgcolor=\"white\">\n"
                          + "<h1>Index of " + directory + "</h1><hr><pre>";
    std::list<std::string>::iterator it_times = times.begin();
    std::list<std::string>::iterator it_sizes = sizes.begin();
    for (std::list<std::string>::iterator it = files.begin(); it != files.end(); )
	{
		line = "<a href=\"";
		line = line + *it;
		line = line + "\">";
		line = line + *it;
		line = line + "</a>";
        int space = (*it).size();
        for (int space = (*it).size(); space!= 70; space++)
            line = line + " ";
        line = line + *it_times++;
        for (space = 0; space!= 70 - (*it_sizes).size(); space++)
            line = line + " ";
        line = line + *it_sizes++;
        it++;
        line += "\n";
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
