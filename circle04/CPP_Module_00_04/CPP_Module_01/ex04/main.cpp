#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int terminate(std::string str){
    std::cerr << "\033[0;31m" << str << "\033[0m" << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return(terminate("Invalid number of arguments.\nUsage: [filename] [s1] [s2]"));

    std::ifstream ifs(argv[1]); //reading
    if (!ifs)
        return(terminate("Cannot open file"));

    std::ofstream ofs(std::string(argv[1]) + ".replace"); //writing
    if (!ofs)
        return(terminate("Cannot open file"));

    std::string s1 = std::string(argv[2]);
    while(ifs)
    {
        std::string line;
        std::string::size_type n;
        getline(ifs, line);
        n = line.find(s1);
        if(n != std::string::npos)
        {
            line.erase(n, s1.length());
            line.insert(n, argv[3]);
        }
        ofs << line;
        if (!ifs.eof())
            ofs << std::endl;
    }
    ofs.close();
    return 0;
}