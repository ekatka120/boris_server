#include "Cgi.hpp"

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
    char **argv = new char *[2];
    std::string tmp = "HOHOHOHO";
    argv[0] = new char[100];
    strcpy(argv[0], tmp.c_str());
    //argv[0] = hoho.c_str();
    argv[1] = NULL;
    //print_envp(_env);
    if ((pid = fork()) == 0)
    {
        std::cout << "Child process" << std:: endl;
        int res = execve("/Users/patutina/Desktop/Школа 21/new_boris_server/cgi_tester", argv, _env);
        std::cout << res << std:: endl;
        std::cout << strerror(errno) << std:: endl;
        exit(1);
    }
    waitpid(pid, &stat, 0);
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

    //not clear
    this->_map_envp["PATH_TRANSLATED"] = ""; //??? get_cwd()+path_info
    this->_map_envp["SCRIPT_NAME"] = ""; // stuff before first ?

    //clear
    this->_map_envp["QUERY_STRING"] = ""; // stuff after first ? "q=query-string+http&oq=query-string+http&aqs=chrome..69i57j0i22i30l6j69i60.3737j0j9&sourceid=chrome&ie=UTF-8"
    this->_map_envp["PATH_INFO"] = "/post_body"; // from request header 1 line, 2: GET /background.png HTTP/1.0
    // или дополнительный путь после пути к скрипту, если задан путь c:/cgi-bin/example1.exe/sports.html, то /sports.html в path_info
    this->_map_envp["REQUEST_URI"] = ""; // from request header 1 line, 2: GET /background.png HTTP/1.0 мб, что-то еще?
    this->_map_envp["REQUEST_METHOD"] = "PUT"; // указываем метод from request
    this->_map_envp["CONTENT_LENGTH"] = "10000"; // body length from request
    this->_map_envp["CONTENT_TYPE"] = "text/html"; // from request
    this->_map_envp["SERVER_NAME"] = ""; //from request ex: "HOST : localhost:8000"
    this->_map_envp["SERVER_PORT"] = ""; //from request ex: "HOST : localhost:8000"
    //if do not have authorisation
    this->_map_envp["AUTH_TYPE"] = "Basic"; //type of authorisation; если есть авторизация, указываем ее тип: Authorization: <type> <credentials>
    this->_map_envp["REMOTE_USER"] = ""; //если есть авторизация, указываем декодированного юзера (Base64::decode(credentials))

    // no change
    this->_map_envp["SERVER_PROTOCOL"] = "HTTP/1.1";
    this->_map_envp["SERVER_SOFTWARE"] = "HTTP/1.1";
    this->_map_envp["GATEWAY_INTERFACE"] = "CGI/1.1"; //no change
    this->_map_envp["REMOTE_ADDR"] = "localhost"; //no change???
    this->_map_envp["REMOTE_IDENT"] = ""; //no change
};

void Cgi::cgi_start()
{
    cgi_set_envs();
    std::cout << "cgi_set_envs();" <<std::endl;
    map_envs_to_char_array();
    cgi_usage();
    //cgi_response();
};