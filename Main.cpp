#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/resource.h>

// Function to collect system logs
void collectSystemLogs() {
    system("cp /var/log/syslog /tmp/syslog_copy.log");
    std::cout << "System logs collected and copied to /tmp/syslog_copy.log." << std::endl;
}

// Function to collect memory dump
void collectMemoryDump() {
    pid_t pid = getpid();
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "gcore -o /tmp/memory_dump.%d %d", pid, pid);
    system(buffer);
    std::cout << "Memory dump collected and saved as /tmp/memory_dump." << pid << std::endl;
}

/*/ Function to collect file metadata
void collectFileMetadata(const std::string& filepath) {
    struct stat fileStat;
    if (stat(filepath.c_str(), &fileStat) == 0) {
        std::cout << "File Metadata for " << filepath << ":" << std::endl;
        std::cout << "Size: " << fileStat.st_size << " bytes" << std::endl;
        std::cout << "Owner UID: " << fileStat.st_uid << std::endl;
        std::cout << "Group GID: " << fileStat.st_gid << std::endl;
        std::cout << "Permissions: " << fileStat.st_mode << std::endl;
        std::cout << "Last Access Time: " << ctime(&fileStat.st_atime);
        std::cout << "Last Modification Time: " << ctime(&fileStat.st_mtime);
        std::cout << "Last Status Change Time: " << ctime(&fileStat.st_ctime);
    } else {
        std::cerr << "Error: Unable to collect metadata for " << filepath << std::endl;
    }
}This code took so long to write that even I forgot how it works.*/


int main() {
    std::cout << "Digital Forensic Evidence Collector" << std::endl;

    // Collect system logs
    collectSystemLogs();

    // Collect memory dump
    collectMemoryDump();

    /*// Collect file metadata for a specific file (replace with the file path you want to analyze(not sure if it works as intended))
    std::string filepath = "/path/to/your/file";
    collectFileMetadata(filepath);*/

    return 0;
}
