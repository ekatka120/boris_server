#include "Cgi.hpp"
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>

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

std::string Cgi::read_from_file(int fd)
{
    std::vector<char>   buffer;
    std::string         answer_body;
    int ret = 0;

    buffer.reserve(100000);
    while ((ret = read(fd, &buffer[0], 100000)) > 0)
        answer_body.append(&buffer[0], ret);
    close(fd);
    if (ret == -1)
        throw Exceptions::ReadException();
    return(answer_body);
}

void Cgi::cgi_usage_2(char **filename)
{
    int         fd;
    pid_t       pid;
    int         stat = 0;
    int         input;
    int         output;
    char        **argv;
    std::string answer_body;

    argv = new char *[3];
    argv[0] = new char[1024];
    argv[1] = new char[1024];
    argv[2] = NULL;

    std::string tmp1 = "/Users/patutina/Desktop/42/new_boris_server/cgi_tester";
    std::string tmp2 = "/Users/patutina/Desktop/42/new_boris_server/new_txt_file";
    strcpy(argv[0], tmp1.c_str());
    strcpy(argv[1], tmp2.c_str());

    pid = fork();
    if (pid == -1)
        throw Exceptions::ForkException();
    else if (pid == 0)
    {
        input = open(filename[0], O_RDONLY, S_IRUSR);
        output = open(filename[1], O_WRONLY, S_IWUSR);
        dup2(input, 0);
        dup2(output, 1);
        close(output);
        close(input);
        if (execve(argv[0], argv, _env) == -1)
            throw Exceptions::ExecveException();;
        exit(-1);
    }
    else
    {
        waitpid(-1, &stat, 0);
        if ((fd = open(filename[1], O_RDONLY, S_IRUSR)) == -1)
            throw Exceptions::OpenTmpFileException();
        answer_body = read_from_file(fd);
        unlink(filename[0]);
        unlink(filename[1]);
        std::cout << "201 Ok" << std::endl;
        std::cout << answer_body;
    }
};

void Cgi::cgi_usage()
{
    char    *filename[2];
    int     input;
    int     output;

    std::string template_for_file("/tmp/tmp_XXXXXX");
    filename[0] = new char [40];
    filename[1] = new char [40];
    strncpy(filename[0], template_for_file.c_str(), template_for_file.size());
    strncpy(filename[1], template_for_file.c_str(), template_for_file.size());
    input = mkstemp(filename[0]);
    output = mkstemp(filename[1]);
    if (input == -1 || output == -1)
        throw Exceptions::OpenTmpFileException();

    std::string body_from_client = "I Am So Smart! \nI Am So Smart! \nS-M-R-T! \nI Mean S-M-A-R-T!\nxoxo\n";
    if (write(input, body_from_client.c_str(), body_from_client.size()) == -1)
        throw Exceptions::WriteException();

    close(input);
    close(output);
    cgi_usage_2(filename);
    delete filename[0];
    delete filename[1];
}



void Cgi::map_envs_to_char_array()
{
    std::map<std::string, std::string>::iterator it;
    std::string tmp;
    int i = 0;
    
    _env = new char* [_map_envp.size() + 1];
    for(it = _map_envp.begin(); it != _map_envp.end(); ++it)
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

    this->_map_envp["AUTH_TYPE"]            = "";
    this->_map_envp["CONTENT_LENGTH"]       = "0";
    this->_map_envp["CONTENT_TYPE"]         = "text/html";
    this->_map_envp["GATEWAY_INTERFACE"]    = "CGI/1.1";
    this->_map_envp["PATH_INFO"]            = "/post_body";
    this->_map_envp["PATH_TRANSLATED"]      = "/Users/patutina/Desktop/42/new_boris_server/post_body";
    this->_map_envp["QUERY_STRING"]         = "";
    this->_map_envp["REMOTE_ADDR"]          = "localhost";
    this->_map_envp["REMOTE_IDENT"]         = "";
    this->_map_envp["REMOTE_USER"]          = "";
    this->_map_envp["SCRIPT_NAME"]          = "/Users/patutina/Desktop/42/new_boris_server/cgi_tester";
    this->_map_envp["REQUEST_METHOD"]       = "POST";
    this->_map_envp["REQUEST_URI"]          = "/post_body";
    this->_map_envp["SERVER_NAME"]          = "localhost";
    this->_map_envp["SERVER_PORT"]          = "7554";
    this->_map_envp["SERVER_PROTOCOL"]      = "HTTP/1.1";
    this->_map_envp["SERVER_SOFTWARE"]      = "HTTP/1.1";
};

void Cgi::cgi_start()
{
    cgi_set_envs();
    map_envs_to_char_array();
    cgi_usage();
    //cgi_response();
};