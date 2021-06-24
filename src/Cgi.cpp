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


void Cgi::cgi_usage()
{
    char filename[2][50];
    memset(filename,0,sizeof(char)*100);
    std::string templateFileName("/tmp/file-XXXXXX");
    std::string _client = "Kate, i m very close to be ready!\nxoxo\n";
    strncpy(filename[0], templateFileName.c_str(), templateFileName.size());
    strncpy(filename[1], templateFileName.c_str(), templateFileName.size());
    int     inputFD;
    int    outputFD;
    inputFD = mkstemp(filename[0]);
    write(inputFD, _client.c_str(), _client.size());
    outputFD = mkstemp(filename[1]);
    close(inputFD);
    close(outputFD);

    pid_t pid;
    int stat;
    char **argv = new char *[3];
    std::string tmp1 = "/Users/patutina/Desktop/42/new_boris_server/cgi_tester";
    std::string tmp2 = "/Users/patutina/Desktop/42/new_boris_server/new_txt_file";

    argv[0] = new char[1024];
    argv[1] = new char[1024];
    strcpy(argv[0], tmp1.c_str());
    strcpy(argv[1], tmp2.c_str());
    argv[2] = NULL;
//    print_envp(_env);
//    print_envp(argv);
    if ((pid = fork()) == 0)
    {
        std::cout << "Child process" << std:: endl;
        std::cout << filename[0] << std::endl;
        inputFD = open(filename[0], O_RDONLY, S_IRUSR);
        dup2(inputFD, 0);
        close(inputFD);
        outputFD = open(filename[1], O_WRONLY, S_IWUSR);
        dup2(outputFD, 1);
        close(outputFD);
        int res = execve(argv[0], argv, _env);
        std::cout << res << std:: endl;
        std::cout << strerror(errno) << std:: endl;
        exit(1);
    }
    else{
        //waitpid(pid, &stat, 0);
        sleep(3);
        kill(pid, stat);
        std::cout << "\n\nParent process" << std:: endl;
        waitpid(-1, &stat, 0);
        WIFEXITED(stat);
        int fd;
        fd = open(filename[1], O_RDONLY, S_IRUSR);
        std::vector<char> buffer;
        std::string data;
        int ret = 0;

        buffer.reserve(100000);
        do {
            data.append(&buffer[0], ret);
            ret = read(fd, &buffer[0], 100000);
        } while (ret > 0);
        close(fd);
        std::cout << data;
        unlink(filename[0]);
        unlink(filename[1]);

    }
};

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