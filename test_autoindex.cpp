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

void foo(){}

std::string		get_cwd_string()
{
    char dir[1024];
    getcwd(dir, 1024);
    //Exception
    std::string cwd(dir);
    return cwd;
}

int my(void)
{
    std::string current_dir;
    std::string directory;
    std::string path;
    std::list<char *> files;
    std::list<char *> times;
    std::list<char *> sizes;

    current_dir = get_cwd_string();
    if (current_dir.back() != '/')
        current_dir = current_dir + "/";
    directory = "www/";
    path = current_dir + directory;
    std::cout << "current location: " << path << std::endl;


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


    d = opendir(path.c_str());
    files.clear();
    sizes.clear();
    times.clear();
    if (d)
    {
        dir = readdir(d);
        while ((dir = readdir(d)) != NULL) 
        {
            tmp = path + dir->d_name;
            strcpy(file_path, tmp.c_str());
            //проверка на то, является ли что-то папкой или файлом
            //к папкам добовляем в конец / и убираем у них размер
            stat(file_path, &filestat);
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
            time = time + "-";
            time = time + my_time.month;
            time = time + "-";
            time = time + my_time.year;
            time = time + " ";
            time = time + my_time.time_no_seconds; 

            char time_char[100];
            char size_char[100];
            char name_char[100];
            strcpy(time_char, time.c_str());
            if (filestat.st_mode == 16877)
                tmp = "-";
            else
                tmp = std::to_string(filestat.st_size);
            strcpy(size_char, tmp.c_str());
            strcpy(name_char, name.c_str());
            sizes.push_back(strdup(size_char));
            times.push_back(strdup(time_char));
            files.push_back(strdup(name_char));
            std::cout << "here " << name_char << "\t" << time_char << "\t" << size_char << std::endl;
        }
        closedir(d);
        //if closedir() == -1, throw Exception
    

        std::list<char *>::iterator it_times = times.begin();
        std::list<char *>::iterator it_sizes = sizes.begin();
        for (std::list<char *>::iterator it = files.begin(); it != files.end(); )
        {
            std::cout << "\t" << *it++;
            std::cout << "\t\t" << *it_times++;
            std::cout << "\t\t" << *it_sizes++ << std::endl;
        }
    }
    //     for (std::list<char *>::iterator it = files.begin(); it != files.end(); it++)
    //     {
    //         line = "<a href=\"";
    //         line = line + *it;
    //         line = line + "\">";
    //         line = line + *it;
    //         line = line + "</a>\n";
    //         response = response + line;
    //         std::cout << "Filename\t" << *it << "\n";
    //         stat(*it, &filestat);
            
    //         std::cout << "Birth time\t" << ctime(&filestat.st_birthtime);
    //         std::cout << "User time\t" << ctime(&filestat.st_ctime);
    //     }

    // }
    return(0);
}

int main(void)
{
    my();
    sleep(100);
}