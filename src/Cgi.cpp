#include "Cgi.hpp"
#include <signal.h>

void print_envp(char **envp)
{
    int i = 0;
    std::cout << "print_envp" << std::endl;
    while (envp[i] != NULL)
    {
        std::cout << envp[i] << std::endl;
        i++;
    }
}


void Cgi::cgi_usage()
{
    pid_t pid;
    int stat;
    char **argv = new char *[3];
    std::string tmp1 = "/Users/patutina/Desktop/Школа 21/new_boris_server/cgi_tester";
    std::string tmp2 = "/Users/patutina/Desktop/Школа 21/new_boris_server/new_txt_file";
//    std::string tmp1 = "cgi_tester";
//    std::string tmp2 = "new_txt_file";

    argv[0] = new char[1024];
    argv[1] = new char[1024];
    strcpy(argv[0], tmp1.c_str());
    strcpy(argv[1], tmp2.c_str());
    argv[2] = NULL;
    print_envp(_env);
    print_envp(argv);
    if ((pid = fork()) == 0)
    {
        std::cout << "Child process" << std:: endl;
        int res = execve(argv[0], argv, _env);
        std::cout << res << std:: endl;
        std::cout << strerror(errno) << std:: endl;
        exit(1);
    }
    //waitpid(pid, &stat, 0);
    sleep(3);
    kill(pid, stat);
    std::cout << "\n\nParent process" << std:: endl;
};

void Cgi::map_envs_to_char_array()
{
    std::string tmp;
    int i = 0;

    _env = new char* [_map_envp.size() + 1];
    for(std::map<std::string, std::string>::iterator it = _map_envp.begin(); it != _map_envp.end(); ++it)
    {
        tmp = it->first + "=" + it->second;
        _env[i] = new char[tmp.size() + 1];
        strcpy(_env[i], tmp.c_str());
        i++;
    }
    _env[i] = NULL;
}

void Cgi::cgi_set_envs()
{

    this->_map_envp["AUTH_TYPE"] = "";
    this->_map_envp["CONTENT_LENGTH"] = "0"; // body length from request
    this->_map_envp["CONTENT_TYPE"] = "text/html"; // from request
    this->_map_envp["GATEWAY_INTERFACE"] = "CGI/1.1"; //no change
    this->_map_envp["PATH_INFO"] = "/post_body"; // from request header 1 line, 2: GET /background.png HTTP/1.0
    this->_map_envp["PATH_TRANSLATED"] = "/Users/patutina/Desktop/Школа 21/new_boris_server/post_body"; //??? get_cwd()+path_info
    this->_map_envp["QUERY_STRING"] = ""; // stuff after first ? "q=query-string+http&oq=query-string+http&aqs=chrome..69i57j0i22i30l6j69i60.3737j0j9&sourceid=chrome&ie=UTF-8"
    this->_map_envp["REMOTE_ADDR"] = "localhost"; //no change???
    this->_map_envp["REMOTE_IDENT"] = ""; //no change
    this->_map_envp["REMOTE_USER"] = ""; //если есть авторизация, указываем декодированного юзера (Base64::decode(credentials))
    this->_map_envp["SCRIPT_NAME"] = "/Users/patutina/Desktop/Школа 21/new_boris_server/cgi_tester"; // stuff before first ?
    this->_map_envp["REQUEST_METHOD"] = "POST"; // указываем метод from request
    this->_map_envp["REQUEST_URI"] = "/post_body"; // from request header 1 line, 2: GET /background.png HTTP/1.0 мб, что-то еще?
    this->_map_envp["SERVER_NAME"] = "localhost"; //from request ex: "HOST : localhost:8000"
    this->_map_envp["SERVER_PORT"] = "7554"; //from request ex: "HOST : localhost:8000"
    this->_map_envp["SERVER_PROTOCOL"] = "HTTP/1.1";
    this->_map_envp["SERVER_SOFTWARE"] = "HTTP/1.1";
};

void Cgi::cgi_start()
{
    cgi_set_envs();
    std::cout << "cgi_set_envs();" <<std::endl;
    map_envs_to_char_array();
    cgi_usage();
    //cgi_response();
};