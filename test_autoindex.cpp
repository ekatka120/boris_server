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
    std::cout << "PATH " << path << std::endl;
    //___________________
    DIR *d;
    struct dirent *dir;
        struct stat filestat;
    d = opendir(path.c_str());
    t_time my_time;
    char **array;
    if (d)
    {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
            std::cout << "Filename\t" << dir->d_name << "\n";
            stat(dir->d_name, &filestat);
            
            // std::cout << "Birth time\t" << ctime(&filestat.st_birthtime);
            // std::cout << "User time\t" << ctime(&filestat.st_ctime);
            std::cout << "here\n";
            array = ft_split(ctime(&filestat.st_ctime), ' ');
            my_time.weekday = array[0];
            my_time.month = array[1];
            my_time.day = array[2];

            my_time.year = array[4];
            char no_seconds[10];
            strcpy(no_seconds, array[3]);
            no_seconds[5] = '\0';
            my_time.time_no_seconds = no_seconds;
            std::cout << my_time.day << "\t" << my_time.month << "\t" << my_time.time_no_seconds << "\n";
            // strcpy(my_time.weekday, array[0]);
            // std::cout << "here\n";
            // strcpy(my_time.month, array[1]);
            // strcpy(my_time.day, array[2]);
            // strcpy(my_time.time_no_seconds, array[3]);
            // my_time.time_no_seconds[5] = '\0';
            // strcpy(my_time.year, array[4]);
            files.push_back(dir->d_name);
        }
        closedir(d);
        //if closedir() == -1, throw Exception
    }
    //else Exception

    std::string response;
    std::string line;

    // response = "";
    // response = response + "<html>\n"
    //            + "<head><title>Index of /</title></head>\n"
    //            + "<body bgcolor=\"white\">\n"
    //            + "<h1>Index of /test/</h1><hr><pre>";



    // for (std::list<char *>::iterator it = files.begin(); it != files.end(); it++)
    // {
    //     line = "<a href=\"";
    //     line = line + *it;
    //     line = line + "\">";
    //     line = line + *it;
    //     line = line + "</a>\n";
    //     response = response + line;
    //     std::cout << "Filename\t" << *it << "\n";
    //     stat(*it, &filestat);
        
    //     std::cout << "Birth time\t" << ctime(&filestat.st_birthtime);
    //     std::cout << "User time\t" << ctime(&filestat.st_ctime);
    // }

    //   + "<a href=\"../\">../</a>\n"
    //   + "<a href=\"test.txt\">test.txt</a>                 19-May-2012 10:43            0\n"

    response = response + "</pre><hr></body>\n"
                          "</html>";
    //std::cout << response << std::endl;

    //check if dir exists (boris's part)
    // 1) get names of all files
    // 2) creating map, writing them there
    // 3) writing as value address of file
    // 4) saving everything in html code as response
}
