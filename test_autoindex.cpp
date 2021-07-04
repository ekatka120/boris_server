#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <list>


std::string		get_cwd_string()
{
    char dir[1024];
    getcwd(dir, 1024);
    //Exception
    std::string cwd(dir);
    return cwd;
}

int main(void)
{
    //function get_path
    std::string current_dir;
    std::string directory;
    std::string path;
    std::list<char *> files;

    current_dir = get_cwd_string();
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

    //check if dir exists (boris's part)
    // 1) get names of all files
    // 2) creating map, writing them there
    // 3) writing as value address of file
    // 4) saving everything in html code as response
}
