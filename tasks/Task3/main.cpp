#include <nlohmann/json.hpp>

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: Task3 <json_string>\n";
        return 1;
    }

    try {
        nlohmann::json j = nlohmann::json::parse(argv[1]);
        std::cout << "Parsed JSON:\n" << j.dump(2) << "\n\n";

        if (j.contains("name")) {
            std::cout << "Name : " << j["name"].get<std::string>() << "\n";
        }
        if (j.contains("grade")) {
            std::cout << "Grade: " << j["grade"].get<std::string>() << "\n";
        }
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
