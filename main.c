#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)              // Windows: ms
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep((ms) * 1000)    // Linux/macOS
#endif
//inclusive for every OS!!

void typeOut(const char *text, int delay) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        SLEEP(delay);
    }
    putchar('\n');
}

int main() {
    FILE *file;
    char doom[100];

    file = fopen("doom.txt", "r");
    if (file == NULL) {
        typeOut("Error: doom.txt missing. Even worse, we're doomed AND unorganized.", 50);
        return 1;
    }

    while (fgets(doom, sizeof(doom), file)) {
        typeOut(doom, 100);   
    }

    fclose(file);

    getchar();
    typeOut("press any key to accept our fate", 50);
    getchar();

    return 0;
}
