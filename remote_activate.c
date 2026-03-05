#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to run a command and show output
void execute_command(const char *cmd) {
    FILE *pipe = popen(cmd, "r");
    if (!pipe) {
        perror("popen failed");
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }
    pclose(pipe);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip:port> \"command\"\n", argv[0]);
        fprintf(stderr, "Example: %s 192.168.1.100:5555 \"am start -n com.android.settings/.Settings\"\n", argv[0]);
        return 1;
    }

    const char *ip_port = argv[1];
    const char *cmd = argv[2];

    char connect_str[256];
    snprintf(connect_str, sizeof(connect_str), "adb connect %s", ip_port);
    printf("Connecting: %s\n", connect_str);
    execute_command(connect_str);

    char shell_str[512];
    snprintf(shell_str, sizeof(shell_str), "adb shell %s", cmd);
    printf("Running on phone: %s\n", shell_str);
    execute_command(shell_str);

    // Optional: disconnect
    char disconnect_str[256];
    snprintf(disconnect_str, sizeof(disconnect_str), "adb disconnect %s", ip_port);
    printf("Disconnecting...\n");
    execute_command(disconnect_str);

    return 0;
}