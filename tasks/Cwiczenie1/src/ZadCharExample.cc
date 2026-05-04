#include <iostream>
#include <cstring>
#include <cctype>
#include "ZadCharExample.h"

using namespace std;

int ZadCharExample::main() {
    cout << "=== <cstring> functions ===" << endl;

    // --- strlen ---
    const char* s1 = "Hello, World!";
    cout << "\n[strlen]" << endl;
    cout << "  strlen(\"" << s1 << "\") = " << strlen(s1) << endl;

    // --- strcpy / strncpy ---
    cout << "\n[strcpy / strncpy]" << endl;
    char buf[64];
    strcpy(buf, s1);
    cout << "  strcpy  -> buf = \"" << buf << "\"" << endl;

    char buf2[8];
    strncpy(buf2, s1, 5);
    buf2[5] = '\0';
    cout << "  strncpy(5) -> buf2 = \"" << buf2 << "\"" << endl;

    // --- strcat / strncat ---
    cout << "\n[strcat / strncat]" << endl;
    char cat[64] = "Foo";
    strcat(cat, "Bar");
    cout << "  strcat  -> \"" << cat << "\"" << endl;
    strncat(cat, "BazQux", 3);
    cout << "  strncat(3) -> \"" << cat << "\"" << endl;

    // --- strcmp / strncmp ---
    cout << "\n[strcmp / strncmp]" << endl;
    const char* a = "apple";
    const char* b = "banana";
    int cmp = strcmp(a, b);
    cout << "  strcmp(\"apple\", \"banana\") = " << cmp
         << (cmp < 0 ? "  (<0: apple before banana)" : "  (>=0)") << endl;
    cout << "  strncmp(\"apple\", \"apricot\", 2) = "
         << strncmp("apple", "apricot", 2)
         << "  (pierwsze 2 znaki takie same)" << endl;

    // --- strchr / strrchr ---
    cout << "\n[strchr / strrchr]" << endl;
    const char* text = "programming";
    const char* found = strchr(text, 'm');
    if (found)
        cout << "  strchr('m') znaleziono na indeksie " << (found - text) << endl;
    const char* rfound = strrchr(text, 'm');
    if (rfound)
        cout << "  strrchr('m') ostatnie wystapienie na indeksie " << (rfound - text) << endl;

    // --- strstr ---
    cout << "\n[strstr]" << endl;
    const char* haystack = "The quick brown fox";
    const char* needle = "brown";
    const char* pos = strstr(haystack, needle);
    if (pos)
        cout << "  strstr(\"brown\") znaleziono na indeksie " << (pos - haystack) << endl;

    // --- memset / memcpy ---
    cout << "\n[memset / memcpy]" << endl;
    char mem[8];
    memset(mem, '-', 7);
    mem[7] = '\0';
    cout << "  memset('-', 7) -> \"" << mem << "\"" << endl;

    char src[6] = "hello";
    char dst[6];
    memcpy(dst, src, sizeof(src));
    cout << "  memcpy -> dst = \"" << dst << "\"" << endl;

    // --- <cctype> character classification ---
    cout << "\n=== <cctype> functions ===" << endl;
    const char* sample = "Hello42!";
    for (int i = 0; sample[i]; ++i) {
        unsigned char c = static_cast<unsigned char>(sample[i]);
        cout << "  '" << (char)c << "'"
             << "  alpha="  << (isalpha(c) ? 1 : 0)
             << "  digit="  << (isdigit(c) ? 1 : 0)
             << "  space="  << (isspace(c) ? 1 : 0)
             << "  upper="  << (isupper(c) ? 1 : 0)
             << "  lower="  << (islower(c) ? 1 : 0)
             << "  punct="  << (ispunct(c) ? 1 : 0)
             << "  upper->'" << (char)toupper(c) << "'"
             << "  lower->'" << (char)tolower(c) << "'" << endl;
    }

    return 0;
}
