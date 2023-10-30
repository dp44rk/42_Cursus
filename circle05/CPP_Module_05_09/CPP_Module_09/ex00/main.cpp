#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 1 || ac != 2) {
        ac == 1 ? std::cerr << "Error: could not open file." << std::endl :
                  std::cerr << "Error: Invalid arguments." << std::endl;
        return 1;
    }

    const std::string CSV_FILE_PATH = "./data.csv";
    const std::string inputFilePath(av[1]);

    try {
        BitcoinExchange datas(CSV_FILE_PATH);
        datas.convertToRecord(inputFilePath);
    }
    catch (const char *err) {
        std::cout << err << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}