# include <iostream>
# include "Exceptions.hpp"
# include <map>
# include <unistd.h>
//Is it obligatory to implement in this project complien form ?
class Cgi
{
    public:
        void cgi_start();
        void cgi_set_envs();
        void cgi_usage();
        void cgi_usage_2(char **filename);
        void cgi_response();
        void map_envs_to_char_array();
        std::string read_from_file(int fd);
    private:
        std::map<std::string, std::string> _map_envp;
        char **_env;
};